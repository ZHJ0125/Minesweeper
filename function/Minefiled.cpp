#include <stdlib.h>
#include <stdio.h>
#include <time.h>
short int Minefield[10][10];

/*
  Mine_init()函数实现了三个功能 ：
  1. 初始化雷区数组元素全部为 0 
  2. 在雷区随机产生 10 个地雷 
  3. 对雷区数组的所有元素进行统计
*/ 

void Mine_init() 
{
    int hang=0, lie=0, lei_shu=0;
    srand(time(0));		//产生随机数种子 
    //对雷区元素进行初始化 
    for(hang=0;hang<10;hang++) 
	{
        for(lie=0;lie<10;lie++) 
		{
	        Minefield[hang][lie]=0;
	    }
    }
    //雷区随机产生 10 个地雷 
    for(int i=0;i<10;i++) 
	{
        hang=rand()%10;
        lie=rand()%10;
        if(Minefield[hang][lie]<10) 
		{
	        Minefield[hang][lie]=10;
	    }
    }
    //统计雷区各元素的数值  
    for(hang=0;hang<10;hang++) 
	{
        for(lie=0;lie<10;lie++) 	//遍历雷区  
		{
	        if(Minefield[hang][lie]>=10) //如果此元素是雷,就跳过 
			{
	        	continue;
			}
			//如果此元素不是雷的话  
			lei_shu=0;	//初始雷数为 0 个 
			//为防止下标越界,对行列的位置进行判断  
	        if((hang-1)>=0)		//保证上行不越界  
			{
    		    if((lie-1)>=0) 
				{
		            if(Minefield[hang-1][lie-1]>=10) 	//需要保证左上行列不越界 
					{
			            lei_shu++;
			        }
			    }
			    if(Minefield[hang-1][lie]>=10) 			//保证行不越界 
				{
			        lei_shu++;
			    }
		        if((lie+1)<=9) 
				{
			        if(Minefield[hang-1][lie+1]>=10) 	//保证右上行列不越界 
					{
			            lei_shu++;
			        }
			    }
		    }
		    if((lie-1)>=0) 		//保证左列不越界 
			{
		        if(Minefield[hang][lie-1]>=10) 
				{
		            lei_shu++;
			    }
		    }
		    if((lie+1)<=9) 		//保证右列不越界 
			{
		    	if(Minefield[hang][lie+1]>=10) 
				{
		    		lei_shu++;
				}
			}
			if((hang+1)<=9) 	//保证下行不越界 
			{
				if((lie-1)>=0) 
				{
					if(Minefield[hang+1][lie-1]>=10) 	//保证左下不越界 
					{
						lei_shu++;
					}
				}
				if(Minefield[hang+1][lie]>=10) 		//保证下行不越界 
				{
					lei_shu++;
				}
				if((lie+1)<=9) 
				{
					if(Minefield[hang+1][lie+1]>=10) 	//保证右下不越界 
					{
						lei_shu++;
					}
				}
			}
			Minefield[hang][lie]=lei_shu;	//统计得出各元素的值 
	    }
    }
}


//实现对用户输入的行列进行判断及标记 
void Mine_dig(int hang,int lie) 
{
	if((hang>=0)&&(hang<=9)&&(lie>=0)&&(lie<=9)) 	//保证用户输入的行列数是有效的 
	{
		if(Minefield[hang][lie]<100) 	//该元素没有被挖过 
		{
			Minefield[hang][lie]+=100;	//加 100 来标记它被挖 
			//如果该元素原来是空,应该对其上下左右四个方向继续挖 
			if(Minefield[hang][lie]==100) 
			{
				if(Minefield[hang-1][lie]<100) 
				{
					Mine_dig(hang-1,lie);
				}
				if(Minefield[hang+1][lie]<100) 
				{
					Mine_dig(hang+1,lie);
				}
				if(Minefield[hang][lie-1]<100) 
				{
					Mine_dig(hang,lie-1);
				}
				if(Minefield[hang][lie+1]<100) 
				{
					Mine_dig(hang,lie+1);
				}
			}
		}	
	}
}


//实现对雷区元各素的输出,包括显示行列的数字 
void Figure_show() 
{
	//将用户的行输出 
	int hang=0, lie=0;
	printf("   0 ");
	for(int i=1;i<11;i++)
		printf("  %d  ",i);
	printf("\n\n");
	for(hang=0;hang<10;hang++) 
	{
		if(hang<9)
		printf("  %d) ",hang+1);
		else
		printf(" %d) ",hang+1);		//用户列输出 
		for(lie=0;lie<10;lie++) 
		{
		    if(Minefield[hang][lie]>=100) 	//该元素被挖过 
			{
		    	if(Minefield[hang][lie]-100==10) 	//该元素是雷 
				{
		    		printf("  X  ");
				}
				else if(Minefield[hang][lie]-100==0) //该元素原来为空 
				{
					printf("     ");
				}
				else 
				{
					printf("  %d  ",Minefield[hang][lie]-100);	//该元素原来是数字 
				}
			}
			else 	//该元素没有被挖过 
			{
					printf("  *  ");
			}
		}
		printf("\n\n");
	}
}


//对游戏结果进行标记,决定游戏是否继续 
int pan_duan() 
{
	int hang=0, lie=0, i=0;
	for(hang=0;hang<10;hang++) 
	{
		for(lie=0;lie<10;lie++) 
		{
			if(Minefield[hang][lie]!=10) 	//不是没有被挖的雷 
			{
			    if(Minefield[hang][lie]==110) //踩雷了...
				{
				    return 1;	
			    }
			    if(Minefield[hang][lie]<100) //还没有挖过 
				{
				    i = 2;	//返回2,就是说还有没挖的 
			    }
		    }
		}
	}
	return i;
}



int main() 
{
	int hang=0, lie=0, i=0;
	Mine_init();	
	Figure_show();	
	while(1) 
	{
	    printf("请输入行号和列号（1~10）：");
	    scanf("%d%d",&hang,&lie);
	    fflush(stdout);	
		Mine_dig(hang-1,lie-1);		
	    Figure_show();		
	    i=pan_duan();
	    if(i==1) 
		{
	    	printf("\n~~~~~~~~~~ GameOver ~~~~~~~~~~\n");
	    	break;
		}
		if(i==0) 
		{
			printf("\n~~~~~~~~~~ Game Win !~~~~~~~~~~\n");
			break;
		}
    }
	/*while(1)
	{
		char x;
		printf("再玩一局吗? (y/n) : ");
		scanf("%c",&x);
		if( x == 'y' )  return main();
		if( x == 'n' )  return 0;
	}*/
    return 0;
}
