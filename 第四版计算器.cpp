#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double count(char op[],double num[]);//������������ ������
double getNum(char str[],int * pos,int start); //���һ����

int main()
{
	printf("\t\t���İ��ѧ������\t\n");
	printf("\t\t****************\t\n");
	printf("\t\t    ��������    \t\n");
	printf("\t\t�������㷨������\t\n");
	printf("\t\tע�⣺��֧������\t\n");
	printf("\t\t****************\t\n");
	printf("\t\t**���ߣ��⴨**\t\n");
	printf("\t\t       2018.4.25\t\n");
	printf("\t\t****************\t\n");
	char str[40] = "";
	printf("С��ʹ�����㣺������Ϸ��ı��ʽ�����س�������\n");
	scanf("%s",str);
	
	int lenth = strlen(str);
	char op[40] = "";
	double num[40] = {0};
	int k = 0;
	int m = 0;
	int position = 0; //��¼ �ַ�����ѭ������λ��

	//�������� "12345.2+1.3-5"
	for(int i = 0 ;i < lenth;i++)
	{
		
		if(str[i] >= '0' && str[i] <= '9')
		{
			num[k] = getNum(str,&position,i); //���һ�������浽��������ȥ
			i = position;                     //��һ�����е���������12345.2 ����ʱ��ѭ�����е��ַ���+��λ��
			k++;
		}


		//���ȼ��жϣ�����count���㺯��ǰ�����˳����м����õ���ֵ���浽ǰһ��ֵ�count����ֻ����Ӽ� 
		if(str[i] == '*')
		{
			i++;
			num[k-1] = num[k-1] * getNum(str,&position,i);
			i = position;
		}//�˳����ȼ�
		 
		if(str[i] == '/')
		{
			i++;
			num[k-1] = num[k-1] / getNum(str,&position,i);
			i = position;
		}//�˳����ȼ�
		
		if(str[i]=='+'||str[i]=='-')//�޸��ж�������ֻ�ж��Ƿ��� + - �������op 
		{
			op[m] = str[i];
			m++;
		}			
	}
	
	double value = count(op,num);
	printf("������ı��ʽ�������ֵ������λС��Ϊ%.4f\n",value);

	return 0;
}

double getNum(char str[],int * position,int start)  //�ҵ�һ������only one��
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
				*position = i; //ͨ��ָ����������޸��������б�����ֵ�������޸ĵ�Ŀ����Ϊ�����������ӵ�ǰλ����������
				break;
			}
		}
	return result;
}

//1+2*3/4-5*6-1=31.5
double count(char op[],double num[])//ֻ����Ӽ����� 
{
	double value = num[0];
	int m = strlen(op); //mΪ����������ĸ���
	for(int n = 0 ;n <m ;n++)
	{
		if(op[n]=='+') value =value + num[n+1];
		else if(op[n]=='-') value =value - num[n+1];
	} 
	return value;
}
