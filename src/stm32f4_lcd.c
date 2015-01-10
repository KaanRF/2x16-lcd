/*
 * stm32f4_lcd.c
 *
 *  Created on: Feb 26, 2013
 *      Author: Kaan
 */


#include "stm32f4xx.h"
#include "stm32f4_lcd.h"
#include "delay.h"

void lcd_init(void)
{

    GPIOD->MODER = 0x55005555;     // GPIOD nin 15, 14, 13, 12 pinleri cikis tanimlandi (LEDler icin) 0..7 arasýda çýkýþ
    GPIOB->MODER = 0x00000503;     // GPIOB 4 ve 5 i çýkýþ yaptýk.	 +B0 analog

   // GPIOA->OSPEEDR= 0x00000000;   // GPIOD nin tum cikislariný Max. 2 Mhz de kullanacaðýz.
    GPIOB->OSPEEDR= 0xFFFFFFFF;	  // AYný þey GPIOB içinde geçerli

    GPIO_B(4)=0;/*RS pin */  	GPIO_B(5)=0;  /*enable bit*/  //	 Genel
    GPIOD->ODR= 0x00000000;		  //	 Temizlik

    delay_ms(20);

    lcd_veri(0x30); // Lcd Reset
    lcd_temizle();
    lcd_veri(56);   // 2 satýr kullanacaðýmýzý yazdýk
    lcd_veri(15);   // Display i aç
    lcd_veri(0x06); // Kursör 1 artan modda.
    lcd_temizle();	    // Lcd yi temizle

}

void lcd_veri(unsigned char veri)
{
 	GPIO_B(4)=0;  delay_ms(10);
    GPIOD->ODR = veri;
    GPIO_B(5)=1;  delay_ms(10);  GPIO_B(5)=0;
}

void lcd_goto(unsigned char p1,unsigned char p2)
{
    if (p1==1) lcd_veri(0x80+(p2-1));
    else      lcd_veri(0xC0+(p2-1));
}

void lcd_puts(unsigned char *lcd_data)
{
    delay_ms(10);
    while(*lcd_data)  Yaz(*lcd_data++);
}

void Yaz(unsigned dat)
{
 	GPIO_B(4)=1;  delay_ms(10);
    GPIOD->ODR = dat;
    GPIO_B(5)=1;  delay_ms(10);  GPIO_B(5)=0;
}

void lcd_temizle(void)
{
    lcd_veri(1);
    delay_ms(10);
}

void lcd_imlec_yok(void)
{
    lcd_veri(0x0C);
    delay_ms(10);
}

void lcd_imlec_var(void)
{
 	lcd_veri(0x0F);
    delay_ms(10);
}
