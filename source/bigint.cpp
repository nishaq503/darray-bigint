//
// Created by Tom Howard and Najib Ishaq
//

#include "bigint.h"

void bigint::strip_zeros() {
    if ( number.empty() )
        number.push_back(0);
    else
        while ( number.size() > 1 && number.back() == 0 )
            number.pop_back();
}

bigint::bigint() {
    number.clear();
    number.push_back(0);
}

bigint::bigint( unsigned int i ) {
    number.clear();
    do {
        number.push_back( (digit)(i % 10) );
        i /= 10;
    } while ( i );
}

bigint::bigint( const std::string & str ) {
    number.clear();

    for ( size_t i = str.length() ; i > 0 ; --i ) {
        if (str[i - 1] < '0' || str[i - 1] > '9')
            throw std::invalid_argument("All elements in given string myst be digits.");

        number.push_back( (digit)(str[i - 1] - '0') );
    }

    this->strip_zeros();
}

bigint::bigint( const darray<digit> & num ) {
    number.clear();
    number = num;
    this->strip_zeros();
}

bigint::bigint( const bigint & that ) {
    number.clear();
    number = that.number;
}

bigint& bigint::operator=( const bigint & that ) {
    if ( this == &that ) // assignment to self.
        return *this;

    number.clear();
    number = that.number;

    return *this;
}

digit bigint::at( int index ) const {
    return number.at(index);
}

digit bigint::operator[]( int index ) const {
    return number.at(index);
}

std::string bigint::to_string(bool commas) const {
    std::string result;

    for ( int i = number.size() - 1 ; i >= 0 ; --i ) {
        result += std::to_string(number.at(i));
        if ( i % 3 == 0 && commas && i > 0 )
            result += ',';
    }

    return result;
}

std::string bigint::scientific(int decimal_points) const {
    return std::__cxx11::string();
}

std::ostream &bigint::operator<<(std::ostream &, bigint &) const {
    return <#initializer#>;
}

bool bigint::operator==(const bigint &) const {
    return false;
}

bool bigint::operator!=(const bigint &) const {
    return false;
}

bool bigint::operator<(const bigint &) const {
    return false;
}

bool bigint::operator<=(const bigint &) const {
    return false;
}

bool bigint::operator>(const bigint &) const {
    return false;
}

bool bigint::operator>=(const bigint &) const {
    return false;
}

bigint bigint::add(const bigint &) const {
    return bigint();
}

bigint bigint::multiply(const bigint &) const {
    return bigint();
}

bigint bigint::power(int) const {
    return bigint();
}

bigint bigint::subtract(const bigint &) const {
    return bigint();
}

bigint bigint::divide(const bigint &) const {
    return bigint();
}

bigint bigint::mod(const bigint &) const {
    return bigint();
}

bigint bigint::operator+(const bigint &) const {
    return bigint();
}

bigint bigint::operator-(const bigint &) const {
    return bigint();
}

bigint bigint::operator*(const bigint &) const {
    return bigint();
}

bigint bigint::operator/(const bigint &) const {
    return bigint();
}

bigint bigint::operator%(const bigint &) const {
    return bigint();
}

bigint &bigint::operator+=(const bigint &) {
    return <#initializer#>;
}

bigint &bigint::operator-=(const bigint &) {
    return <#initializer#>;
}

bigint &bigint::operator*=(const bigint &) {
    return <#initializer#>;
}

bigint &bigint::operator/=(const bigint &) {
    return <#initializer#>;
}

bigint &bigint::operator%=(const bigint &) {
    return <#initializer#>;
}

bigint &bigint::operator++() {
    return <#initializer#>;
}

bigint bigint::operator++(int) {
    return bigint();
}

bigint &bigint::operator--() {
    return <#initializer#>;
}

bigint bigint::operator--(int) {
    return bigint();
}

bigint bigint::fast_multiply(const bigint &) const {
    return bigint();
}

bigint bigint::fast_power(int) const {
    return bigint();
}

bigint bigint::fast_divide(const bigint &) const {
    return bigint();
}

bigint bigint::fast_mod(const bigint &) const {
    return bigint();
}

