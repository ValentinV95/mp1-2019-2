#pragma once

template < typename T >
class Matrix : public Vector< Vector < T > > {
public:

    Matrix(int n) : Vector < Vector < T > >(n, Vector < T >(n)) {}

    void m_print() {
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
            {
                cout << this->m_x[i][j] << "\t";
            }
            cout << endl;
        }
    }

private:

};