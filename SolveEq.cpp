#include <stdio.h>
#include <string.h>

#include "SolveEq.h"

#define SOFT_ASSERT(condition) {                                                                                \
    if(!(condition))                                                                                            \
        printf("Error: %s, file: %s, line: %d, function: %s\n", #condition, __FILE__, __LINE__,__FUNCTION__)     \
}

const double EPS = 0.0001;

/**
*@brief Выводит сообщение если произошла ошибкой
*/
void printLol(){
    printf("Команда отсутствует или введена с ошибкой, для информации запустите %s\n", HELP);
}

/**
*@brief Запускает ручной ввод
*/
void handRun()
{

    printf("Введите коэффициенты квадратного уравнения: \n");

    double a = NAN, b = NAN, c = NAN;

    while (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        scanf( "%*[^\n]" );
        printf("Ошибка, повторите ввод\n");
    }

    double x1 = NAN, x2 = NAN;
    int nRoots = solveSquareEq(a, b, c, &x1, &x2);
    printRoots(nRoots, x1, x2);  

}

/**
*@brief Сравнивает два вещественных числа с точностью до константы
*@param[in] d1 первое число
*@param[in] d2 второе число
*/
bool isEqualDouble(double d1, double d2)
{
    assert(isfinite(d1));
    assert(isfinite(d2));
    
    return (fabs(d1 - d2) < EPS);
}

/**
*@brief Решает линейное уравнение, возвращает количество корней
*@param[in] b коэффициент перед x^1
*@param[in] c коэффициент перед x^0
*@param[out] x корень уравнения
*/
nRoots solveLinearEq(double b, double c, double* x)
{

    assert(isfinite(b));
    assert(isfinite(c));
    assert(x != nullptr);

    if (!isEqualDouble(b, 0.0))
    {
        *x = -(c / b);

        return One_Root;
    }

    if (isEqualDouble(c, 0.0))
    {
            return Inf_Roots;
    }

    return No_Roots;

}

/**
*@brief Решает квадратное уравнение, возвращает количество корней
*@param[in] a коэффициент перед x^2
*@param[in] b коэффициент перед x^1
*@param[in] c коэффициент перед x^0
*@param[out] x1 больший корень / единственный корень
*@param[out] x2 меньший корень
*/
nRoots solveSquareEq(double a, double b, double c, double* x1, double* x2)
{

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);

    if (isEqualDouble(a, 0.0))
    {
        return solveLinearEq(b, c, x1);
    }    

    if (isEqualDouble(c, 0.0))
    {
        if (b == 0)
        {
            *x1 = 0.0;

            return One_Root;
        }

        *x1 = 0;   
        *x2 = -b/a;

        return Two_Roots;

    }

    if (b == 0 && c/a < 0)
    {
        *x1 = sqrt(-c/a);
        *x2 = -(*x1);

        return Two_Roots;

    }

    double D = b * b - 4 * a * c;
    if (isEqualDouble(D, 0.0))
    {
        *x1 = -( b / (2 * a));
        
        return One_Root;
    }

    if (D < 0.0){
       return No_Roots; 
    }

    double sqD = sqrt(D);
    *x1 = (-b + sqD)/(2 * a);   
    *x2 = (-b - sqD)/(2 * a);
        
    return Two_Roots;
    
}

/**
*@brief Выводит количество решений и корни если они есть
*@param[in] nRoots количество решений
*@param[in] x1 больший корень / единственный корень
*@param[in] x2 меньший корень
*/
void printRoots(int nRoots, double x1, double x2)
{


    const char* EQ = "У этого уравнения";
    
    switch (nRoots)
    {
        case Inf_Roots:
                printf("%s бесконечно много решений\n", EQ);
                break;
        case No_Roots :
                printf("%s нет решений\n", EQ);
                break;
        case One_Root :
                printf("%s корнем является %5.2lf\n", EQ, x1);
                break;
        case Two_Roots:
                printf("%s корнями являются %5.2lf %5.2lf\n", EQ, x1, x2);
                break;
    }

}