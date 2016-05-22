#include <iostream>
#include <stdio.h> 
#include <string.h>
#include<queue>
#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
#include<fstream>         //新的头文件（用于文件的输入等操作） 

/*定义判断是否输入为文件格式，第五次作业添加的内容*/ 
void Print::print_format_one(string getsfile,string putsfile)
{    
    double result;
    ifstream infile;
    ofstream outfile;
        
    infile.open(getsfile.c_str(),ios::in); 
    outfile.open(putsfile.c_str(),ios::out); 
        
    string input;
    while(!infile.eof())   
    {
        Scan get;                                                                     //定义scan类 
	    Calculation cal;                                                              //定义calculation类，用于计算结果     
        getline(infile,input,'\n'); 
        get.ToStringQueue(input);  
        if((get.outputqueue.front()=="ERROR") )
		{
			outfile<<"ERROR"<<endl;
		}  
		else
		{
			result=cal.Calculate(get.outputqueue);
		    outfile<<result<<endl;
		}	
	}
		
	infile.close();                                                             //关闭文件 
	outfile.close();                                                                                                   

	
}

/*无需文件操作的时候，跟第四次作一样*/


void Print::print_format_two(string input,double result,int judge)
{
	cout<<input;                                        // 输出式子                                                                   
	if(judge==1)                                        //看是否输入的式子是有问题的，如果有问题就输出error 
    {
    	cout<<"ERROR"<<endl;
	}
	else
	{
		cout<<result<<endl;                           //输出结果 
	}
}


void Print::print_format_three(double result,int judge)
{                                             
	if(judge==1)                                        //看是否输入的式子是有问题的，如果有问题就输出error 
    {
    	cout<<"ERROR"<<endl;
	}
	else
	{
		cout<<result<<endl;                           //输出结果 
	}
}

