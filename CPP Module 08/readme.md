# Container

A container is a data structure that stores a collection of elements. 
The C++ Standard Library provides several container types, such as std::vector, std::list, std::map, and std::set.
Each container type has its own set of member functions and iterators.

## Sequence containers 
Sequence containers store elements in a linear order. The order of elements is maintained.
### 1. std::vector
When you need random access and dynamic resizing with easy insertion at the end.

**Structure:** 
- Dynamic array.

**Access to Members:** 
- Random access: ``v[i]``, ``v.at(i)`` (O(1)).
- ``v.front()``, ``v.back()`` for first/last element.

**Insertion:**  
- End: ``v.push_back(val)`` (Amortized O(1)).
- Middle: ``v.insert(pos, val)`` (O(n), requires shifting).

**Deletion:**
- End: ``v.pop_back()`` (O(1)).
- Middle: ``v.erase(pos)`` (O(n), requires shifting). 

**O(1): The runtime is constant regardless of the input size.
**O(n): For every additional element in the input, the runtime increases proportionally.

### 2. std::deque
When you need fast insertion/deletion at **both ends** (same as the vector but better if u need to insert in the beigining)

**Structure:** 
- Double-ended queue.

**Access to Members:**
- Random access: ``d[i]``, ``d.at(i)`` (O(1)).
- ``d.front()``, ``d.back()`` for first/last element.

**Insertion:**
- Front: ``d.push_front(val)`` (O(1)).
- Back: ``d.push_back(val)`` (O(1)).
- Middle: ``d.insert(pos, val)`` (O(n)).

**Deletion:**
- Front: ``d.pop_front()`` (O(1)).
- Back: ``d.pop_back()`` (O(1)).
- Middle: ``d.erase(pos)`` (O(n)).

### 3. std::list
When frequent insertions and deletions are needed in the middle of the container (O(1) for insertion/deletion). **No random access**

**Structure:** 
- Doubly-linked list.

**Access to Members:**
- Sequential access only: Use ``std::next(iterator, n)`` to navigate (O(n)).
- ``l.front()``, ``l.back()``.

**Insertion**
- Anywhere: ``l.insert(pos, val)`` (O(1) when iterator is provided).

**Deletion:**
- Anywhere: ``l.erase(pos)`` (O(1) when iterator is provided).



# Choosing the Right Container

#### Do you need sorting?

- Yes → Use associative containers (set, map).
- No → Use unordered containers (unordered_set, unordered_map).

#### Do you need indexing?

- Yes → Use sequence containers (vector, deque).

#### Do you need frequent insertion/deletion?

- Yes → Use linked containers (list, deque).

#### Do you need a stack or queue structure?

- Yes → Use container adaptors (stack, queue).

## Iterator
In C++, an iterator is an object that enables a programmer to traverse a container, particularly lists, vectors, and other data structures.
- begin(): Returns an iterator to the first element.
- end(): Returns an iterator to the element following the last element.

## std::find
The std::find() algorithm is used to search for an element in a container.
It returns an iterator to the first element in the range [first, last) that matches the given value.
If no such element is found, it returns the last iterator.
The std::find() algorithm is defined in the <algorithm> header file.