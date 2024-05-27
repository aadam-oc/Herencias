// HerenciasLib.cpp
#include "HerenciasLib.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

namespace HerenciasLibrary
{
    int HerenciasFunctions::randX()
    {
        
        int randomX = rand() % 10;
        return randomX;
    }

    int HerenciasFunctions::randY()
    {
        //srand(time(0)); // Semilla aleatoria basada en el tiempo actual
        int randomY = rand() % 8 + 1;
        return randomY;
    }

    void HerenciasFunctions::printMap(char(&map)[10][10])
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    }
}
