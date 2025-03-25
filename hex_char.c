#include "stm32f10x.h"                  // Device header

char hex_to_char(uint16_t hex1)
{
	char char1;
		switch(hex1)
			{
			//0-10
			case 0x30:
			  char1='0';
				break;
			case 0x31:
			  char1='1';
				break;
			case 0x32:
			  char1='2';
				break;
			case 0x33:
			  char1='3';
				break;
			case 0x34:
			 char1='4';
				break;
			case 0x35:
			  char1='5';
				break;
			case 0x36:
			  char1='6';
				break;
			case 0x37:
			  char1='7';
				break;
			case 0x38:
			  char1='8';
				break;
			case 0x39:
			  char1='9';
				break;
			
			//A-Z
			case 0x41:
			  char1='A';
				break;
			case 0x42:
			  char1='B';
				break;
			case 0x43:
			  char1='C';
				break;
			case 0x44:
			  char1='D';
				break;
			case 0x45:
			  char1='E';
				break;
			case 0x46:
			  char1='F';
				break;	
			case 0x47:
			  char1='G';
				break;
			case 0x48:
			  char1='H';
				break;
			case 0x49:
			  char1='I';
				break;
			case 0x4A:
			  char1='J';
				break;
			case 0x4B:
			  char1='K';
				break;
			case 0x4C:
			  char1='L';
				break;
			case 0x4D:
			  char1='M';
				break;
			case 0x4E:
			  char1='N';
				break;
			case 0x4F:
			  char1='O';
				break;				
			case 0x50:
			  char1='P';
				break;
			case 0x51:
			  char1='Q';
				break;
			case 0x52:
			  char1='R';
				break;				
			case 0x53:
			  char1='S';
				break;
			case 0x54:
			  char1='T';
				break;
			case 0x55:
			  char1='U';
				break;
			case 0x56:
			  char1='V';
				break;
			case 0x57:
			  char1='W';
				break;
			case 0x58:
			  char1='X';
				break;	
			case 0x59:
			  char1='Y';
				break;
			case 0x5A:
			  char1='Z';
				break;	
			
			//字符
			case 0x2C:
			  char1=',';
				break;	
			case 0x2E:
			  char1='.';
				break;				
			
			
			//其他情况
			default:
				return '?';
		}

   return char1;
}
