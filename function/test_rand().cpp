/*
用于测试函数srand(),rand(),time()函数产生随机数 
效果不错  
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int i=0,j=0,p;
	srand(time(NULL));
	while(1)
	{
		p=rand()%10+1;
		printf("%d\t",p);
		printf("\n");
	}
	
	return 0; 
}
