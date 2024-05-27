//BossClass.cpp
#include "BossClass.h"

HerenciasBossClass::HerenciasBossClass() : Attack1(0), Attack2(0) {
}

HerenciasBossClass::HerenciasBossClass(string cName, int cHp, int cAttack, int cXPosition, int cYPosition, int cAttack1, int cAttack2)
    : HerenciasCharactersClass(cName, cHp, cAttack, cXPosition, cYPosition), Attack1(cAttack1), Attack2(cAttack2) {
}

void HerenciasBossClass::getEnemigoFinal() {
    cout << "Nombre: " << getName() << endl;
    cout << "HP: " << getHp() << endl;
    cout << "Ataque: " << getAttack() << endl;
    cout << "Posición X: " << getXPosition() << endl;
    cout << "Posición Y: " << getYPosition() << endl;
    cout << "Ataque 1: " << Attack1 << endl;
    cout << "Ataque 2: " << Attack2 << endl;
}

void HerenciasBossClass::setEnemigoFinal(string cName, int cHp, int cAttack, int cXPosition, int cYPosition, int cAttack1, int cAttack2) {
    setName(cName);
    setHp(cHp);
    setAttack(cAttack);
    setXPosition(cXPosition);
    setYPosition(cYPosition);
    Attack1 = cAttack1;
    Attack2 = cAttack2;
}

int HerenciasBossClass::getAttack1() {
    return Attack1;
}

void HerenciasBossClass::setAttack1(int cAttack1) {
    Attack1 = cAttack1;
}

int HerenciasBossClass::getAttack2() {
    return Attack2;
}

void HerenciasBossClass::setAttack2(int cAttack2) {
    Attack2 = cAttack2;
}

void HerenciasBossClass::useAttack() {
}
