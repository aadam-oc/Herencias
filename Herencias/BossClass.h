//BossClass.h

#pragma once
#include <iostream>
#include "CharactersClass.h"

using namespace std;

class HerenciasBossClass : public HerenciasCharactersClass {
private:
    int Attack1;
    int Attack2;

public:
    HerenciasBossClass();
    HerenciasBossClass(string cName, int cHp, int cAttack, int cXPosition, int cYPosition, int cAttack1, int cAttack2);

    void getEnemigoFinal();
    void setEnemigoFinal(string cName, int cHp, int cAttack, int cXPosition, int cYPosition, int cAttack1, int cAttack2);
    int getAttack1();
    void setAttack1(int cAttack1);
    int getAttack2();
    void setAttack2(int cAttack2);
    void useAttack();
};
