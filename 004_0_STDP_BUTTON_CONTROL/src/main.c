
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;

//Settings for button
void GPIO_Config(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //gp?oA databus enable

	//gp?oA settings
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_Pin= GPIO_Pin_0;
	GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_DOWN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_100MHz;

	GPIO_Init(GPIOA, &GPIO_InitStruct);

	   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //gp?oD databus enable

	    //gp?oD settings
		GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
		GPIO_InitStruct.GPIO_Pin= GPIO_Pin_12;
		GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
		GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
		GPIO_InitStruct.GPIO_Speed=GPIO_Speed_100MHz;

		GPIO_Init(GPIOD, &GPIO_InitStruct);


}

void delayy(uint32_t time){
	while(time--);

}
int main(void)
{
  while (1)
  {
	  if( GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) ){

		  while( GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) );

		  GPIO_SetBits(GPIOD,GPIO_Pin_12);

	  }


  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){

  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){

  return -1;
}
