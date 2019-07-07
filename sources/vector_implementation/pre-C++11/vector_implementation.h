#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <iostream>

template <class Object>
class Vector
{	
	/* implement big five default ctor, copy ctor, copy assignment operator, destructor*/
	public:
		/* default ctor */
		Vector( int initSize = 0 ) : theSize( initSize ), 
			theCapacity( initSize + SPARE_CAPACITY )
		{ objects = new Object[ theCapacity ]; }
		
		/* copy ctor */
		Vector( const Vector & rhs ) : theSize( rhs.theSize ), theCapacity( rhs.theCapacity )
		{
			objects = new Object[ theCapacity ];	
			for( int i = 0; i < theSize; ++i )
				objects[ i ] = rhs.object[ i ];
		}

		/* copy assignment operator */
		Vector & operator= ( const Vector & rhs )
		{
			Vector copy = rhs;
			std::swap( *this, rhs);
			return *this;
		}

		/* dtor */
		~Vector()
		{
			delete [] objects;
		}

	public:

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
			for( int k = 0; k < theSize; ++k)
				newArray[ k ] = objects[ k ];
			
			delete [] objects;
			objects = newArray;	
		}

		Object & operator[] ( int index )
		{ return objects[ index ]; }
			

		const Object & operator[]( int index ) const
		{ return objects[ index ]; }

		bool empty() const
		{ return size() == 0; }

		int size() const
		{ return theSize; }

		int capacity() const
		{ return theCapacity; }

		void push_back( const Object & x )
		{
			if( theSize == theCapacity )
				reserve( 2 * theCapacity + 1 );
			objects[ theSize++ ] = x;	
		}

		void pop_back()
		{ --theSize; }

		const Object & back ( ) const
		{ return objects[ theSize - 1 ]; }


		typedef Object * iterator;
		typedef const Object * const_iterator;

		iterator begin( )
		{ return &objects[ 0 ]; }

		const iterator begin( ) const
		{ return &objects[ 0 ]; }

		iterator end( ) 
		{ return &objects[ size( ) ]; }

		const iterator end( ) const
		{ return &objects[ size( ) ]; }
		
		static const int SPARE_CAPACITY = 16;
	private:
		int theSize;
		int theCapacity;
		Object *objects;
};

#endif
