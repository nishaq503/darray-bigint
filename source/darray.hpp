//
// Created by Najib Ishaq on 4/20/18.
//

#ifndef __DARRAY_HPP__
#define __DARRAY_HPP__

#ifndef NULL
#define NULL 0x00
#endif

#include <new> // for bad_alloc
#include <stdexcept> // for out_of_range
#include <iostream>
#include <string>

template < class T >

class darray {

private:
    T* content;
    int length, capacity;
    const int multiplier = 2, starting_capacity = 128;

    void grow() {
        if ( length < capacity ) return;
        else {
            capacity *= multiplier;
            T *new_content;

            try {
                new_content = new T[capacity];
            }
            catch ( std::bad_alloc& ) {
                throw std::bad_alloc();
            }

            for ( int i = 0 ; i < length ; ++i)
                new_content[i] = content[i];

            delete [] content;
            content = new_content;
        }
    }

    void shrink() {
        if ( length > capacity / 2 ) return;
        else {
            capacity /= multiplier;
            T *new_content;

            try {
                new_content = new T[capacity];
            }
            catch ( std::bad_alloc& ) {
                throw std::bad_alloc();
            }

            for ( int i = 0 ; i < length ; ++i)
                new_content[i] = content[i];

            delete [] content;
            content = new_content;
        }
    }

public:
    darray () {
        length = 0;
        capacity = starting_capacity;

        try {
            content = new T[capacity];
        }
        catch ( std::bad_alloc& ) {
            throw std::bad_alloc();
        }
    }

    explicit darray ( int l ) {
        length = l;
        capacity = 2 * l;

        try {
            content = new T[capacity];
        }
        catch ( std::bad_alloc& ) {
            throw std::bad_alloc();
        }
    }

    darray ( const T *c , int l ) {
        length = l;
        capacity = 2 * l;

        try {
            content = new T[capacity];
        }
        catch ( std::bad_alloc& ) {
            throw std::bad_alloc();
        }

        for ( int i = 0 ; i < l ; ++i )
            content[i] = c[i];
    }

    darray ( const darray <T> &that ) {
        length = that.length;
        capacity = that.capacity;

        try {
            content = new T[capacity];
        }
        catch ( std::bad_alloc& ) {
            throw std::bad_alloc();
        }

        for ( int i = 0 ; i < this->length ; ++i )
            content[i] = that.content[i];
    }

    virtual ~darray () {
        delete content;
        capacity = 0;
        length = 0;
    }

    int size() const {
        return length;
    }

    bool empty() const {
        return ! length;
    }

    darray <T>& operator =(const darray <T> &that) {
        if ( this == &that ) // assignment to self.
            return *this;

        length = that.length;
        capacity = that.capacity;

        try {
            content = new T[capacity];
        }
        catch ( std::bad_alloc& ) {
            throw std::bad_alloc();
        }

        for ( int i = 0 ; i < length ; ++i )
            content[i] = that.content[i];

        return *this;
    }

    T& at ( int index ) const {
        if ( index < 0 || index >= length )
            throw std::out_of_range("Requested index is out of range.");

        return content[index];
    }

    T& operator [] ( int index ) const {
        return at ( index );
    }

    T& front () const {
        if ( length > 0) return content[0];
        else throw std::out_of_range("Array is empty.");
    }

    T& back () const {
        if ( length > 0) return content[length - 1];
        else throw std::out_of_range("Array is empty.");
    }

    T* begin () const {
        if ( length > 0) return content;
        else throw std::out_of_range("Array is empty.");
    }

    T* end () const {
        if ( length > 0) return content + length;
        else throw std::out_of_range("Array is empty.");
    }

    void push_back (const T& value) {
        grow();
        content[length++] = value;
    }

    void push_front (const T& value) {
        grow();
        for (int i = length ; i > 0 ; --i)
            content[i] = content[i - 1];

        content[0] = value;
    }

    void insert (int index, const T& value) {
        if ( index < 0 || index >= length )
            throw std::out_of_range("Requested index is out of range.");

        grow();
        for (int i = length ; i > index ; --i)
            content[i] = content[i - 1];

        content[index] = value;
    }

    T pop_back () {
        shrink();
        return content[length--];
    }

    T pop_front () {
        shrink();
        T temp = content[0];
        for (int i = 0 ; i < length - 1 ; ++i)
            content[i] = content[i + 1];

        return temp;
    }

    T erase (int index) {
        if ( index < 0 || index >= length )
            throw std::out_of_range("Requested index is out of range.");

        shrink();
        T temp = content[index];
        for (int i = index ; i < length - 1 ; ++i)
            content[i] = content[i + 1];

        return temp;
    }

    void clear() {
        delete [] content;
        length = 0;
        capacity = starting_capacity;
        content = new T[capacity];
    }

};

#endif //__DARRAY_HPP__
