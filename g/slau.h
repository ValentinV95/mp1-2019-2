#pragma once
#include "matrix.h"
#include <iostream>
#include "math.h"

using namespace std;

template<class T>
class SLAU : public Matrix<T>                   //наследует матрицу
{
public:
    SLAU(int n) : Matrix<T>::Matrix(n) {}

    Vector<double>* Gausse(Vector<T> y);

};

template<class T>
inline Vector<double>* SLAU<T>::Gausse(Vector<T> y) //метод гаус передаем как параметр правую                                                       часть
{
    Vector< Vector<T> > a = this[0];
    
    Vector<double>* x = new Vector<double>(a.Size() , 0);
    int k, index;
    const double eps = 0.00001;                             // точность
    int n = a.Size();
    double max;
    k = 0;
    while (k < n)
    {                                                      // поиск строки с максимальным a[i][k]
        max = abs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }
        if (max < eps)                      // перестановка строк
        {
            cout << "решение невозможно из-за нулевого столбца ";   // нет нулевых диагональных
            cout << index << " матрицы A" << endl;                  //элементов
            return 0;
        }

        for (int j = 0; j < n; j++)
        {
            T temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }

                                                    // SwapRow(index, k, &a);

        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;
        

                                                        // нормализация уравнений
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];
            if (abs(temp) < eps) continue;              // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            y[i] = y[i] / temp;
            if (i == k)  continue;                      // не вычитать уравнение само из себя
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            y[i] = y[i] - y[k];
        }

        k++;
    }
    for (k = n - 1; k >= 0; k--)                    // обратная подстановка
    {
        (*x)[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * (*x)[k];
    }
    return x;

}

