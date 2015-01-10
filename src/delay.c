/*
 * delay.c
 *
 *  Created on: Feb 26, 2013
 *      Author: Kaan
 */


#include "Delay.h"

void delay_ms(unsigned long Bekle)
{
    Bekle = Bekle * 21008;	// mSn ye ye çevirdik. OSC 168Mhz
    while(Bekle>0){Bekle--;}
}

void delay_us(unsigned long Bekle)
{
    Bekle = Bekle * 21;	// uSn ye ye çevirdik. OSC 168Mhz
    while(Bekle>0){Bekle--;}
}
