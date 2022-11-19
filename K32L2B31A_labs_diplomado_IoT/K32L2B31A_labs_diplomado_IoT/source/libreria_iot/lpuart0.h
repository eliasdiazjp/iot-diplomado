/*! @file : lpuart0.h
 * @author  Elias Jesus Diaz P
 * @version 1.0.0
 * @date    12/11/2022
 * @brief   Driver para 
 * @details
 *
 */
#ifndef LIBRERIA_IOT_LPUART0_H_
#define LIBRERIA_IOT_LPUART0_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_common.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include "fsl_device_registers.h"
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
uint8_t leer_dato(void);
uint8_t leer_bandera_nuevo_dato(void);
uint8_t anailiza_buffer(void);
void  escribir_bandera_nuevo_dato(uint8_t nuevo_valor);

#endif
