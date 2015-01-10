/*
 * stm32f4_lcd.h
 *
 *  Created on: Feb 26, 2013
 *      Author: Kaan
 */

#ifndef STM32F4_LCD_H_
#define STM32F4_LCD_H_

#define GPIO_A(b) *((volatile unsigned long *)( 0x42000000 + (((unsigned long)&GPIOA->ODR) << 5) + ((b) << 2)))
#define GPIO_B(b) *((volatile unsigned long *)( 0x42000000 + (((unsigned long)&GPIOB->ODR) << 5) + ((b) << 2)))
#define GPIO_C(b) *((volatile unsigned long *)( 0x42000000 + (((unsigned long)&GPIOC->ODR) << 5) + ((b) << 2)))
#define GPIO_D(b) *((volatile unsigned long *)( 0x42000000 + (((unsigned long)&GPIOD->ODR) << 5) + ((b) << 2)))
#define GPIO_E(b) *((volatile unsigned long *)( 0x42000000 + (((unsigned long)&GPIOE->ODR) << 5) + ((b) << 2)))
#define GPIO_F(b) *((volatile unsigned long *)( 0x42000000 + (((unsigned long)&GPIOF->ODR) << 5) + ((b) << 2)))
#define GPIO_G(b) *((volatile unsigned long *)( 0x42000000 + (((unsigned long)&GPIOG->ODR) << 5) + ((b) << 2)))
#define GPIO_I(b) *((volatile unsigned long *)( 0x42000000 + (((unsigned long)&GPIOI->ODR) << 5) + ((b) << 2)))

extern void lcd_veri(unsigned char veri);
extern void lcd_goto(unsigned char p1,unsigned char p2);
extern void Yaz(unsigned dat);
extern void lcd_puts(unsigned char *lcd_data);
extern void lcd_temizle(void);
extern void lcd_imlec_var(void);
extern void lcd_imlec_yok(void);
extern void lcd_init(void);

#endif /* STM32F4_LCD_H_ */
