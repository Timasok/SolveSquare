#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

extern const char* HELP;
extern const char* TEST;
extern const char* HANDRUN;

enum nRoots{    
    Inf_Roots = -1,
    No_Roots  =  0,
    One_Root  =  1,
    Two_Roots =  2
};

nRoots solveSquareEq(double a, double b, double c, double* x1, double* x2);
nRoots solveLinearEq(double b, double c, double* x);
void printRoots(int res, double x1, double x2);
bool isEqualDouble(double d1, double d2);

void handRun();
void printLol();