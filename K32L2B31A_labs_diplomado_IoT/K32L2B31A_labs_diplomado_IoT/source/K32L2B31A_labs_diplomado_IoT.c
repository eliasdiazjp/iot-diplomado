/*! @file : K32L2B31A_labs_diplomado_IoT.c
 * @author  Elias Jesus Diaz P
 * @version 1.0.0
 * @date    12/11/2022
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
<<<<<<< HEAD
 /*******************************************************************************
<<<<<<< HEAD
** Includes
 **************************/
=======
* Includes
 ******************************************************************************/

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"
#include "fsl_adc16.h"
#include "fsl_device_registers.h"
#include "fsl_common.h"
#include "fsl_gpio.h"

#include "lpuart0.h"
#include "leds.h"
#include "sens_luz.h"


/***************************
 * Definitions
 **************************/
enum{
	CMD_AT_ATI_Display_Product_Identification_Information=0,
	CMD_AT_AT_GMI_Request_Manufacturer_Identification,
	CMD_AT_AT_GMM_Request_TA_Model_Identification,
	CMD_AT_AT_GMR_Request_TA_Revision_Identification_of_Software_Release,
	CMD_AT_AT_GSN_Request_International_Mobile_Equipment_Identity ,
};

enum{
	FSM_ESTADO_INICIO=0,
	FSM_ESTADO_ESPERA_NUEVO_DATO_LPUART0,
	FSM_ESTADO_ANALIZA_NUEVO_DATO_LPUART0,
	FSM_ESTADO_ENVIAR_COMANDO_ATI,
	FMS_ESTADO_ANALIZA_BUFFER,
	FSM_ESTADO_START_ADC,
	FSM_ESTADO_ESPERA_TIEMPO_RESULTADO,
	FSM_ESTADO_CAPTURA_RESULTADO_ADC,
	FSM_ESTADO_CAPTURA_IMPRIME_RESULTADO_ADC,
};

typedef struct _iot_nodo_data{
	uint16_t data_sensor_luz_adc;
	uint16_t data_sensor_luz_lux;
	//------------------------------------
	uint8_t data_sensor_luz_voltaje;
	uint8_t data_sensor_temperatura;
	uint16_t data_sensor_humedad;
	//------------------------------------
	uint16_t data_sensor_presion_atmosferica;
	//------------------------------------
} iot_nodo_data_t;



/***************************
 * Private Prototypes
 **************************/


/***************************
 * External vars
 **************************/
extern uint8_t dato_lpuart0;
extern uint8_t flag_nuevo_dato_lpuart0;

/***************************
 * Local vars
 **************************/


volatile static uint8_t i = 0 ;
uint8_t fst_estado_actual=FSM_ESTADO_INICIO;
const char* cmd_at[5]={
		"ATI\r\n",//identificacion del producto :nombre del fabricante,identificacion del modelo,identificación de la versión del software del producto
		"AT+GMI\r\n",//nombre del fabricante
		"AT+GMM\r\n",//identificacion del modelo
		"AT+GMR\r\n",//identificación de la versión del software del producto
		"AT+GSN\r\n",//IMEI del producto
};

iot_nodo_data_t datos_locales;

/***************************
 * Private Source Code
 **************************/

int main(void) {

/* Hardware de la placa de inicio. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();

#endif
        led_off_green();
        led_off_red();
 while(1) {
    	switch (fst_estado_actual){
    			case FSM_ESTADO_INICIO:
    				//Escribir condiciones iniciales para le ejecución de toda la FSM/
    				datos_locales.data_sensor_luz_adc = 1;
    				datos_locales.data_sensor_luz_voltaje = 2;
    				datos_locales.data_sensor_luz_lux = 3;
    				datos_locales.data_sensor_temperatura = 4;
    				datos_locales.data_sensor_humedad = 5;
    				datos_locales.data_sensor_presion_atmosferica = 6;

    				fst_estado_actual=FSM_ESTADO_ESPERA_NUEVO_DATO_LPUART0;
    				break;

    			case FSM_ESTADO_ESPERA_NUEVO_DATO_LPUART0:
    				if(leer_bandera_nuevo_dato()!=0){
    					escribir_bandera_nuevo_dato(0);
    					fst_estado_actual=FSM_ESTADO_ANALIZA_NUEVO_DATO_LPUART0;
    				}
    				break;

    			case FSM_ESTADO_ANALIZA_NUEVO_DATO_LPUART0:
    				switch(leer_dato()){
    				case 'x':
    					fst_estado_actual=FSM_ESTADO_START_ADC;
    					break;
    				case 'a':

    					fst_estado_actual=FSM_ESTADO_ENVIAR_COMANDO_ATI;
    					break;
					case 's':
						fst_estado_actual = FSM_ESTADO_ENVIAR_COMANDO_ATI;
						break;
>>>>>>> develop
					case 'd':
						fst_estado_actual = FSM_ESTADO_ENVIAR_COMANDO_ATI;
						break;
					case 'f':
						fst_estado_actual = FSM_ESTADO_ENVIAR_COMANDO_ATI;
						break;
					case 'g':
						fst_estado_actual = FSM_ESTADO_ENVIAR_COMANDO_ATI;
						break;
    				case 'h':
    					borrar_buffer();
    					PRINTF("BUFFER_CLEARED");
    					break;
    				default://dato ilegal
    					fst_estado_actual=FSM_ESTADO_INICIO;

    					break;
    				}
    				break;

    			case FSM_ESTADO_ENVIAR_COMANDO_ATI:
<<<<<<< HEAD
					if (leer_dato()=='s'){
=======
					if (leer_dato()=='a'){
>>>>>>> develop
						PRINTF("%s",cmd_at[CMD_AT_ATI_Display_Product_Identification_Information]);

						fst_estado_actual=FMS_ESTADO_ANALIZA_BUFFER;
						break;
						}

							if (leer_dato() == 's') {
						PRINTF("%s",cmd_at[CMD_AT_AT_GMI_Request_Manufacturer_Identification]);
						fst_estado_actual = FMS_ESTADO_ANALIZA_BUFFER;
						break;
							}

<<<<<<< HEAD
					if (leer_dato() == 'f') {
=======
					if (leer_dato() == 'd') {
>>>>>>> develop
						PRINTF("%s",cmd_at[CMD_AT_AT_GMM_Request_TA_Model_Identification]);
						fst_estado_actual = FMS_ESTADO_ANALIZA_BUFFER;
						break;
							}
<<<<<<< HEAD
					if (leer_dato() == 'g') {
=======
					if (leer_dato() == 'f') {
>>>>>>> develop
						PRINTF("%s",cmd_at[CMD_AT_AT_GMR_Request_TA_Revision_Identification_of_Software_Release]);
						fst_estado_actual = FMS_ESTADO_ANALIZA_BUFFER;
						break;
							}
<<<<<<< HEAD
					if (leer_dato() == 'h') {
=======
					if (leer_dato() == 'g') {
>>>>>>> develop
						PRINTF("%s",cmd_at[CMD_AT_AT_GSN_Request_International_Mobile_Equipment_Identity]);
						fst_estado_actual = FMS_ESTADO_ANALIZA_BUFFER;
						break;
							}

    			case FMS_ESTADO_ANALIZA_BUFFER:
    				anailiza_buffer();
    				    if(anailiza_buffer()==1){
    				    	PRINTF("no hay problemas");
    				    	borrar_buffer();
    				    	fst_estado_actual = FSM_ESTADO_INICIO;

    				    }
    				    if(anailiza_buffer()==2){
    				       PRINTF("hay un problema");
    				       borrar_buffer();
    				       fst_estado_actual = FSM_ESTADO_INICIO;

    				        				    }

    				    break;





    			case FSM_ESTADO_START_ADC:
    				//Genera señal de START para tomar dato ADC/
    				ADC16_SetChannelConfig(ADC0_PERIPHERAL, ADC0_CH0_CONTROL_GROUP, &ADC0_channelsConfig[0]);
    				fst_estado_actual=FSM_ESTADO_ESPERA_TIEMPO_RESULTADO;
    				break;

    			case FSM_ESTADO_ESPERA_TIEMPO_RESULTADO:
    				if (0U== (kADC16_ChannelConversionDoneFlag& ADC16_GetChannelStatusFlags(ADC0_PERIPHERAL,ADC0_CH0_CONTROL_GROUP))) {
    					//No ha terminado de realizar la operacion del ADC
    				} else {
    					fst_estado_actual=FSM_ESTADO_CAPTURA_RESULTADO_ADC;
    				}
    				break;

    			case FSM_ESTADO_CAPTURA_RESULTADO_ADC:
    				// captura el dato adc en una variable
    				datos_locales.data_sensor_luz_adc = ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, ADC0_CH0_CONTROL_GROUP);
    				fst_estado_actual=FSM_ESTADO_CAPTURA_IMPRIME_RESULTADO_ADC;
    				break;

    			case FSM_ESTADO_CAPTURA_IMPRIME_RESULTADO_ADC:
    				//imprime el dato adc
    				PRINTF("data_sensor_luz_adc: %d\r\n",datos_locales.data_sensor_luz_adc);
    				fst_estado_actual=FSM_ESTADO_INICIO;
    				break;

    			default:	//estado ilegal
    				fst_estado_actual=FSM_ESTADO_INICIO;
    				break;

        }

        __asm volatile ("nop");
    }
    return 0 ;
}
