/*
此部分函数用于初始化布局，包括三部分功能：
1.初始化原数组为无雷 Mine_init
2.实现随机分布的雷区(限制个数) Mine_random
3.遍历记录数组元素数值(用于记录是否有雷) Mine_show
4.界面显示雷区  Figure_show  
*/ 

//初始化一个10*10的雷区数组
#include<stdio.h> 
#include<stdlib.h>
#include<time.h> 
#define ismine 11
int notdig=0;
short int Minefield[10][10]={0};
void Mine_init(void)
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			printf("%d ",Minefield[i][j]);
		}
		printf("\n"); 
	}//用于调试显示Minefiled数组 
}

//随布置地雷  
void Mine_random (void)
{
	int m,n;
	srand(time(0));
	//开始布置地雷 
	for(int i=0; i<10; i++)
	{
		m=rand()%10;		//产生 0 ~ 9之间的随机数 m,n  
		n=rand()%10;
		Minefield[m][n]=ismine;
	}
	
}

 
//记录数组元素数值,没有考虑到越界 
/*void Mine_show (void)
{
	//Mine_random();
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(Minefield[i][j] >= ismine) 
			{
				Minefield[i-1][j-1]++;
				Minefield[i-1][j]++;
				Minefield[i-1][j+1]++;
				Minefield[i][j-1]++;
				Minefield[i][j+1]++;
				Minefield[i+1][j-1]++;
				Minefield[i+1][j]++;
				Minefield[i+1][j+1]++;
			}
		}
	}
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(Minefield[i][j] >= ismine) 
			{
				Minefield[i][j] = ismine;
			}
		}
	}*/
	
	/*for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			printf("%d ",Minefield[i][j]);
			if(j == 9) printf("\n"); 
		}
	}
}*/

void Mine_count (void) 
{
	int lei_shu=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(Minefiled[i][j] != ismine )
			{
				//防止左越界 
				if(i-1 >=0 )
				{
					
					if(Minefiled[i-1][j-1] >= ismine ) 
					lei_shu++;
					if(Minefiled[i-1][j] >= ismine ) 
					lei_shu++;
					if(Minefiled[i-1][j+1] >= ismine ) 
					lei_shu++;
				} 
				if(Minefiled[i+1][j] >=0 )
				{
					if(Minefiled[i+1][j-1] >= ismine ) 
					lei_shu++;
					if(Minefiled[i+1][j] >= ismine ) 
					lei_shu++;
					if(Minefiled[i+1][j+1] >= ismine ) 
					lei_shu++;
				} 
				if(Minefiled[i][j-1] >= ismine )
				lei_shu++;
				if(Minefiled[i][j+1] >= ismine )
				lei_shu++;
			}
		}
	}
}

//显示当前雷区状态  
void Figure_show (void)
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(Minefield[i][j] < 20) //没有被挖到过  
				{printf(" * "); notdig++;}
			else if(Minefield[i][j] == 20)
				printf("   ");
			else
				printf(" %d ",Minefield[i][j] - 20 );
		
		}
		printf(" \n");
	}
}

//最初界面的显示 
void init_show ()
{
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*          Welcome  to  this  game             *\n");
	printf("*                                              *\n");
	printf("************************************************\n");
}



