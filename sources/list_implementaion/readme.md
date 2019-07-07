## List Template Container


Outline of datails:

1. The List class itself, which contains links to both ends, the size of the list, and a host
of methods.

2. The Node class, which is likely to be a private nested class. A node contains the data
and pointers to the previous and next nodes, along with appropriate constructors.

3. The const_iterator class, which abstracts the notion of a position, and is a pub-
lic nested class. The const_iterator stores a pointer to “current” node, and provides
implementation of the basic iterator operations, all in the form of overloaded operators
such as = , == , != , and ++ .

4. The iterator class, which abstracts the notion of a position, and is a public nested
class. The iterator has the same functionality as const_iterator , except that operator*
returns a reference to the item being viewed, rather than a constant reference to
the item. An important technical issue is that an iterator can be used in any rou-
tine that requires a const_iterator , but not vice versa. In other words, iterator IS-A
const_iterator .
