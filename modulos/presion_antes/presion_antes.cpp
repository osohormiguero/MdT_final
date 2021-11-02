
#include "arm_book_lib.h"
#include "presion_antes.h"


AnalogIn presionAntes(A0);


void sensorPresionAntesInit(){
    }

void sensorPresionAntesUpdate(){
    }
    
float sensorPresionAntesRead(){
    return presionAntes.read();
    }