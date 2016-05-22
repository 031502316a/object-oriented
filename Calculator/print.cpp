#include <iostream>
#include <stdio.h> 
#include <string.h>
#include<queue>
#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
#include<fstream>         //�µ�ͷ�ļ��������ļ�������Ȳ����� 

/*�����ж��Ƿ�����Ϊ�ļ���ʽ���������ҵ��ӵ�����*/ 
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
        Scan get;                                                                     //����scan�� 
	    Calculation cal;                                                              //����calculation�࣬���ڼ�����     
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
		
	infile.close();                                                             //�ر��ļ� 
	outfile.close();                                                                                                   

	
}

/*�����ļ�������ʱ�򣬸����Ĵ���һ��*/


void Print::print_format_two(string input,double result,int judge)
{
	cout<<input;                                        // ���ʽ��                                                                   
	if(judge==1)                                        //���Ƿ������ʽ����������ģ��������������error 
    {
    	cout<<"ERROR"<<endl;
	}
	else
	{
		cout<<result<<endl;                           //������ 
	}
}


void Print::print_format_three(double result,int judge)
{                                             
	if(judge==1)                                        //���Ƿ������ʽ����������ģ��������������error 
    {
    	cout<<"ERROR"<<endl;
	}
	else
	{
		cout<<result<<endl;                           //������ 
	}
}

