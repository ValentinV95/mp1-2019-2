#include "vector.h"
#include "matrix.h"
#include "slau.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{

    srand(time_t(NULL));

    Vector<double> b;
    //for (int i = 10; i < 12; ++i)
        b.push_back(36);
        b.push_back(47);
        b.push_back(37);

    SLAU<double> test(3);

    test[0][0] = 2;
    test[0][1] = 4;
    test[0][2] = 1;
    test[1][0] = 5;
    test[1][1] = 2;
    test[1][2] = 1;
    test[2][0] = 2;
    test[2][1] = 3;
    test[2][2] = 4;

    /*for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
            test[i][j] = rand() % 10;
    }*/

    for (int i = 0; i < test.Size(); ++i)
    {
        for (int j = 0; j < test[i].Size(); ++j)
            cout << test[i][j] << " ";
        cout << b[i] << endl;
    }

    Vector<double> * answer = test.Gausse(b);
    
    for (int i = 0; i < test.Size(); ++i)
    {
        for (int j = 0; j < test[i].Size(); ++j)
            cout << test[i][j] << " ";
        cout << b[i];
        cout << endl;
    }

    cout << endl << "X : ";
    if(answer)
    for (int k = 0; k < answer->Size(); ++k)
        cout << (*answer)[k] << " ";

    return 0;
}
