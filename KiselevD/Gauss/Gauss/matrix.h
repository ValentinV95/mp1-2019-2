#pragma once

template < typename T >
class Matrix : public Vector< Vector < T > > {
public:
    Matrix(int n) : Vector < Vector < T > >(n, Vector < T >(n)) {}

private:
    
};