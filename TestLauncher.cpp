#include <stdio.h>

#include "SolveEq.h"
#include "TestLauncher.h"

/**
*@brief Печатает результаты тестов
*@param[in] a коэффициент перед x^2
*@param[in] b коэффициент перед x^1
*@param[in] c коэффициент перед x^0
*@param[in] nRootsExpected правильное количество решений
*@param[in] x1Expected правильный больший корень / правильный единственный корень
*@param[in] x2Expected правильный меньший корень
*/
void printTestResults(double a, double b, double c, int nRootsExpected, double x1Expected, double x2Expected)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(isfinite(x1Expected));
    assert(isfinite(x2Expected));

    double x1 = 0.0, x2 = 0.0;
    int nRoots = solveSquareEq(a, b, c, &x1, &x2);

    if (!(isEqualDouble(nRoots, nRootsExpected) 
        && isEqualDouble(x1, x1Expected) 
        && isEqualDouble(x2, x2Expected)))
    {
        printf("FAILED:   nRoots = %d, x1 = %2.2lf, x2 = %2.2lf\n"
            "Expected: nRoots = %d, x1 = %2.2lf, x2 = %2.2lf\n"
            "\n", nRoots, x1, x2, nRootsExpected, x1Expected, x2Expected);
    }
    else
    {
        printf("THE TEST WAS PASSED SUCCESSFULLY\n"
                "\n");
    }

}

/**
*@brief Выполняет тесты, записанные в файле
*@param[out] fileName имя файла
*/
void readTestData(const char* fileName)
{
    assert(fileName != nullptr);

    FILE *fp = fopen(fileName, "r"); 

    if (fp == NULL)
    {
        printf("Ошибка в файле %s !\n", fileName);

        return;
    }

    for (int i = 0; i < MAXTESTS; i++)
    {
        double a = NAN, b = NAN, c = NAN, x1Expected = NAN, x2Expected = NAN;
        int nRootsExpected = NAN;

        if (fscanf(fp, "%lg %lg %lg %d %lg %lg\n", &a, &b, &c, &nRootsExpected, &x1Expected, &x2Expected) != 6)
        {
            printf("Ошибка в %d строчке файла %s \n", (i+1), fileName);
            fclose(fp);
            return;
        }

        printTestResults( a, b, c, nRootsExpected, x1Expected, x2Expected);
    }

    fclose(fp);
}

/**
*@brief Выполняет тесты, записанные в программной структуре данных
*@param[in]  numberOfTests количество тестов
*/
void testsFromStorage()
{
    double a_Ratio[MAXTESTS]         = { 1.0,   2.0,        0.0, 0.0,  1.0,  0.5, 0.0};
    double b_Ratio[MAXTESTS]         = { 0.0, -18.0,        0.0, 3.0, -5.5, -4.0, 0.0};
    double c_Ratio[MAXTESTS]         = {-4.0,  40.0,        0.0, 9.0,  6.0,  6.0, 7.0};
    int n_RootsExpected[MAXTESTS]    = {   2,     2,  Inf_Roots,   1,    2,    2,   0};
    double x1_Expected[MAXTESTS]     = { 2.0,   5.0,        0.0, 3.0,  4.0,  6.0, 0.0};
    double x2_Expected[MAXTESTS]     = {-2.0,   4.0,        0.0, 0.0,  1.5,  2.0, 0.0};

    for (int i = 0; i < MAXTESTS; i++)
    {
        printTestResults(a_Ratio[i], b_Ratio[i], c_Ratio[i], n_RootsExpected[i], x1_Expected[i], x2_Expected[i]);
    }
    
}