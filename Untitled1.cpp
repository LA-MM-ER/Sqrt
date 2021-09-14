///     @file Untitled1.cpp
///     \author Georgiy Moskvin
///     \version 1.0.0
///     \date 14.09.2021

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>

const int INFINITE_ROOTS = 3;

#define TEST
#ifdef TEST
#define RUN_PROG UnitTest();
#else
#define RUN_PROG solve_eq();
#endif

int solve_quadratic (double a, double b, double c, double *x1, double *x2);

//! @brief This test checks functionality of the function in standard situation
//! @param [in] a,b,c - coefficients of equation
//! @param [in] x1_true, x2_true - roots that we know
//! @param [in] x1_end, x2_end - variables for roots
//! @return success status of test (1 if test is success and 0 if not)

int test_classic() {
    double a = 1, b = -5, c = 6;
    double x1_true = 2, x2_true = 3;
    double x1_end = 0,  x2_end = 0;

    solve_quadratic(a, b, c, &x1_end, &x2_end);

    if ((x1_true == x1_end) && (x2_true == x2_end) || (x1_true == x2_end) && (x2_true == x1_end) ) {

        printf("ok\n");
        return 1;

    } else {

        printf("error\n");
        return 0;
    }
}

//! @brief This test checks functionality of the function when all coefficient variables equals zero
//! @param [in] a,b,c - coefficients of equation
//! @param [in] x1_end, x2_end - variables for roots
//! @return success status of test (1 if test is success and 0 if not)

int test_infinite() {
    int a = 0, b = 0, c = 0;
    double x1_end = 0, x2_end = 0;

    if (solve_quadratic(a, b, c, &x1_end, &x2_end) != 3) {

        printf ("error\n");
        return 0;

    } else {

        printf("ok\n");
        return 1;
    }
}

//! @brief This test checks functionality of the function when a equals 0 and b,c is not
//! @param [in] a,b,c - coefficients of equation
//! @param [in] x1_end, x2_end - variables for roots
//! @param [in] x1_true - root that we know
//! @return success status of test (1 if test is success and 0 if not)

int test_a_zero_only() {
    int a = 0, b = 2, c = -4;
    int x1_true = 2;
    double x1_end = 0, x2_end = 0;

    solve_quadratic(a, b, c, &x1_end, &x2_end);

    if (x1_true == x1_end)  {

        printf("ok\n");
        return 1;

    } else {

        printf("error\n");
        return 0;

    }
}

//! @brief This test checks functionality of the function when a, b equals 0 and c is not
//! @param [in] a,b,c - coefficients of equation
//! @param [in] x1, x2 - variables for roots
//! @return success status of test (1 if test is success and 0 if not)

int test_ab_zero_cnot() {
    double a = 0, b = 0, c = 3, x1 = 0, x2 = 0;

    if (solve_quadratic(a, b, c, &x1, &x2) != 0) {

        printf ("error\n");
        return 0;

    } else {

        printf("ok\n");
        return 1;
    }
}


//! @brief This test checks functionality of the function with negative discriminant
//! @param [in] a,b,c - coefficients of equation
//! @param [in] x1, x2 - variables for roots
//! @return success status of test (1 if test is success and 0 if not)

int test_negative_discr() {
    double a = 6, b = 2, c = 1, x1 = 0, x2 = 0;

    if (solve_quadratic(a, b, c, &x1, &x2) != 0) {

        printf ("error\n");
        return 0;

    } else {

        printf("ok\n");
        return 1;
    }
}

#define UNITTEST(func)                         \
    if (!func){                                \
                                               \
        printf("%s not passed\n", #func);      \
        return -1;                             \
                                               \
    } else {                                   \
                                               \
        printf("ok");                          \
        return 0;                              \
    }                                          \

//! @brief This function run all tests at once

int UnitTest() {
    UNITTEST(test_negative_discr())
    UNITTEST(test_ab_zero_cnot())
    UNITTEST(test_a_zero_only())
    UNITTEST(test_infinite())
    UNITTEST(test_classic())
}

//! @brief This function compares <double> variables with zero
//! @param [in] eps - the precision with which we measure a variable
//! @return 1 or 0 depending on the result of comparison with <eps>

bool is_zero(double number) {

    float eps = 0.00001;

    return (fabs(number) < eps);
}

//! @brief This function solves the square equation
//! @return number of roots
//! @param [in] - a, b, c - coefficients of equation
//! @param [out]  x1, x2 - roots of equation

int solve_quadratic (double a, double b, double c, double *x1, double *x2) {

    assert(x1 != NULL);

    if (is_zero(a)) {

        if (is_zero(b)) {

            if (is_zero(c)) {

                return INFINITE_ROOTS;

            } else {

                return 0;
            }

        } else {

            *x1 = (-1 * c / b);

            return 1;
        }

    } else {

        double discr = b * b - 4 * a * c;
        double sqrt_discr = sqrt(discr);

        if(discr >= 0) {

            *x1 = ( -1 * b + sqrt_discr ) / (2 * a);
            *x2 = ( -1 * b - sqrt_discr ) / (2 * a);

            return 2;

        } else {

            return 0;

        }
    }


}

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    printf("enter a, b and c \n");

    int num_read = scanf("%lf %lf %lf", &a, &b, &c);
    if (num_read != 3) {

        printf("wrong coefficients");
        return EXIT_FAILURE;

    } else {

        int num_roots = solve_quadratic(a, b, c, &x1, &x2);

        switch(num_roots) {

            case 0:
                printf("No roots\n");
                break;

            case 1:
                printf("root equals %lf\n", x1);
                break;

            case 2:
                printf("first root equals %lf,\n", x1);
                printf("second root equals %lf\n", x2);
                break;

            case INFINITE_ROOTS:
                printf("equation has infinite roots\n");
                break;

            default:
                printf("Error, num_roots is wrong and equals %d\n", num_roots);
                break;
        }
    }

    return 0;
}
