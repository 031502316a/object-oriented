#include <iostream>
#include <stdio.h> 
#include <string.h>
#include<queue>
#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
using namespace std;

int main(int argc,char *argv[])
{
	Scan get;                                                                     //定义scan类 
	Print output;                                                                 //定义print类，但是这里没什么用。。。。 
	Calculation cal;                                                              //定义calculation类，用于计算结果 
	string input,_input;                                                          //定义一个字符串用来存储输入要计算的式子  
	cin>>input;
    if(input=="-a")                                                               //如果有输入-a的话就得输出整个式子 
	{ 
	    cin >>_input;                                                             /*如果不是-a的话既不必在输入，因为input就已经是要计算的式子了，
		                                                                          如果是-a则需要再输入要计算的式子 */ 
	    cout<<_input;                                                             // 输出式子 
		cout<<"= ";                                                               //格式要求
		get.ToStringQueue(_input);                                                
	}
	else
	{
	    get.ToStringQueue(input);                                                /*把输入的input放入Scan类的函数进行计算，把计算后的值赋予
		                                                                           Scan的成员 outputqueue*/
	}                                                  
    if(get.outputqueue.front()=="ERROR")                                         //看是否输入的式子是有问题的，如果有问题就输出error 
    {
    	cout<<"ERROR"<<endl;
	}
	else
	{
		cout<<cal.Calculate(get.outputqueue)<<endl;                              //输出结果 
	}
	return 0;
}
