#include "stm32f4xx.h"                  // Device header

// Toggling led at 1 Hz using TIM2 Compare mode.
int main(void)
{
	RCC->AHB1ENR |=1;
	GPIOA->MODER |= 0x800; // SET PA5 to Alternate function
	GPIOA->AFR[0] |= 0x00100000; // Set pin AF1 for TIM2 CH1
	
	RCC->APB1ENR |=1;
	TIM2->PSC = 1600-1;
	TIM2->ARR = 10000-1;
	TIM2->CCMR1 = 0x30; 			//Setting output to toggle
	TIM2->CCR1 =0;						//Setting matchmode
	TIM2->CCER |=1; 					//Enable channel 1 compare mode
	
	TIM2->CNT = 0;						//Clear counter
	TIM2->CR1 = 1;						//Enable TIM2
	
	while(1){
	}
	
	
	
	
	
	
}
