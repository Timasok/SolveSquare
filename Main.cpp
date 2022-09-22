#include <stdio.h>
#include <string.h>

#include "SolveEq.h"
#include "TestLauncher.h"

const char* HELP    = "-h";
const char* TEST    = "-t";
const char* HANDRUN = "-r";

int main(int argc, const char* argv[])
{
    if (argc == 1)
    {
        printLol();
        return 1;
    }

    if (strcmp(HELP, argv[1]) == 0)
    {
        printf("\t %s  вывести доступные команды\n"
               "\t %s fileName запустить тесты из файла\n"
               "\t %s запустить программу вручную\n",
            HELP, TEST, HANDRUN);
        
        return 0;
    }
    
    if (strcmp(TEST, argv[1]) == 0)
    {
        if (argc < 3)
        {
            printf("Ошибка: имя файла отстутствует\n"
                "Формат команды можно узнать %s", HELP);
            return 0;
        }

        readTestData(argv[2]);
        return 0;
    }

    if (strcmp(HANDRUN, argv[1]) == 0)
    {
        handRun();
        return 0;
    }
    
    printLol();
    return 1;
}