/*! @file : K32L2B31A_labs_diplomado_IoT.c
 * @author  Elias Jesus Diaz P
 * @version 1.0.0
 * @date    12/11/2022
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
 /*******************************************************************************
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

volatile uint32_t g_systickCounter;
volatile static int i = 0 ;

uint8_t dato_lpuart0;


extern uint8_t dato_lpuart0;
extern uint8_t flag_nuevo_dato_lpuart0;


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


        i++ ;
        if(leer_bandera_nuevo_dato()!=0){
        	PRINTF("Valor en ASCII : %d\r\n", leer_dato());
        	escribir_bandera_nuevo_dato(0);
        	if(leer_dato()==82){
        		/* R=82*/
        		led_on_red();
        	  	}
        	if(leer_dato()==114){
        		/* r=114*/
   	      		led_off_red();
           	  	}

        	if(leer_dato()==86){
        		/* V=86*/
  	       		led_on_green();
          	  	}
        	if(leer_dato()==118){
        		/* v=118*/
   	       		led_off_green();
           	  	}
        	if(leer_dato()==76){
        		/* L=76*/
        	PRINTF("lux: %f\r\n", Sens_dato());
        	   	}

        }

        __asm volatile ("nop");
    }
    return 0 ;
}
