/*此部分函数用于测试time()函数*/
/*
发现此函数并不适用于本程序
time函数产生的随机数,只在秒一级有显著变化,在分及以上时刻的变化不大 
*/
#include<stdio.h>
#include<time.h>
int main()
{
	time_t t;
	struct tm * lt;
	double a = time(&t);
	lt = localtime (&t);
	printf("%lld \n ",a);
	printf("%d/%d/%d %d:%d:%d \n",lt->tm_year+1900,lt->tm_mon,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	return 0;
 } 
