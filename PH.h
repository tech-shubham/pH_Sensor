/***************************************************************************
*
*
* PH.h
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#ifndef __PH_HEADER_H__
#define __PH_HEADER_H__
#include "adc.h"


//////////////////////////////////////PH Sensors ////////////////////////////////
int buf[10],temp;
unsigned long int avgValue;
void AB_STEM_init_PH(void);
int AB_STEM_read_PH(unsigned int ADC_PIN);









#endif //__PH_HEADER_H__