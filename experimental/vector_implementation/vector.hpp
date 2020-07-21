#ifndef EXPERIMENTAL_VECTOR_IMPLEMENTATION_VECTOR_HPP
#define EXPERIMENTAL_VECTOR_IMPLEMENTATION_VECTOR_HPP

#include <algorithm>
#include <memory>
#include <utility>

namespace experimental {

	namespace vector_implementation
	{
		template <class Object, class Alloc = std::allocator<Object>>
		class vector
		{
			private:
				using Traits = std::allocator_traits<Alloc>;
				using Ptr = typename Traits::pointer;

				void clear() noexcept
				{
					if(thePtr){
						Object *raw_ptr = static_cast<Object *>(thePtr);
						Traits::destroy(theAllocator, raw_ptr);
						Traits::deallocate(theAllocator, thePtr, theSize);
						thePtr = nullptr;
					}
				}

				template <class... Args>
				void emplace(Args&&... args)
				{
					clear();
					thePtr = Traits::allocate(theAllocator, theSize);
					try{
						Object *raw_ptr = static_cast<Object *>(thePtr);
						Traits::construct(theAllocator, raw_ptr, std::forward<Args>(args)...);
					}catch(...){
						Traits::deallocate(theAllocator, thePtr, theSize);
						throw;
					}
				}

			public:
				using allocator_type = Alloc;

				explicit vector ( int initSize = 0, Alloc a = {} ) : theSize{ initSize }, 
					theCapacity{ initSize + SPARE_CAPACITY }, theAllocator{ a } 
				{ this->emplace(); }

				vector( const vector & rhs, Alloc a = {} ) : theSize{ rhs.theSize }, 
					theCapacity{ rhs.theCapacity }, theAllocator{ a }
				{
					this->emplace(rhs);
				}

				vector & operator= ( const vector & rhs )
				{
					vector copy = rhs;
					std::swap( *this, copy );
					return *this;
				}

				~vector() noexcept { clear(); }

				vector( vector && rhs ) noexcept : theSize{ rhs.theSize }, 
					theCapacity{ rhs.theCapacity }, theAllocator{ rhs.theAllocator }
				{
					thePtr = std::exchange(rhs.thePtr, nullptr);
					rhs.theSize = 0;
					rhs.theCapacity = 0;
				}

				vector &operator= ( vector && rhs ) noexcept
				{
					std::swap( theSize, rhs.theSize );
					std::swap( theCapacity, rhs.theCapacity);
					std::swap( thePtr, rhs.thePtr );

					return *this;
				}

				void resize( int newSize )
				{
					if( newSize > theCapacity )
						reserve( newSize * 2 );
					theSize = newSize;
				}

				void reserve( int newCapacity )	
				{
					if( newCapacity < theSize )
						return;

					Object *newArray = new Object[ newCapacity ];
					for(int k = 0; k < theSize; ++k)
						newArray[ k ] = std::move( thePtr[ k ] );

					theCapacity = newCapacity;
					std::swap( thePtr, newArray );
					delete [] newArray;
				}

				Object &operator[] ( int index )
				{ return thePtr[ index ]; }

				const Object & operator[] ( int index ) const
				{ return thePtr[ index ]; }

				bool empty( ) const 
				{ return size() == 0; }

				int size( ) const
				{ return theSize; }

				int capacity( ) const 
				{ return theCapacity; }

				void push_back( const Object & x )
				{
					if( theSize == theCapacity )
						reserve( 2 * theCapacity + 1 );
					thePtr[ theSize++ ] = x;
				}

				void push_back( Object && x )
				{
					if( theSize == theCapacity )
						reserve( 2 * theCapacity + 1);
					thePtr[ theSize++ ] = std::move( x );
				}

				void pop_back( )
				{
					--theSize;
				}

				const Object & back ( ) const
				{
					return thePtr[ theSize - 1 ];
				}

				using iterator = Object *;
				using const_iterator = const Object *;

				iterator begin( )
				{ return &thePtr[ 0 ]; }
				
				const_iterator begin( ) const
				{ return &thePtr[ 0 ]; }
					
				iterator end( )
				{ return &thePtr[ size() ]; } 

				const_iterator end( ) const
				{ return &thePtr[ size() ]; }

				static constexpr short SPARE_CAPACITY = 16;

			private:
				int theSize;
				int theCapacity;
				Ptr * thePtr;
				Alloc theAllocator;
		};
	} // namespace vector_implementation
} // namespace experimental

#endif //EXPERIMENTAL_VECTOR_IMPLEMENTATION_VECTOR_HPP
