/*
 * count_strg.c
 *
 * Created: 15/08/2023 03:07:43 م
 *  Author: handsa
 */ 
unsigned short count_string(char*ptr)
{
	unsigned short x=0;
	while(*ptr!=0)
	{
		ptr++;
	x++;
	}
x--;
return x;
}
