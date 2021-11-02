//=====[Libraries]=============================================================

#include "sistema.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    //Inicializa el sistema
    sistemaInit();
    while (true) {
        //actualiza el sistema
        sistemaUpdate();
    }
}