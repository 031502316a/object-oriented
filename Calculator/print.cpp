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
	Scan get;                                                                     //����scan�� 
	Calculation cal;                                                              //����calculation�࣬���ڼ�����                                                         //����һ���ַ��������洢����Ҫ�����ʽ��  
    
	ifstream infile;
    ofstream outfile;
        
    infile.open(getsfile.c_str(),ios::in); 
    outfile.open(putsfile.c_str(),ios::out);

    string input;  
    while(!infile.eof())                                                       //δ�����ļ�β 
    {       
		getline(infile,input,'\n');                                           //�������� 
        get.ToStringQueue(input);   
        queue<string>que;
        que=get.outputqueue;
        if(que.front()=="ERROR")                                  //���Ƿ������ʽ����������ģ��������������error 
        {
    	    cout<<"ERROR"<<endl;
	    }
	    else
	    {
	    	double results;
	    	results=cal.Calculate(que);
	        outfile<<results<<endl;
		} 
    }
    infile.close();                                                          //�ر��ļ� 
    outfile.close();
}

/*�����ļ�������ʱ�򣬸����Ĵ���һ��*/


void Print::print_format_two(string input)
{
	Scan get;                                                                   //����scan�� 
	Calculation cal;                                                            //����calculation�࣬���ڼ����� 
	cout<<input;                                                                // ���ʽ��                                                        //��ʽҪ��
	get.ToStringQueue(input);                                                
	if(get.outputqueue.front()=="ERROR")                                        //���Ƿ������ʽ����������ģ��������������error 
    {
    	cout<<"ERROR"<<endl;
	}
	else
	{
		cout<<cal.Calculate(get.outputqueue)<<endl;                           //������ 
	}
}


void Print::print_format_three(string input)
{
	Scan get;                                                                //����scan�� 
	Calculation cal;    
	get.ToStringQueue(input);                                                /*�������input����Scan��ĺ������м��㣬�Ѽ�����ֵ����
		                                                                         Scan�ĳ�Ա outputqueue*/                                                          //����calculation�࣬���ڼ����� 
	if(get.outputqueue.front()=="ERROR")                                    //���Ƿ������ʽ����������ģ��������������error 
    {
    	cout<<"ERROR"<<endl;
	}
	else
	{
		cout<<cal.Calculate(get.outputqueue)<<endl;                           //������ 
	}
}

