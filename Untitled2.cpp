#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a;
    int b;
    int c;
    double x;
    double y;
    cout << "enter a ";
    cin >> a;
    cout << "enter b ";
    cin >> b;
    cout << "enter c ";
    cin >> c;
    if((b*b-4*a*c) >= 0)
    {
        x = ( -1*b + sqrt(b*b - 4*a*c) ) / (2 * a);
        cout << "first root equals " << x;
        y = ( -1*b - sqrt(b*b - 4*a*c) ) / (2 * a);
        cout << ", second root equals " << y;
    }
    else
    {
        cout << "the equation has no real roots";
    }
    return 0;
}
