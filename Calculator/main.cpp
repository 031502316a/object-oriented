#include <iostream>
#include <stdio.h> 
#include <string.h>
#include<queue>
#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
#include<fstream>         //新的头文件（用于文件的输入等操作） 
using namespace std;

int main(int argc,char *argv[])
{
	int judge=0;
	double result=0;
	
	Print output;    
	                                            
	if((strcmp(argv[1],"-f") == 0))
	{
		string input;
		string getsfile=argv[argc-2];                                            //输入文件名 
        string putsfile=argv[argc-1];                                            //输出文件名 
        output.print_format_one(getsfile,putsfile);                                                  
	}
	
	else if(strcmp(argv[1],"-a") == 0)  
	{
		Scan get;                                                                     //定义scan类 
	    Calculation cal;                                                              //定义calculation类，用于计算结果     
	
		string input = argv[argc-1];  
		string input1 = argv[argc-1];  
		get.ToStringQueue(input);   
		if((get.outputqueue.front()=="ERROR") )
		{
			judge=1;
		}
		else
		{
			result=cal.Calculate(get.outputqueue);
		}		
		output.print_format_two(input1,result,judge);
	}
	
	else 
	{
		Scan get;                                                                     //定义scan类 
	    Calculation cal;                                                              //定义calculation类，用于计算结果    
		 
		string input = argv[argc-1];   
		get.ToStringQueue(input);   
		if((get.outputqueue.front()=="ERROR") )
		{
			judge=1;
		}
		else
		{
			result=cal.Calculate(get.outputqueue);
		}		
		output.print_format_three(result,judge);
	}
	
	return 0;
}
