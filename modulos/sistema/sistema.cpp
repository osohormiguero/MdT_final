//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "motor_bomba.h"
#include "valvula.h"
#include "presion_antes.h"
#include "presion_despues.h"
#include "pc_serial_com.h"
#include "sistema.h"
#include "control_sensores.h"
#include "alarmas.h"
#include "user_interface.h"

//=====[Main function, the program entry point after power on or reset]========


//establece la variable de comunicacion con la consola
static Serial usbPort_sistema(USBTX, USBRX);

//inicaliza el sistema
void sistemaInit(){
    usbPort_sistema.printf("El programa está corriendo!\n");
    valvulaInit();
    motorBombaInit();
    pcSerialComInit();
    controlSensoresInit();
    alarmasInit();
    userInterfaceInit();
    }
    
void sistemaUpdate(){
    pcSerialComUpdate();
    controlSensoresUpdate();
    userInterfaceUpdate();
    delay(TIEMPO_DE_INCREMENTO_MS);
    }