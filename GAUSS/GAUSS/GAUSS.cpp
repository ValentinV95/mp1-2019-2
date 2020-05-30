#include "classes.h"

int main()
{
    int s;
    cout << "vvedite razmer vectora" << endl;
    cin >> s;
    Vector <double> mVector(s);
    slau<double>m(s);
    m.RandM();
    cout << "pervonachalnaya matrica" << endl;
    m.printM();
    mVector = m.gauss();
}