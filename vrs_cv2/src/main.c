/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 6.0.0   2016-10-04

The MIT License (MIT)
Copyright (c) 2009-2016 Atollic AB

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************
*/

/* Includes */
#include <stddef.h>
#include "stm32l1xx.h"


/* Private typedef */
/* Private define  */
/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */
int getValue(uint16_t button);

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  int i = 0;
  int button = 0;
  int k = 0;
  int p = 0;
  int button1 = 0;
  int counter = 0;
  int tmp1 = 0;
  int tmp2 = 0;
  int tmp3 = 0;

  /**
  *  IMPORTANT NOTE!
  *  See the <system_*.c> file and how/if the SystemInit() function updates 
  *  SCB->VTOR register. Sometimes the symbol VECT_TAB_SRAM needs to be defined 
  *  when building the project if code has been located to RAM and interrupts 
  *  are used. Otherwise the interrupt table located in flash will be used.
  *  E.g.  SCB->VTOR = 0x20000000;  
  */

  /**
  *  At this stage the microcontroller clock setting is already configured,
  *  this is done through SystemInit() function which is called from startup
  *  file (startup_stm32l1xx_hd.s) before to branch to application main.
  *  To reconfigure the default setting of SystemInit() function, refer to
  *  system_stm32l1xx.c file
  */

  /* TODO - Add your application code here */


  //Uloha 1
  /*
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);  //zapnutie periferie GPIOA

  GPIOA->MODER |= (uint32_t)((0b01)<<(5*2));	//nastavenie hodnoty inputu na dany pin
  GPIOA->OTYPER &= ~((0b1)<<5);
  GPIOA->PUPDR |= (uint32_t)((0b01)<<(5*2));	//nastavenie pull up pull down na poz�ciu 10 (0b10)
  GPIOA->OSPEEDR |= (uint32_t)((0b11)<<(5*2));

  GPIOA->ODR |= 0b0000000000100000;
*/
  //Uloha 2

  	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);

      GPIOA->MODER |= (uint32_t)((0b01)<<(5*2));
      GPIOA->OTYPER &= ~((0b1)<<5);
      GPIOA->PUPDR |= (uint32_t)((0b01)<<(5*2));
      GPIOA->OSPEEDR |= (uint32_t)((0b11)<<(5*2));

      GPIOC->MODER &= ~((0b11)<<(13*2));
      GPIOC->OTYPER &= ~((0b1)<<13);
      GPIOC->PUPDR &= ~((0b11)<<(13*2));

  //Uloha 3
  /*
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);

      GPIOA->MODER |= (uint32_t)((0b01)<<(5*2));
      GPIOA->OTYPER &= ~((0b1)<<5);
      GPIOA->PUPDR |= (uint32_t)((0b01)<<(5*2));
      GPIOA->OSPEEDR |= (uint32_t)((0b11)<<(5*2));


      GPIOC->MODER &= ~((0b11)<<(13*2));
      GPIOC->OTYPER &= ~((0b1)<<13);
      GPIOC->PUPDR &= ~((0b11)<<(13*2));
     /*
  /* Infinite loop */
  while (1)
  {
	  /*
	  GPIOA->ODR |= (uint16_t)(1 << 5); //zapina
	  GPIOA->ODR &= ~(uint16_t)(1 << 5); //vypina

	  GPIOA->BSRRL |= ((uint16_t)(1<<5));
	  GPIOA->BSRRL &= ~((uint16_t)(1<<5));

	  GPIOA->BSRRH |= ((uint16_t)(1<<5));
	  GPIOA->BSRRH &= ~((uint16_t)(1<<5));
	  */

	  //Uloha 2
/*
	  button=getValue(GPIOC->IDR);
	  if(button==1){
		  GPIOA->ODR |=(uint16_t)(0b1<<5);
	  }	else {
		  GPIOA->ODR &=~((uint16_t)(0b1<<5));
	  }

	  //Uloha3 1
/*
	  k=0;
	  p=0;

	  GPIOA->ODR|=(uint16_t)((0b1)<<5);
	  for(k;k < 999999;k++)
	  {
	  }
	  GPIOA->ODR&= ~((uint16_t)((0b1)<<5));
	  for(p;p < 999999 ;p++)
	  {

	  }
*/
	  //Uloha3 2
/*
	  button=getValue(GPIOC->IDR);
	  if(button==1){
		  GPIOA->ODR |=(uint16_t)(0b1<<5);
	  }	else {
		  GPIOA->ODR &=~((uint16_t)(0b1<<5));
	  }
*/

	  //Uloha3 3

	  button1=getValue(GPIOC->IDR);
	  	if (button1 == 1)
	  	{
	  		while(counter < 6)
	  		{
	  			counter++; //5 "impulzov"
	  		}
	  		counter = 0;
	  	}
	  	button1=getValue(GPIOC->IDR);
	  	if (button1 == 0)
	  		{
	  			while(counter < 6)
	  			{
	  				counter++; //5 "impulzov"
	  			}
	  			counter = 0;
	  		}
	  	button1=getValue(GPIOC->IDR);
	  	if (button1 == 1)
	  		{
	  			while(counter < 6)
	  			{
	  				counter++; //5 "impulzov"

	  			}
	  			counter = 0;
	  			if(tmp1 == 0)
	  			{
	  				GPIOA->ODR |=(uint16_t)(0b1<<5);
	  				tmp1 = 1;
	  			}
	  			else if(tmp1 == 1)
	  			{
	  				GPIOA->ODR &= ~(uint16_t)(0b1<<5);
	  				tmp1 = 0;
	  			}
	  		}

	i++;

  }
  return 0;
}

int getValue(uint16_t button) // sleduj bit ci 0 alebo 1
{
	if(((button>>13)& 0b01)==1)
		return 0;
	else
		return 1;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*
 * Minimal __assert_func used by the assert() macro
 * */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
  while(1)
  {}
}

/*
 * Minimal __assert() uses __assert__func()
 * */
void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}
