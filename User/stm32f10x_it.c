#include "stm32f10x_it.h"
#include "bsp_ov7725.h"
#include "bsp_led.h" 
#include "EasyTracer.h"
#include "bsp_ili9341_lcd.h"


extern u8 Ov7725_vsync;


//===================================================================
//ov7725 ���ж� ������� 
//===================================================================
void EXTI0_IRQHandler(void)
{
    if ( EXTI_GetITStatus(EXTI_Line0) != RESET ) 	//���EXTI_Line0��·�ϵ��ж������Ƿ��͵���NVIC 
    {
		if( Ov7725_vsync == 0 )
		{
			FIFO_WRST_L(); 	                      	//����ʹFIFOд(����from����ͷ)ָ�븴λ
			FIFO_WE_H();	                     	//����ʹFIFOд����
			Ov7725_vsync = 1;	   	
			FIFO_WE_H();                          	//ʹFIFOд����
			FIFO_WRST_H();                        	//����ʹFIFOд(����from����ͷ)ָ���˶�
		}
		else if( Ov7725_vsync == 1 )
		{
			FIFO_WE_L();                          	//����ʹFIFOд��ͣ
			Ov7725_vsync = 2;
			FIFO_PREPARE;                         	//FIFO׼��		
			ImagDisp();					            //�ɼ�����ʾ   
			LED1_TOGGLE
		}        
		EXTI_ClearITPendingBit(EXTI_Line0);		    //���EXTI_Line0��·�����־λ        
    }    
}