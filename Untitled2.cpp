#include <iostream>
#include <cmath>

int main()
{
    int a;
    int b;
    int c;
    double x;
    double y;
    std::cout << "enter a ";
    std::cin >> a;
    std::cout << "enter b ";
    std::cin >> b;
    std::cout << "enter c ";
    std::cin >> c;
    if((b*b-4*a*c) >= 0)
    {
        x = ( -1*b + sqrt(b*b - 4*a*c) ) / (2 * a);
        std::cout << "first root equals " << x;
        y = ( -1*b - sqrt(b*b - 4*a*c) ) / (2 * a);
        std::cout << ", second root equals " << y;
    }
    else
    {
        std::cout << "the equation has no real roots";
    }
    return 0;
}
