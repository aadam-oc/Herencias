//CharactersClass.cpp

#include "CharactersClass.h"

HerenciasCharactersClass::HerenciasCharactersClass() {
    Name = "Name";
    Hp = 0;
    Attack = 0;
    XPosition = 0;
    YPosition = 0;
}

HerenciasCharactersClass::HerenciasCharactersClass(string cName, int cHp, int cAttack, int cXPosition, int cYPosition) 
{
    Name = cName;
    Hp = cHp;
    Attack = cAttack;
    XPosition = cXPosition;
    YPosition = cYPosition;
}

// Name
string HerenciasCharactersClass::getName() {
    return Name;
}

void HerenciasCharactersClass::setName(string cName) {
    Name = cName;
}

void HerenciasCharactersClass::updateName(string cName) {
    Name = cName;
}

// Hp
int HerenciasCharactersClass::getHp() {
    return Hp;
}

void HerenciasCharactersClass::setHp(int cHp) {
    Hp = cHp;
}

// Attack
int HerenciasCharactersClass::getAttack() {
    return Attack;
}

void HerenciasCharactersClass::setAttack(int cAttack) {
    Attack = cAttack;
}

// XPosition
int HerenciasCharactersClass::getXPosition() {
    return XPosition;
}

void HerenciasCharactersClass::setXPosition(int cXPosition) {
    XPosition = cXPosition;
}

// YPosition
int HerenciasCharactersClass::getYPosition() {
    return YPosition;
}

void HerenciasCharactersClass::setYPosition(int cYPosition) {
    YPosition = cYPosition;
}

// Builder
void HerenciasCharactersClass::CharacterBuilder(string cName, int cHp, int cAttack,
    int cXPosition, int cYPosition) {
    Name = cName;
    Hp = cHp;
    Attack = cAttack;
    XPosition = cXPosition;
    YPosition = cYPosition;
}

// Stats
void HerenciasCharactersClass::getStats() {
    cout << "Nombre: " << Name << "\nVida restante: " << Hp << "\nAtaque: " << Attack; // Aquí deberías usar YPosition en lugar de getYPosition
}

// Position
//void HerenciasCharactersClass::getPosition() {
//    cout << "\nPosicion: \n   X=" << XPosition << "\n   Y=" << YPosition; 
//}
int HerenciasCharactersClass::getPosition() {
        return XPosition << YPosition;
  }

//Moverse
void HerenciasCharactersClass::moveUp() {
    YPosition--;
}

void HerenciasCharactersClass::moveDown() {
    YPosition++;
}

void HerenciasCharactersClass::moveLeft() {
    XPosition--;
}

void HerenciasCharactersClass::moveRight() {
    XPosition++;
}