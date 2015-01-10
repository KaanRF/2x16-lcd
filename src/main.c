#include "stm32f4xx.h"
#include "delay.h"
#include "stm32f4_lcd.h"

void SystemInit()
{
	 unsigned int i;

	     for (i=0;i<0x00100000;i++);          // OSC oturtma ve kurtarma  rutini
	    RCC->CFGR |= 0x00009400;         // AHB ve APB hizlarini max degerlere set edelim
	    RCC->CR |= 0x00010000;            // HSE Xtal osc calismaya baslasin
	    while (!(RCC->CR & 0x00020000));// Xtal osc stabil hale gelsin
	    RCC->PLLCFGR = 0x07405408;      // PLL katsayilarini M=8, N=336, P=2 ve Q=7 yapalim
	    RCC->CR |= 0x01000000;            // PLL calismaya baslasin
	    while(!(RCC->CR & 0x02000000)); // Pll hazir oluncaya kadar bekle
	    FLASH->ACR = 0x00000605;        // Flash ROM icin 5 Wait state secelim ve ART yi aktif edelim
	    RCC->CFGR |= 0x00000002;        // Sistem Clk u PLL uzerinden besleyelim
	    while ((RCC->CFGR & 0x0000000F) != 0x0000000A); // Besleninceye kadar bekle

	    RCC->AHB1ENR  |= 0x0000001F;           // GPIO A,B,C,D.E clock'u aktif edelim
		RCC->APB1ENR  |= 0x00000002;           // Timer3 CLK'u aktif edelim (84 Mhz)
	    RCC->APB2ENR  |= 0x00000101; 			 //Timer1 CLK etkin (168MHz)

	    GPIOD->MODER   = 0x55000000;         // GPIOD nin 15, 14, 13, 12 pinleri cikis tanimlandi (LEDler icin)
	    //GPIOD->OSPEEDR = 0xFFFFFFFF;         // GPIOD nin tum cikislari en yuksek hizda kullanacagiz
	    GPIOD->OSPEEDR = 0x00000000;      //*** logýc analyzer test ýcýn cýkýslar 2mhz alýndý****//

		GPIOE->MODER   = 0x86668000;         // E7,8,10,12,15 AF, 9,11,13 çýkýþ
		//GPIOE->OSPEEDR = 0xFFFFFFFF;          // E portu hýzý 100 MHz
		GPIOE->OSPEEDR = 0x00000000;     //*** logýc analyzer test ýcýn cýkýslar 2mhz alýndý****//

		GPIOE->AFR[1]  = 0x00010101;		  // E8,10,12 AF1 seçildi

	    GPIOC->MODER   = 0x00000000;		  //C0+C1+C2 giriþ
	    //GPIOC->OSPEEDR = 0xFFFFFFFF;		 // C portu   en yüksek hýzda
	    GPIOC->OSPEEDR = 0x00000000;      //*** logýc analyzer test ýcýn cýkýslar 2mhz alýndý****//
}

int main()
{
	lcd_init();
	lcd_temizle();
	lcd_imlec_yok();
	delay_ms(128);
	while(1)
	{
		lcd_goto(1,1);
		lcd_puts("stm32f4 discovery");
		lcd_goto(2,1);
		lcd_puts("2x16-LCD");
	}
}
