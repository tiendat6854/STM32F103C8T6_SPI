#include "stm32f10x.h"                  // Device header
#include"timer2.h"
#include"spi.h"

void GPIO_Init_PC13(void)
{
  RCC->APB2ENR |= (1 << 4);
	GPIOC->CRH &= ~(15 << 20);
	GPIOC->CRH |= (3 << 20);
}

void delay_ms(uint32_t t)
{
  while(t)
	{
	  TIM2->CNT = 0; 
		while(TIM2->CNT < 1000) {}
	  --t;
	}
}

int main()
{
  GPIO_Init_PC13();
	timer2_Init();
	SPI2_Init();
	SPI_Write(pu8Data, u32Len);
	
	while(1)
	{
		GPIOB->ODR &= ~(1 << 12);
		SPI_Write(u8Buff, sizeof(u8Buff));
		GPIOB->ODR |= (1 << 12);
		
	  GPIOC->ODR |= (1 << 13);
		delay_ms(500);
		GPIOC->ODR &= ~(1 << 13);
		delay_ms(500);
	}
}
