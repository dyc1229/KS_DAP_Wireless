#include "bsp_button.h"
#include "gpio.h"
#include "oled.h"
#include "include.h"
/*******************************************************************
 *                          ��������                               
 *******************************************************************/
#if 1

Button_t Button1;
Button_t Button2;
Button_t Button3;
uint8_t button_num = 0;
//����һ����
void Btn1_Down_CallBack(void *btn)
{
	button_num = 1;
	//	OLED_ShowString(0, 40, "anxia1", 12, 1);
}
//����һ˫��
void Btn1_Double_CallBack(void *btn)
{
}

void Btn1_Long_CallBack(void *btn)
{
	if (Show.mode == MODE_SET_ONLINE)
	{
		__set_FAULTMASK(1); //�ر������ж�
		NVIC_SystemReset(); //ϵͳ��λ
	}
	Show.windows = SHOW_MENU;
	Show.mode = MODE_SET_NORMAL;
}
void Btn1_Long_Free_CallBack(void *btn)
{
}
void Btn1_Continuos_CallBack(void *btn)
{
	//   printf("Button1 ����!");
}

void Btn1_ContinuosFree_CallBack(void *btn)
{
	//   printf("Button1 �����ͷ�!");
}

void Btn2_Down_CallBack(void *btn)
{
	button_num = 2;
	//	OLED_ShowString(0, 40, "anxia2", 12, 1);
}

void Btn2_Double_CallBack(void *btn)
{
	
}

void Btn2_Long_CallBack(void *btn)
{
	button_num = 9;
}
void Btn2_Long_Free_CallBack(void *btn)
{
}
void Btn2_Continuos_CallBack(void *btn)
{
	//   printf("Button2 ����!");
}
void Btn2_ContinuosFree_CallBack(void *btn)
{
	//   printf("Button2 �����ͷ�!");
}
void Btn3_Down_CallBack(void *btn)
{
	button_num = 3;
	//	OLED_ShowString(0, 40, "anxia3", 12, 1);
}

void Btn3_Double_CallBack(void *btn)
{
}

void Btn3_Long_CallBack(void *btn)
{

		__set_FAULTMASK(1); //�ر������ж�
		NVIC_SystemReset(); //ϵͳ��λ

}
void Btn3_Long_Free_CallBack(void *btn)
{
}
void Btn3_Continuos_CallBack(void *btn)
{
	//   printf("Button2 ����!");
}
void Btn3_ContinuosFree_CallBack(void *btn)
{
	//   printf("Button2 �����ͷ�!");
}
uint8_t Read_KEY1_Level(void)
{
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
}

uint8_t Read_KEY2_Level(void)
{
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7);
}
uint8_t Read_KEY3_Level(void)
{
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
}
void Button_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	Button_Create("Button1",
				  &Button1,
				  Read_KEY1_Level,
				  KEY_OFF);
	Button_Attach(&Button1, BUTTON_DOWN, Btn1_Down_CallBack);			//����
	Button_Attach(&Button1, BUTTON_DOUBLE, Btn1_Double_CallBack);		//˫��
	Button_Attach(&Button1, BUTTON_LONG, Btn1_Long_CallBack);			//��������
	Button_Attach(&Button1, BUTTON_LONG_FREE, Btn1_Long_Free_CallBack); //�����ɿ�
	Button_Create("Button2",
				  &Button2,
				  Read_KEY2_Level,
				  KEY_OFF);
	Button_Attach(&Button2, BUTTON_DOWN, Btn2_Down_CallBack);			//����
	Button_Attach(&Button2, BUTTON_DOUBLE, Btn2_Double_CallBack);		//˫��
	Button_Attach(&Button2, BUTTON_LONG, Btn2_Long_CallBack);			//����
	Button_Attach(&Button2, BUTTON_LONG_FREE, Btn2_Long_Free_CallBack); //����
	Button_Create("Button3",
				  &Button3,
				  Read_KEY3_Level,
				  KEY_OFF);
	Button_Attach(&Button3, BUTTON_DOWN, Btn3_Down_CallBack);			//����
	Button_Attach(&Button3, BUTTON_DOUBLE, Btn3_Double_CallBack);		//˫��
	Button_Attach(&Button3, BUTTON_LONG, Btn3_Long_CallBack);			//����
	Button_Attach(&Button3, BUTTON_LONG_FREE, Btn3_Long_Free_CallBack); //����
	Get_Button_Event(&Button1);
	Get_Button_Event(&Button2);
	Get_Button_Event(&Button3);
}

#endif