#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double count(char op[],double num[]);//根据两个数组 计算结果
double getNum(char str[],int * pos,int start); //获得一个数

int main()
{
	printf("\t\t第四版科学计算器\t\n");
	printf("\t\t****************\t\n");
	printf("\t\t    更新内容    \t\n");
	printf("\t\t四则运算法则运算\t\n");
	printf("\t\t注意：不支持括号\t\n");
	printf("\t\t****************\t\n");
	printf("\t\t**作者：吴川**\t\n");
	printf("\t\t       2018.4.25\t\n");
	printf("\t\t****************\t\n");
	char str[40] = "";
	printf("小天使提醒你：请输入合法的表达式，摁回车键结束\n");
	scanf("%s",str);
	
	int lenth = strlen(str);
	char op[40] = "";
	double num[40] = {0};
	int k = 0;
	int m = 0;
	int position = 0; //记录 字符串中循环到的位置

	//假如输入 "12345.2+1.3-5"
	for(int i = 0 ;i < lenth;i++)
	{
		
		if(str[i] >= '0' && str[i] <= '9')
		{
			num[k] = getNum(str,&position,i); //获得一个数保存到数组里面去
			i = position;                     //第一次运行到这里先找12345.2 ，这时候循环运行到字符串+的位置
			k++;
		}


		//优先级判断：进入count运算函数前，将乘除现行计算后得到的值保存到前一个值里，count函数只运算加减 
		if(str[i] == '*')
		{
			i++;
			num[k-1] = num[k-1] * getNum(str,&position,i);
			i = position;
		}//乘除优先级
		 
		if(str[i] == '/')
		{
			i++;
			num[k-1] = num[k-1] / getNum(str,&position,i);
			i = position;
		}//乘除优先级
		
		if(str[i]=='+'||str[i]=='-')//修改判断条件，只判断是否是 + - 是则存入op 
		{
			op[m] = str[i];
			m++;
		}			
	}
	
	double value = count(op,num);
	printf("您输入的表达式所算出的值保留四位小数为%.4f\n",value);

	return 0;
}

double getNum(char str[],int * position,int start)  //找到一个数（only one）
{
		char tem[40] = "";
		int j = 0;
		int i = start;
		double result = 0;

		// 12345.2+1.3-5
		while(str[i] >= '0' && str[i] <= '9' || str[i] == '.')
		{
			tem[j] = str[i];
			j++;

			if(str[i+1] >= '0' && str[i+1] <= '9' || str[i+1] == '.')
			{
				i++;
				continue;
			}
			else
			{
				result = atof(tem);
				*position = i; //通过指针变量可以修改主函数中变量的值。这里修改的目的是为了让主函数从当前位置往后面找
				break;
			}
		}
	return result;
}

//1+2*3/4-5*6-1=31.5
double count(char op[],double num[])//只负责加减运算 
{
	double value = num[0];
	int m = strlen(op); //m为操作运算符的个数
	for(int n = 0 ;n <m ;n++)
	{
		if(op[n]=='+') value =value + num[n+1];
		else if(op[n]=='-') value =value - num[n+1];
	} 
	return value;
}
