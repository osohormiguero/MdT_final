#include "mbed.h"
#include "arm_book_lib.h"
#include "user_interface.h"
#include "display.h"
#include "sistema.h"
#include "presion_antes.h"
#include "presion_despues.h"
#include "celda_carga.h"

#define DISPLAY_REFRESH_TIME_REPORT_MS 1000

static int displayRefreshTimeMs = DISPLAY_REFRESH_TIME_REPORT_MS;
static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();
static void userInterfaceDisplayReportStateInit();
static void userInterfaceDisplayReportStateUpdate();


void userInterfaceInit()
{
    userInterfaceDisplayInit(); 
}

void userInterfaceUpdate()
{
    userInterfaceDisplayUpdate();
}

static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_TYPE_GLCD_ST7920, DISPLAY_CONNECTION_SPI );
    userInterfaceDisplayReportStateInit();
}

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;

    if( accumulatedDisplayTime >= displayRefreshTimeMs ) {
        accumulatedDisplayTime = 0;
        userInterfaceDisplayReportStateUpdate();
        }

    else {
        accumulatedDisplayTime = accumulatedDisplayTime + TIEMPO_DE_INCREMENTO_MS;
    }
}


static void userInterfaceDisplayReportStateInit()
{
    displayRefreshTimeMs = DISPLAY_REFRESH_TIME_REPORT_MS;

    displayModeWrite( DISPLAY_MODE_CHAR );

    displayClear();

    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "PA:" ); //A de Antes de la bomba o aguas arriba

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "PD:" ); //D de Después de la bomba o aguas abajo

    displayCharPositionWrite ( 0,2 );
    displayStringWrite( "Peso:" ); // para determinar nivel en el recipiente
}


static void userInterfaceDisplayReportStateUpdate()
{
    char presionAntesString[5];
    char presionDespuesString[5];
    char pesoString[5];

    sprintf(presionAntesString, "%.2f", sensorPresionAntesRead());
    displayCharPositionWrite ( 7,0 );
    displayStringWrite( presionAntesString );
    displayCharPositionWrite ( 13,0 );
    displayStringWrite( "psi" );

    sprintf(presionDespuesString, "%.2f", sensorPresionDespuesRead());
    displayCharPositionWrite ( 7,1 );
    displayStringWrite( presionDespuesString );
    displayCharPositionWrite( 13,1);
    displayStringWrite("psi");
    
    sprintf(pesoString, "%.2f", celdaCargaRead());
    displayCharPositionWrite ( 7,2 );
    displayStringWrite( pesoString );
    displayCharPositionWrite(13,2);
    displayStringWrite("grs"); // unidad de peso elegida
}
