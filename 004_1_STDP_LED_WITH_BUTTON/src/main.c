
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIOInitStruct;
int counter;
void GPIO_Config(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);

	GPIOInitStruct.GPIO_Pin=GPIO_Pin_1;
	GPIOInitStruct.GPIO_Mode=GPIO_Mode_IN;
	GPIOInitStruct.GPIO_OType=GPIO_OType_PP;
	GPIOInitStruct.GPIO_PuPd=GPIO_PuPd_DOWN;
	GPIOInitStruct.GPIO_Speed=GPIO_Speed_100MHz;

	GPIO_Init(GPIOB,&GPIOInitStruct);

		GPIOInitStruct.GPIO_Pin=GPIO_Pin_12;
		GPIOInitStruct.GPIO_Mode=GPIO_Mode_OUT;
		GPIOInitStruct.GPIO_OType=GPIO_OType_PP;
		GPIOInitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
		GPIOInitStruct.GPIO_Speed=GPIO_Speed_100MHz;

		GPIO_Init(GPIOD,&GPIOInitStruct);


}

void delay(uint32_t time){
	while(time--);
}
int main(void)
{

	GPIO_Config();

  while (1)
  {
	  if ( GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) ){
		  while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) );
		  delay(336000);
		  counter++;
		  if(counter==1){
			  GPIO_SetBits(GPIOD,GPIO_Pin_12);
		  }
		  else if(counter==2){
		  			  GPIO_SetBits(GPIOD,GPIO_Pin_13);
		  		  }
		  else if(counter==3){
		  			  GPIO_SetBits(GPIOD,GPIO_Pin_14);
		  		  }
		  else{
			  counter=0;
			  GPIO_ResetBits(GPIOD,GPIO_Pin_12);
			  delay(168000);
			  GPIO_ResetBits(GPIOD,GPIO_Pin_13);
	          delay(168000);
		      GPIO_ResetBits(GPIOD,GPIO_Pin_14);

		  }
	  }
  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){

  return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void){

  return -1;
}
