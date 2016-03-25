#include "Scan.h"

void Scan::ToStringQueue(string input)
{
	int i;
	int digit=0;                                  //用来计算位数（当然记得要赋予初值） ;
	string num="";                                //用来把一组数字拼接起来
	string wrong=" ";                             //用于下面如果有超过十位数的时候复制error ，push到队列之中 
	for (i=0; i<input.size(); i++)
	{
		if (input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '*' || input[i] == '/')
		{
			if (num!="")                           //如果该符号前有数字则输出 
			{
				outputqueue.push(num);
				num="";
				digit=0;
			}
			string copy;                           //定义copy使其等于该符号，从而push入队列，直接pushinput[i]是不行的 
			copy=input[i];
			outputqueue.push(copy);
		}
		else if (input[i] >= 48 && input[i] <= 57 || input[i] == '.')      //47到58在字符中对应的是数字0到9 
		{
			if (input[i] == '.')                    //小数点不算位数，所以要判断下 
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
				for (j=0; j<outputqueue.size(); j++)       // 当有数字超出十位数的时候，将outputqueue清零，使其只等于ERROR
				{
					outputqueue.pop();               
				}
				wrong="ERROR";
				outputqueue.push(wrong);                  //队列中只有ERROR了 
				break;                                    //跳出循环 ，因为输入有错，不需要再计算 
			}
			else
			{
			     num=num+input[i];                       //将一个数字合并，因为是字符所以可以直接相加，如果是整形之类的就不能直接相加了 
			} 
		}
	}
	if (num!=""&&wrong!="ERROR")                          //很重要，如果最后一位是数字的话就无法push到outputqueue中，所以要加上这个判断
	{
		outputqueue.push(num);
	}
}
