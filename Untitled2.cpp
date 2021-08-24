#include <iostream>
#include <cmath>
#include <stdio.h>

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double x = 0;
    double y = 0;
    printf("enter a, b and c \n");
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a == 0)
    {
        x = (-1*c / b);
        printf("root equals %lf" ,x);
    }
        else
        {
            if((b*b-4*a*c) >= 0)
            {
                x = ( -1*b + sqrt(b*b - 4*a*c) ) / (2 * a);
                printf("first root equals %lf" ,x);
                y = ( -1*b - sqrt(b*b - 4*a*c) ) / (2 * a);
                printf(", second root equals %lf " ,y);
            }
            else
            {
                printf("the equation has no real roots");
            }
        }
    return 0;
}
