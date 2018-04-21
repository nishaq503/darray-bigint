//
// Created by Tom Howard and Najib Ishaq
//

#ifndef __BIGINT_H__
#define __BIGINT_H__

#include "darray.hpp"
#include <string>
#include <iostream>

typedef unsigned short digit;

class bigint {
private:
    darray <digit> number;

    void strip_zeros();

public:
    bigint();
    explicit bigint( unsigned int );
    explicit bigint( const std::string & );
    explicit bigint( const darray <digit> & );
    bigint( const bigint & );

    bigint& operator =( const bigint & );

    const darray <digit>& get_number() const { return number; }
    digit at( int ) const;

    digit operator []( int ) const;

    std::string to_string( bool commas = true) const;
    std::string scientific( int decimal_points = 3 ) const;

    std::ostream& operator <<( std::ostream &, bigint & ) const;

    bool operator ==( const bigint & ) const;
    bool operator !=( const bigint & ) const;
    bool operator <( const bigint & ) const;
    bool operator <=( const bigint & ) const;
    bool operator >( const bigint & ) const;
    bool operator >=( const bigint & ) const;

    bigint add( const bigint & ) const;
    bigint multiply( const bigint & ) const;
    bigint power( int ) const;

    bigint subtract( const bigint & ) const;
    bigint divide( const bigint & ) const;
    bigint mod( const bigint & ) const;

    bigint operator +( const bigint & ) const;
    bigint operator -( const bigint & ) const;
    bigint operator *( const bigint & ) const;
    bigint operator /( const bigint & ) const;
    bigint operator %( const bigint & ) const;

    bigint& operator +=( const bigint & );
    bigint& operator -=( const bigint & );
    bigint& operator *=( const bigint & );
    bigint& operator /=( const bigint & );
    bigint& operator %=( const bigint & );

    bigint& operator ++(); // prefix increment. ++i
    bigint operator ++()(int); // postfix increment. i++
    bigint& operator --(); // prefix decrement. --i
    bigint operator --()(int); // postfix decrement. i--

    bigint fast_multiply( const bigint & ) const;
    bigint fast_power( int ) const;
    bigint fast_divide( const bigint & ) const;
    bigint fast_mod( const bigint & ) const;

};


#endif //__BIGINT_H__
