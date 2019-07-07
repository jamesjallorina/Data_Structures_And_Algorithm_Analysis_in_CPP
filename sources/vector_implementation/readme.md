## Vector Template Container


Outline of datails:

1. The Vector will maintain the primitive array (via a pointer variable to the block of
allocated memory), the array capacity, and the current number of items stored in the
Vector.

2. The Vector will implement the Big-Five to provide deep-copy semantics for the copy
constructor and operator= , and will provide a destructor to reclaim the primitive array.
It will also implement C++11 move semantics.

3. The Vector will provide a resize routine that will change (generally to a larger number)
the size of the Vector and a reserve routine that will change (generally to a larger
number) the capacity of the Vector . The capacity is changed by obtaining a new block
of memory for the primitive array, copying the old block into the new block, and
reclaiming the old block.

4. The Vector will provide an implementation of operator[] (as mentioned in
Section 1.7.2, operator[] is typically implemented with both an accessor and mutator
version).

5. The Vector will provide basic routines, such as size , empty , clear (which are typically
one-liners), back , pop_back , and push_back . The push_back routine will call reserve if the
size and capacity are same.

6. The Vector will provide support for the nested types iterator and const_iterator , and
associated begin and end methods.
