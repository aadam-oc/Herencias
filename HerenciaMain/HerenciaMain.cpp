#include <iostream>
#include "HerenciasLib.h"
#include "CharactersClass.h"
#include <conio.h> // Para getch()
#include <windows.h> // Para Sleep()

#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"

using namespace std;


const int MAP_SIZE = 10;
BOOLEAN batallaFinalAcabada = false;
BOOLEAN batallaAcabada = false;
char iconoEnemigo = 'E';
BOOLEAN showEnemies = true
;


void initializeMap(char map[MAP_SIZE][MAP_SIZE]) {
    // Inicializa el mapa con caracteres de punto
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            map[i][j] = '.';
        }
    }
}

void placeCharacter(char map[MAP_SIZE][MAP_SIZE], HerenciasCharactersClass& character, char symbol) {
    // Coloca el personaje en el mapa en sus coordenadas
    int x = character.getXPosition();
    int y = character.getYPosition();
    map[y][x] = symbol;
}



int main() {
    srand(time(NULL));
    char map[MAP_SIZE][MAP_SIZE]; // Declara un mapa de 10x10

    // Inicializa el mapa con puntos (.)
    initializeMap(map);

    // Crear personaje
    HerenciasCharactersClass Personaje;
    Personaje.CharacterBuilder("Personaje", 200, 20, MAP_SIZE / 2, 0); // Personaje en el centro de la fila superior
    HerenciasCharactersClass EnemigoFinal;
    EnemigoFinal.CharacterBuilder("EnemigoFinal", 200, 20, HerenciasLibrary::HerenciasFunctions::randX(), 9); // Personaje en el centro de la fila superior

    // Crear enemigos
    HerenciasCharactersClass Enemigos[4];
    for (int i = 0; i < 4; ++i) {
        Enemigos[i].CharacterBuilder("Enemigo", 100, 10, HerenciasLibrary::HerenciasFunctions::randX(), HerenciasLibrary::HerenciasFunctions::randY());
    }

    char keyPressed; // Variable para almacenar la tecla presionada

    // Bucle principal del juego
    while (true) {
        // Limpiar la pantalla
        system("cls");

        // Detectar tecla presionada
        if (_kbhit()) { // kbhit() detecta si se ha presionado una tecla
            keyPressed = _getch(); // Obtiene la tecla presionada
            switch (keyPressed) {
            case 'w':
                Personaje.moveUp();
                break;
            case 's':
                Personaje.moveDown();
                break;
            case 'a':
                Personaje.moveLeft();
                break;
            case 'd':
                Personaje.moveRight();
                break;
            }
        }

        // Limpiar el mapa y colocar al personaje
        initializeMap(map);
        placeCharacter(map, Personaje, 'P');
        placeCharacter(map, EnemigoFinal, 'S');

        // Colocar enemigos en el mapa
        if (showEnemies == true)
        {
            for (int i = 0; i < 4; ++i) {
                placeCharacter(map, Enemigos[i], iconoEnemigo);
            }
        }
        

        // Imprime el mapa
        HerenciasLibrary::HerenciasFunctions::printMap(map);

        Sleep(1);
        if (Personaje.getPosition() == EnemigoFinal.getPosition())
        {
            system("cls");
            cout << "Has encontrado la salida pero esta custodiada por un enemigo con la misma vida que tu, tendras que luchar contra el para salir\n\n\n";
            Sleep(2000);
            system("cls");
            cout << "\n\nPrimero empezara atacando el personaje y luego atacara el Enemigo hasta que uno de los dos muera\n\n";
            Personaje.getStats();
            cout << "\n\n";
            EnemigoFinal.getStats();
            cout << "\n\n";
            /*system("pause");*/

            while (batallaFinalAcabada == false && batallaAcabada == false)
            {
                //En cada ronda tanto el enemigo pueden hacer entre 20 y 30 de daño
                int dañoEnemigo = rand() % 10;
                int dañoPersonaje = rand() % 10;
                EnemigoFinal.setAttack(EnemigoFinal.getAttack() + dañoEnemigo);
                Personaje.setAttack(Personaje.getAttack() + dañoPersonaje);


                Sleep(800);

                cout << Personaje.getName() << ": \n";
                EnemigoFinal.setHp(EnemigoFinal.getHp() - Personaje.getAttack());
                if (EnemigoFinal.getHp() > 0)
                {
                    cout << "El personaje le ha hecho " << Personaje.getAttack() << " puntos de daño al enemigo final y le quedan " << EnemigoFinal.getHp() << " de vida\n\n\n\n";
                }
                else
                {
                    cout << "El personaje le ha hecho " << Personaje.getAttack() << " puntos de daño al enemigo final y le quedan 0 puntos de vida\n\n\n\n";
                }
                
                if (Personaje.getHp() <= 0 || EnemigoFinal.getHp() <= 0)
                {
                    if (Personaje.getHp() < EnemigoFinal.getHp())
                    {
                        cout << RED << "Ha ganado el enemigo" << RESET;
                        return 0;
                    }
                    else if (Personaje.getHp() > EnemigoFinal.getHp())
                    {
                        cout << LGREEN << "Has ganado y has conseguido salir" << RESET;
                        return 0;
                    }
                }
                
                if (Personaje.getHp() > 0)
                {
                    cout << "\n" << EnemigoFinal.getName() << ": \n";
                    Personaje.setHp(Personaje.getHp() - EnemigoFinal.getAttack());
                    if (Personaje.getHp() > 0)
                    {
                        cout << "El enemigo final te ha hecho " << EnemigoFinal.getAttack() << " puntos de daño y te quedan " << Personaje.getHp() << "puntos de vida\n\n\n\n";
                    }
                    else
                    {
                        cout << "El enemigo final te ha hecho " << EnemigoFinal.getAttack() << " puntos de daño y te quedan 0 puntos de vida\n\n\n\n";
                    }
                    
                }
                

                Sleep(500);
                if (Personaje.getHp() <=0 || EnemigoFinal.getHp() <= 0)
                {
                    if (Personaje.getHp() < EnemigoFinal.getHp())
                    {
                        cout << RED << "Ha ganado el enemigo" << RESET;
                        return 0;
                    }
                    else if (Personaje.getHp() > EnemigoFinal.getHp())
                    {
                        cout << LGREEN << "Has ganado y has conseguido salir" << RESET;
                        return 0;
                    }
                }
            } 

            
        }
        for (int i = 0; i < 4; i++)
        {
            if (Personaje.getPosition() == Enemigos[i].getPosition())
            {
                cout << "Te has encontrado a un enemigo, ahora vas a tener que luchar contra el   \n\n\n";
                while (batallaFinalAcabada == false && batallaAcabada == false)
                {
                    
                    int dañoEnemigo = rand() % 10;
                    int dañoPersonaje = rand() % 10;
                    Enemigos[i].setAttack(Enemigos[i].getAttack() + dañoEnemigo);
                    Personaje.setAttack(Personaje.getAttack() + dañoPersonaje);

                    Sleep(1000);
                    system("cls");

                    cout << Personaje.getName() << ": \n";
                    Enemigos[i].setHp(Enemigos[i].getHp() - Personaje.getAttack());

                    if (Enemigos[i].getHp() > 0)
                    {
                        cout << "El personaje le ha hecho " << Personaje.getAttack() << " puntos de daño al enemigo y le quedan " << Enemigos[i].getHp() << " de vida\n\n\n\n";
                    }
                    else
                    {
                        cout << "El personaje le ha hecho " << Personaje.getAttack() << " puntos de daño al enemigo final y le quedan 0 puntos de vida\n\n\n\n";
                    }

                    if (Personaje.getHp() <= 0 || Enemigos[i].getHp() <= 0)
                    {
                        if (Personaje.getHp() < Enemigos[i].getHp())
                        {
                            cout << RED << "Ha ganado el enemigo" << RESET;
                            keyPressed = 's';
                            batallaAcabada = true;
                        }
                        else if (Personaje.getHp() > Enemigos[i].getHp())
                        {
                            cout << LGREEN << "Has ganado " << RESET;
                            keyPressed = 's';
                            batallaAcabada = true;
                        }
                    }

                    if (Personaje.getHp() > 0)
                    {
                        cout << "\n" << Enemigos[i].getName() << ": \n";
                        Personaje.setHp(Personaje.getHp() - Enemigos[i].getAttack());
                        if (Personaje.getHp() > 0)
                        {
                            cout << "El enemigo te ha hecho " << Enemigos[i].getAttack() << " puntos de daño y te quedan " << Personaje.getHp() << "puntos de vida\n\n\n\n";
                        }
                        else
                        {
                            cout << "El enemigo te ha hecho " << Enemigos[i].getAttack() << " puntos de daño y te quedan 0 puntos de vida\n\n\n\n";
                        }

                    }


                    Sleep(500);
                    if (Personaje.getHp() <= 0 || Enemigos[i].getHp() <= 0)
                    {
                        if (Personaje.getHp() < Enemigos[i].getHp())
                        {
                            cout << RED << "Ha ganado el enemigo" << RESET;
                            keyPressed = 's';
                            batallaAcabada = true;
                        }
                        else if (Personaje.getHp() > Enemigos[i].getHp())
                        {
                            cout << LGREEN << "Has ganado" << RESET;
                            keyPressed = 's';
                            batallaAcabada = true;

                        }
                    }

                }
                



                
            }
        }
        Sleep(2);
    }

}