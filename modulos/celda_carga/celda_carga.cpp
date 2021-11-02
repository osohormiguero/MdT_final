#include "mbed.h"
#include "arm_book_lib.h"
#include "HX711.h"

#define _FACTOR_CALIBRACION_ 1

HX711 celda(A3, A4);


void celdaCargaInit(){
    celda.setScale(_FACTOR_CALIBRACION_);
    }
    
float celdaCargaRead(){
    return celda.getGram();
    }