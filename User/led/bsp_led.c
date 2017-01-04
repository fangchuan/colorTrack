#include "bsp_led.h"   


static void LED_GPIO_Config(void)
{				
	GPIO_InitTypeDef GPIO_InitStructure;              		//����һ��GPIO_InitTypeDef���͵Ľṹ																	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOF, ENABLE); //����GPIOB��GPIOF������ʱ��  
															//Ӳ���ӷ�:led1-PB1��led2-PF7��led3-PF8																										
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;     	//��������ģʽΪͨ���������	 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     	//������������Ϊ50MHz   
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;	          	//ѡ��Ҫ���Ƶ�GPIOB����			  
	GPIO_Init(GPIOB, &GPIO_InitStructure);	              	//���ÿ⺯������ʼ��GPIOB0
																		 
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7|GPIO_Pin_8;	//ѡ��Ҫ���Ƶ�GPIOF����		
	GPIO_Init(GPIOF, &GPIO_InitStructure);                	//������ͬ��IO��  ���õĿ⺯��Ҳ��ͬ 		
					
	GPIO_SetBits(GPIOB, GPIO_Pin_0);                      
	GPIO_SetBits(GPIOF, GPIO_Pin_7|GPIO_Pin_8);	          	//�ر�����led
}


void LED_GPIO_Init(void)
{
	LED_GPIO_Config();
}