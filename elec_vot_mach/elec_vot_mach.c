/*
 * elec_vot_mach.c
 *
 * Created: 15/08/2023 02:48:24 م
 *  Author: handsa
 */ 


#include <avr/io.h>
#include "prog init.h"
int main(void)
{
  dio_set_port('c',0);
  lcd_init(); 
  unsigned short A=0;
    unsigned short B=0;
	  unsigned short C=0;
	    unsigned short D=0;
		char flag1 =0;
	char flag11 =0;
	char flag2 =0;
	char flag12 =0;
	char flag3 =0;
	char flag13 =0;
	char flag4 =0;
	char flag14 =0;
	char str[5];	
		/*lcd_send_string("x1=0");
				lcd_send_string("x2=0");
						lcd_send_string("x3=0");
								lcd_send_string("x4=0");*/
		
 lcd_send_cmd(disp_on_cursor_off);
    while(1)
    {
      if ((dio_read_pin('c',0)==1)&&(flag1==0))/* if button belongs to the candidate is pressed the result will be incremented by 1*/
      {
     A++;
	 flag1=1;
	  }
	  if ((dio_read_pin('c',0)==0)&&(flag1==1))
	  {
	 flag1=0;
	  }
     if ((dio_read_pin('c',1)==1)&&(flag11==0))/* if button belongs to the candidate is pressed the result will be decremented by 1*/
     {
	    if (A>0)
	    {
	   	 A--;
	    }
	
	     flag11=1;
     }
     if ((dio_read_pin('c',1)==0)&&(flag11==1))
     {
	     flag11=0;
     }
   
   /*-----------------------------------------------------*/
   if ((dio_read_pin('c',2)==1)&&(flag2==0))
   {
	   B++;
	   flag2=1;
   }
   if ((dio_read_pin('c',2)==0)&&(flag2==1))
   {
	   flag2=0;
   }
   if ((dio_read_pin('c',3)==1)&&(flag12==0))
   {
	   if (B>0)
	   {
			   B--; 
	   }
	
	   
	   flag12=1;
   }
   if ((dio_read_pin('c',3)==0)&&(flag12==1))
   {
	   flag12=0;
   }
     /*-----------------------------------------------------*/
	   if ((dio_read_pin('c',4)==1)&&(flag3==0))
	   {
		   C++;
		   flag3=1;
	   }
	   if ((dio_read_pin('c',4)==0)&&(flag3==1))
	   {
		   flag3=0;
	   }
	   if ((dio_read_pin('c',5)==1)&&(flag13==0))
	   {
		   if (C>0)
		   {
			   C--;
		   }
		   
		   
		   flag13=1;
	   }
	   if ((dio_read_pin('c',5)==0)&&(flag13==1))
	   {
		   flag13=0;
	   }
	/*--------------------------------------------*/
	if ((dio_read_pin('c',6)==1)&&(flag4==0))
	{
		D++;
		flag4=1;
	}
	if ((dio_read_pin('c',6)==0)&&(flag4==1))
	{
		flag4=0;
	}
	if ((dio_read_pin('c',7)==1)&&(flag14==0))
	{
		if (D>0)
		{
			D--;
		}
		
		
		flag14=1;
	}
	if ((dio_read_pin('c',7)==0)&&(flag14==1))
	{
		flag14=0;
	}
	/***********************************************/
	
		tostring(str,A);
		lcd_move_cursor(1,1);
			//lcd_send_char(0x20);
		//	lcd_send_char(0x20);
		//	lcd_move_cursor(1,1);
			lcd_send_string("x1=");
			lcd_send_string(str);
		lcd_send_char(0x20);
	/********************************************/

		tostring(str,B);
		lcd_move_cursor(1,8);
	//	lcd_send_char(0x20);
			//	lcd_send_char(0x20);
	//lcd_move_cursor(1,8);
		lcd_send_string("x2=");
		lcd_send_string(str);
	lcd_send_char(0x20);
	
	/***************************************/
	
		tostring(str,C);
			lcd_move_cursor(2,1);
			//lcd_send_char(0x20);
			//lcd_send_char(0x20);
			//lcd_move_cursor(2,1);
		lcd_send_string("x3=");
		lcd_send_string(str);
		lcd_send_char(0x20);
	/*******************/
	
	
		tostring(str,D);
lcd_move_cursor(2,8);
//lcd_send_char(0x20);
//lcd_send_char(0x20);
//lcd_move_cursor(2,8);
		lcd_send_string("x4=");
		lcd_send_string(str);
		lcd_send_char(0x20);
	}
}