#include "Scan.h"

void Scan::ToStringQueue(string input)
{
	int i;
	int digit=0;                                  //��������λ������Ȼ�ǵ�Ҫ�����ֵ�� ;
	string num="";                                //������һ������ƴ������
	string wrong=" ";                             //������������г���ʮλ����ʱ����error ��push������֮�� 
	for (i=0; i<input.size(); i++)
	{
		if (input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '*' || input[i] == '/')
		{
			if (num!="")                           //����÷���ǰ����������� 
			{
				outputqueue.push(num);
				num="";
				digit=0;
			}
			string copy;                           //����copyʹ����ڸ÷��ţ��Ӷ�push����У�ֱ��pushinput[i]�ǲ��е� 
			copy=input[i];
			outputqueue.push(copy);
		}
		else if (input[i] >= 48 && input[i] <= 57 || input[i] == '.')      //47��58���ַ��ж�Ӧ��������0��9 
		{
			if (input[i] == '.')                    //С���㲻��λ��������Ҫ�ж��� 
			{
				digit=digit;
			}
			else
			{
				digit++;
			}
			if (digit>10)
			{
				int j;
				for (j=0; j<outputqueue.size(); j++)       // �������ֳ���ʮλ����ʱ�򣬽�outputqueue���㣬ʹ��ֻ����ERROR
				{
					outputqueue.pop();               
				}
				wrong="ERROR";
				outputqueue.push(wrong);                  //������ֻ��ERROR�� 
				break;                                    //����ѭ�� ����Ϊ�����д�����Ҫ�ټ��� 
			}
			else
			{
			     num=num+input[i];                       //��һ�����ֺϲ�����Ϊ���ַ����Կ���ֱ����ӣ����������֮��ľͲ���ֱ������� 
			} 
		}
	}
	if (num!=""&&wrong!="ERROR")                          //����Ҫ��������һλ�����ֵĻ����޷�push��outputqueue�У�����Ҫ��������ж�
	{
		outputqueue.push(num);
	}
}
