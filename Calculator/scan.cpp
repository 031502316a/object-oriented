#include"Scan.h"
using namespace std;


void Scan::ToStringQueue(string input)
{
	string num="",symbol;
	int i,wrong=0,digit;
	for (i=0;i<input.size();i++)
	{
	    if(input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '*' || input[i] == '/')
		{    
		    if (num!="") 
	        {
		     inputqueue.push(num);
	        }
		 num="";
		 symbol=input[i];
		 digit=0;
		 inputqueue.push(symbol); 
        }
			
		else if (input[i] >= 48 && input[i] <= 57 || input[i] == '.')//��������string���͵ģ�����48���������0���Դ����Ƶ�57Ϊ9��
	    {
	    	if(input[i] == '.')
		    {
			  digit=digit;//���λ�� 
			}
			else
			{
			  digit++;
			} 
			      if (digit>10)
			     {
			        if(wrong=1)//������г���ʮλ�������������
                   {
	                int size = inputqueue.size();
	                   for (i=0;i<size;i++)
                      {
		              inputqueue.pop();
	                  }
	                 num="ERROR";
	                inputqueue.push(num);
                   }

			        break;
			     }
		 num=num+input[i];//������string���ͣ����Կ���ֱ����ӡ�
		}

	}
	
   if(num!="")//Ϊ��������һ�����֣�������һ���Ƿ��ŵĻ���û���ˣ� 
  {
	inputqueue.push(num);
  }

}


  queue<string> Scan::getqueue()
{
  return inputqueue;
}


