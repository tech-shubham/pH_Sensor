/***************************************************************************
*
*
* PH.c
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#include "PH.h"


//////////////////////////////////////PH Sensors //////////////////////////////// 
void AB_STEM_init_PH()
{
		enableADC();
}

int AB_STEM_read_PH(unsigned int ADC_PIN)	//A0, A1, A2 and A3
{	
	for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
	{ 
		buf[i]=readAnalogValue(ADC_PIN, AB_INTERNAL);
		_delay_ms(10);
	}
	for(int i=0;i<9;i++)        //sort the analog from small to large
	{
		for(int j=i+1;j<10;j++)
		{
			if(buf[i]>buf[j])
			{
				temp=buf[i];
				buf[i]=buf[j];
				buf[j]=temp;
			}
		}
	}
	avgValue=0;
	for(int i=2;i<8;i++)                      //take the average value of 6 center sample
		avgValue+=buf[i];
	float phValue=(float)(avgValue*5.0)/1024/6; //convert the analog into millivolt
	phValue=3.5*phValue;
	
	return (phValue*100);
}		


int main()
{
	int phValue=0;
	AB_STEM_init_PH();
	
	while(1)
	{
		phValue=AB_STEM_read_PH(AB_CHANNEL_2);	///// Stores the pH value
	}

		return 0;
}