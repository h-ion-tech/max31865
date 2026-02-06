#ifndef _MAX31865_H
#define _MAX31865_H

/*
  Author:     Nima Askari
  WebSite:    http://www.github.com/NimaLTD
  Instagram:  http://instagram.com/github.NimaLTD
  Youtube:    https://www.youtube.com/channel/UCUhY7qY1klJm1d2kulr9ckw

  Version:    1.0.0


  Reversion History:

  (1.0.0)
  First Release.

*/

#ifdef __cplusplus
 extern "C" {
#endif

#include "gpio.h"
#include "spi.h"
#include <stdbool.h>
//#########################################################################################################################
typedef struct
{
  GPIO_TypeDef      *cs_gpio;
  uint16_t          cs_pin;
  SPI_HandleTypeDef *spi;
  uint8_t           lock;

}Max31865_t;
//#########################################################################################################################
void  Max31865_init(Max31865_t *max31865,SPI_HandleTypeDef *spi,GPIO_TypeDef  *cs_gpio,uint16_t cs_pin,uint8_t  numwires, uint8_t filterHz);
bool  Max31865_readRes(Max31865_t *max31865,float *readRes);
bool  Max31865_readTempC(Max31865_t *max31865,float *readTemp);
bool  Max31865_readTempF(Max31865_t *max31865,float *readTemp);
float Max31865_Filter(float	newInput, float	lastOutput, float efectiveFactor);

uint8_t  Max31865_readFault(Max31865_t *max31865);
void     Max31865_clearFault(Max31865_t *max31865);
void     Max31865_enableBias(Max31865_t *max31865, uint8_t enable);

void Max31865_SEQ1_ClearFaultEnBias (Max31865_t *max31865);
void Max31865_SEQ2_ConfigOneShotMeasure (Max31865_t *max31865);
uint16_t Max31865_SEQ3_ReadRawValue (Max31865_t *max31865);

bool Max31865_setHighFaultThreshold(Max31865_t *max31865, float highTempC);
bool Max31865_setLowFaultThreshold(Max31865_t *max31865, float lowTempC);

//#########################################################################################################################
#ifdef __cplusplus
}
#endif



#endif
