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
			
		else if (input[i] >= 48 && input[i] <= 57 || input[i] == '.')//由于这是string类型的，所以48在这里才是0，以此类推到57为9。
	    {
	    	if(input[i] == '.')
		    {
			  digit=digit;//算出位数 
			}
			else
			{
			  digit++;
			} 
			      if (digit>10)
			     {
			        if(wrong=1)//如果是有超过十位的数则输出错误
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
		 num=num+input[i];//由于是string类型，所以可以直接相加。
		}

	}
	
   if(num!="")//为了输出最后一个数字（如果最后一个是符号的话就没用了） 
  {
	inputqueue.push(num);
  }

}


  queue<string> Scan::getqueue()
{
  return inputqueue;
}


