//CharactersClass.h
#pragma once
#include <iostream>
#include <string>

using namespace std;

class HerenciasCharactersClass {
private:
    string Name;
    int Hp;
    int Attack;
    int XPosition;
    int YPosition;

public:
    HerenciasCharactersClass();
    HerenciasCharactersClass(string cName, int cHp, int cAttack, int cXPosition, int cYPosition);

    // Name
    string getName();
    void setName(string cName);
    void updateName(string cName);

    // Hp
    int getHp();
    void setHp(int cHp);

    // Attack
    int getAttack();
    void setAttack(int cAttack);

    // XPosition
    int getXPosition();
    void setXPosition(int cXPosition);

    // YPosition
    int getYPosition();
    void setYPosition(int cYPosition);

    // Builder
    void CharacterBuilder(string cName, int cHp, int cAttack, int cXPosition, int cYPosition);

    // Stats
    void getStats();

    // Position
    int getPosition() ;

    // Movimientos del personaje
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};
