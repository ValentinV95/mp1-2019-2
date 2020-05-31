#include "classes.h"

int main()
{
    int s;
    double* pt;
    cout << "vvedite razmer vectora" << endl;
    cin >> s;
    pt = new double[s];
    Vector <double> mVector(s);
    slau<double>m(s);
    m.RandM();
    for (int i = 0; i < s; i++)
    {
        cout << "Vvedite " << i << " pravoe znachenie" << endl;
        cin >> pt[i];
    }
    cout << "pervonachalnaya matrica" << endl;
    m.printM();
    mVector = m.gauss(pt);
}