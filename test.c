#include "stm32f10x.h"                  // Device header
#include "test.h"
#include "stdio.h"
#include "Delay.h"
#include "myrtc.h"


void LED_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_4| GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA , &GPIO_InitStruct);
			
}

void GREEN_LED_flicker(void){
				if(MyRTC_Time[4] == 30){
					GPIO_SetBits(GPIOA,GPIO_Pin_3);
				}else if(MyRTC_Time[4] == 31){
					GPIO_ResetBits(GPIOA,GPIO_Pin_3);
				}
								
}

void RED_LED_flicker(void){
				
	GPIO_SetBits(GPIOA,GPIO_Pin_4);

				
}

void BLUE_LED_flicker(void){
				
	GPIO_SetBits(GPIOA,GPIO_Pin_5);
	Delay_ms(100);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	Delay_ms(100);
	GPIO_SetBits(GPIOA,GPIO_Pin_5);
	Delay_ms(100);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);				
}
