/*! @file : leds.c
 * @author  Elias Jesus Diaz P
 * @version 1.0.0
 * @date    12/11/2022
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
* Includes
 **************************/
#include "leds.h"
#include "fsl_gpio.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
/***************************
 * Definitions
 **************************/


/***************************
 * Private Prototypes
 **************************/


/***************************
 * External vars
 **************************/


/***************************
 * Local vars
 **************************/


/***************************
 * Private Source Code
 **************************/


/***************************
 * Public Source Code
 **************************/
 
 void led_on_green(){
	 GPIO_PinWrite(GPIOD,5,0);

 }

 void led_off_green(){
 	 GPIO_PinWrite(GPIOD,5,1);

  }

 void led_on_red(){
 	 GPIO_PinWrite(GPIOE,31,0);

  }


 void led_off_red(){
  	 GPIO_PinWrite(GPIOE,31,1);

   }





 /*/salida de los leds /
 SysTick_DelayTicks(100U);
  GPIO_PortToggle(BOARD_LED_GPIO_1, 1u << BOARD_LED_GPIO_PIN_1);
  SysTick_DelayTicks(150U);
  GPIO_PortToggle(BOARD_LED_GPIO_2, 1u << BOARD_LED_GPIO_PIN_2);*/
