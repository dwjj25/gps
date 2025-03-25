#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "hex_char.h"
#include "MyRTC.h"
#include "time.h"

//��hex����ת������������
int char_to_int(char string)
{
	u8 x;
		switch(string)
			{
			//0-10
			case '0':
			  x=0;
				break;	
			case '1':
			  x=1;
				break;				
			case '2':
			  x=2;
				break;	
			case '3':
			  x=3;
				break;	
			case '4':
			  x=4;
				break;	
			case '5':
			  x=5;
				break;				
			case '6':
			  x=6;
				break;	
			case '7':
			  x=7;
				break;	
			case '8':
			  x=8;
				break;	
			case '9':
			  x=9;
				break;				
		}
   return x;
}

//���ֽ���
void show_line(void)
{		
	//����
	OLED_ShowString(1, 5, "|");		
	OLED_ShowString(2, 5, "|");
	OLED_ShowString(3, 5, "|");
	OLED_ShowString(4, 5, "|");
	
	//����1
	OLED_ShowString(2, 1, "-");		
	OLED_ShowString(2, 2, "-");
	OLED_ShowString(2, 3, "-");
	OLED_ShowString(2, 4, "-");
	//��һ��	
	OLED_ShowString(2, 6, "-");
	OLED_ShowString(2, 7, "-");
	OLED_ShowString(2, 8, "-");	
	OLED_ShowString(2, 9, "-");		
	OLED_ShowString(2, 10, "-");	
	OLED_ShowString(2, 11, "-");
	OLED_ShowString(2, 12, "-");
	OLED_ShowString(2, 13, "-");
	OLED_ShowString(2, 14, "-");
	OLED_ShowString(2, 15, "-");
	OLED_ShowString(2, 16, "-");
	
	//����2
	OLED_ShowString(3, 1, "-");		
	OLED_ShowString(3, 2, "-");
	OLED_ShowString(3, 3, "-");
	OLED_ShowString(3, 4, "-");	
	OLED_ShowString(3, 4, "-");
	//��һ��
	OLED_ShowString(3, 6, "-");
	OLED_ShowString(3, 7, "-");
	OLED_ShowString(3, 8, "-");	
	OLED_ShowString(3, 9, "-");		
	OLED_ShowString(3, 10, "-");		
	OLED_ShowString(3, 11, "-");
	OLED_ShowString(3, 12, "-");
	OLED_ShowString(3, 13, "-");
	OLED_ShowString(3, 14, "-");
	OLED_ShowString(3, 15, "-");
	OLED_ShowString(3, 16, "-");
}

/////////////////////////����1�����ڣ�ʱ��/////////////////////////

//��ʾ����	
void show_date(u8 hex_num)
{
	//date
	OLED_ShowString(1, 1, "data");
	
	OLED_ShowChar(1, 7, hex_to_char(Serial_RxPacket[hex_num+5]));
	OLED_ShowChar(1, 8, hex_to_char(Serial_RxPacket[hex_num+6]));
		
	OLED_ShowString(1, 9, ".");
		
	OLED_ShowChar(1, 10, hex_to_char(Serial_RxPacket[hex_num+3]));	
	OLED_ShowChar(1, 11, hex_to_char(Serial_RxPacket[hex_num+4]));
		
	OLED_ShowString(1, 12, ".");	
		
	OLED_ShowChar(1, 13, hex_to_char(Serial_RxPacket[hex_num+1]));
	OLED_ShowChar(1, 14, hex_to_char(Serial_RxPacket[hex_num+2]));
}

//����Сʱ��ʵ��ʱ��
int int_int(int hex_num)
{
	u8 x1,x2,x3;
	x1 = char_to_int(hex_to_char(Serial_RxPacket[hex_num+1]));
	x2 = char_to_int(hex_to_char(Serial_RxPacket[hex_num+2]));
	x3 = x1*10+x2+8;
	if(x3 == 24)
	{
		x3 = 00;
	}
	if(x3 > 24)
	{
		x3 = x3-24;
	}
	
	return x3;
}

//��ʾʱ��
void show_time(u8 hex_num)
{
	//time
	OLED_ShowString(4, 1, "time");
		
	OLED_ShowNum(4, 7, int_int(hex_num), 2);
	
	OLED_ShowString(4, 9, ":");
			
	OLED_ShowChar(4, 10, hex_to_char(Serial_RxPacket[hex_num+3]));
	OLED_ShowChar(4, 11, hex_to_char(Serial_RxPacket[hex_num+4]));
			
	OLED_ShowString(4, 12, ":");
			
	OLED_ShowChar(4, 13, hex_to_char(Serial_RxPacket[hex_num+5]));
	OLED_ShowChar(4, 14, hex_to_char(Serial_RxPacket[hex_num+6]));	

}




/////////////////////////����2��γ�ȣ�����/////////////////////////



//γ��
void show_N(u8 hex_num)
{	
	OLED_ShowString(1, 1, " N  ");
	u32 x = 0;
	u32 x1 = 0;
	//����
	x = x+char_to_int(hex_to_char(Serial_RxPacket[hex_num+1]))*1000000;
	x = x+char_to_int(hex_to_char(Serial_RxPacket[hex_num+2]))*100000;
	
	//С��
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+3]))*1000000;
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+4]))*100000;
	//��һ����
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+6]))*10000;
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+7]))*1000;
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+8]))*100;
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+9]))*10;	
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+10]));	
	
	//γ�Ȼ��㣺ddmm.mmmm ��γ 2236.9453 
	//22+(36.9453/60)= 22.615755
	x = x+x1/60;
	
	//����
	u8 x2 = (x-x%100000)/100000;
	//С��
	u32 x3 = x%100000;
	
	//��Ļ��ʾ30.8212775?
	OLED_ShowNum(1, 7, x2, 3);
	OLED_ShowChar(1, 10, '.');
	OLED_ShowNum(1, 11, x3, 5);
}


//����
void show_E(u8 hex_num)
{
	OLED_ShowString(4, 1, " E  ");
	u32 x = 0;
	u32 x1 = 0;
	
	//����
	x = x+char_to_int(hex_to_char(Serial_RxPacket[hex_num+1]))*1000000000;
	x = x+char_to_int(hex_to_char(Serial_RxPacket[hex_num+2]))*100000000;
	x = x+char_to_int(hex_to_char(Serial_RxPacket[hex_num+3]))*10000000;
	//С��
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+4]))*1000000;
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+5]))*100000;
	//��һ����
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+7]))*10000;
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+8]))*1000;
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+9]))*100;	
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+10]))*10;
	x1 = x1+char_to_int(hex_to_char(Serial_RxPacket[hex_num+11]));	
	
	//���Ȼ��㣺dddmm.mmmm ���� 11408.4790 
	//114+(08.4790/60)=114.141317 
	x = x+x1/60;
	
	//����
	u8 x2 = x/10000000;
	//С��
	u32 x3 = x%100000;
	
	//11506.79764
	//��Ļ��ʾ115.113294
	
	OLED_ShowNum(4, 7, x2, 3);
	OLED_ShowChar(4, 10, '.');
	OLED_ShowNum(4, 11, x3, 5);	
}

/////////////////////////���ݷָ�/////////////////////////
//��ʾ���ڣ�ʱ��
void show_time_date(void)
{	
	u8 hex_num;
	u8 i = 0;
	for(hex_num = 0;hex_num <= 67;hex_num++)
	{
		if(Serial_RxPacket[hex_num] == 0x2C)
		{
			i++;
			if(i == 1)
			{
				OLED_ShowChar(4, 15, ' ');
				show_time(hex_num);
			}			
			if(i == 9)
			{
				OLED_ShowChar(1, 15, ' ');
				show_date(hex_num);
			}
		}
	}
}




//��ʾγ�ȣ�����
void show_N_E(void)
{
	u8 hex_num;
	u8 i = 0;
	for(hex_num = 0;hex_num <= 67;hex_num++)
	{
		if(Serial_RxPacket[hex_num] == 0x2C)
		{
			i++;
			if(i == 3)
			{
				show_N(hex_num);
			}			
			if(i == 5)
			{
				show_E(hex_num);
			}
		}
	}	
}
