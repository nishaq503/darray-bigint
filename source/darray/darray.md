# Templated Dynamic Arrays

**Najib Ishaq** for CSC211 at URI

This is an implementation of Templated Dynamic Arrays.

## Why use Dynamic Arrays over C-Arrays

C-Arrays are extremely useful and easy to understand. They allow us to store similar and/or related values **together** in a chunk of memory. They allow for easy access of different elements in the array via indexing. However, C-Arrays do not know their own size, and this fact has some potentially dangerous ramifications. These arise from the realization that there is nothing in C\texttt{++} to stop you from accessing memory that you did not secure for the array. Specifically, this means that you can access random and uninitialized sections of memory and the language will not warn you about it. Not knowing when you may be doing this can create errors far later in your code. Such errors are notoriously difficult to track down and can be the cause of several hours of frustration and hair-pulling.

We will get around this problem by creating our own class of Dynamic Arrays. We will implement this in such a way so as to not allow us to access memory from outside the array. We will also utilize templated types so we can make arrays with elements of any type.

\pagebreak

## darray.hpp

```c++
#ifndef __DARRAY_HPP__
#define __DARRAY_HPP__

template <class T>

class DArray {
    private:
        // pointer to dynamically allocated array.
        T* content;
        // number of elements in array.
        unsigned int length;
        // capacity reserved for array.
        unsigned int cap;

        // double capacity if length > capacity.
        void grow();
        // halve capacity if length < capacity/2.
        void shrink();

    public:
        // default constructor.
        DArray();
        // constructor for given size.
        DArray(const unsigned int s);
        // constructor for given size and value.
        // Initialize all entries to value.
        DArray(const unsigned int s, T value);
        // copy constructor.
        DArray(const DArray<T>* that);

        // destructor.
        ~DArray();

        // returns length of array.
        unsigned int size() const;
        // returns capacity of array.
        unsigned int capacity() const;
        // index access. throw error if index >= length.
        T at(unsigned int index) const;
        // returns first element of array.
        T front() const;
        // returns last element of array.
        T back() const;
        // returns true if length is 0;
        bool empty() const;
        // clear array. reset to default state.
        void clear();
        // set element at index to value.
        // throw error if index >= length.
        void set(unsigned int index, T value);
        // append value at end of array.
        void push(T value);
        // remove and return value from end of array.
        T pop();
        // insert value at index. move other values.
        // throw error if index >= length.
        void insert(unsigned int index, T value);
        // erase value at index. return that value.
        // throw error if index >= length.
        T erase(unsigned int index);
};

/*
Implementations go here.
*/

#endif // __DARRAY_HPP__
```

\pagebreak

## Private Variables

```c++
T* content;
```

`content` is a pointer to an array of type `T` created on the **heap** using the `new` operator.

```c++
unsigned int length;
```

`length` is the **size** of (i.e. number of elements in) the array.

```c++
unsigned int cap;
```

`cap` is the **capacity** of (i.e. max elements allowed in) the array.

## Private Methods

```c++
void grow();
```

When `length` exceeds `cap`:

* double `cap`,
* create a new array,
* copy over all the elements,
* and delete the old array.

```c++
void shrink();
```

When `length` is less than half of `cap`:

* halve `cap`,
* create new array,
* copy over all elements,
* and delete old array.

## Public Methods

### Constructors

```c++
DArray();
```

The default constructor sets:

* `length` at 0,
* `cap` at 10,
* and creates an array of type `T` on the **heap** with size equal to `cap`.

```c++
DArray(unsigned int s);
```

This constructor takes the requested size `s` as an argument and sets:

* `length` equal to `s`,
* `cap` equal to `2*s`,
* and creates an array of type `T` on the **heap** with size equal to `cap`.

```c++
DArray(unsigned int s, T value);
```

This constructor takes the requested size `s` and `value` as arguments, and sets:

* `length` equal to `s`,
* `cap` equal to `2*s`,
* creates an array of type `T` on the **heap** with size equal to `cap`.
* sets the first s elements in the array equal to `value`.

```c++
DArray(const DArray<T>* that);
```

This is the copy constructor. It copies over all the contents from the dynamic array pointed to by that.

### Destructor

```c++
~DArray();
```

The destructor frees up the memory alllocated for the array. This requires use of the `delete` operator.

### Getter Methods

```c++
unsigned int size() const;
```

Returns the number of elements in the array.

```c++
unsigned int capacity() const;
```

Returns the capacity reserved for the array.

```c++
T at(unsigned int index) const;
```

Returns the elements at location index in the array. Throw an error if an attempt is made to access memory beyond length.

```c++
T front() const;
```

Returns the first element in the array. Throws an error if array is empty.

```c++
T back() const;
```

Returns the last element in the array. Throws an error if array is empty.

```c++
bool empty() const;
```

Returns true if the array is empty, false otherwise.

### Editor Methods

```c++
void set(unsigned int index, T value);
```

Changes the element at location `index` in the array to `value`. Throws an error if `index` is out of bounds.

```c++
void push(T value);
```

Append `value` at the end of the array. `grow()` if needed.

```c++
T pop();
```

Removes the last element from the array. `shrink()` if needed. Return the last element. Throws an error if the array is empty.

```c++
void insert(unsigned int index, T value);
```

Insert `value` at given `index`. Move the other elements forward by one index. `grow()` if needed. Throw an error if `index` is out of bounds.s

```c++
T erase(unsigned int index);
```

Removes the element at `index` from the array. Moves relevant elements back by one index. Return the element removed from the array. Throws an error if `index` is out of bounds.
