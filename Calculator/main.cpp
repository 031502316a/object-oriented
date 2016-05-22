#include <iostream>
#include <stdio.h> 
#include <string.h>
#include<queue>
#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
#include<fstream>         //�µ�ͷ�ļ��������ļ�������Ȳ����� 
using namespace std;

int main(int argc,char *argv[])
{
	int judge=0;
	double result=0;
	
	Print output;    
	                                            
	if((strcmp(argv[1],"-f") == 0))
	{
		string input;
		string getsfile=argv[argc-2];                                            //�����ļ��� 
        string putsfile=argv[argc-1];                                            //����ļ��� 
        output.print_format_one(getsfile,putsfile);                                                  
	}
	
	else if(strcmp(argv[1],"-a") == 0)  
	{
		Scan get;                                                                     //����scan�� 
	    Calculation cal;                                                              //����calculation�࣬���ڼ�����     
	
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
		Scan get;                                                                     //����scan�� 
	    Calculation cal;                                                              //����calculation�࣬���ڼ�����    
		 
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
