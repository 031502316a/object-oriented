#include <iostream>
#include <stdio.h> 
#include <string.h>
#include<queue>
#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
#include<fstream>         //新的头文件（用于文件的输入等操作） 

/*定义判断是否输入为文件格式，第五次作业添加的内容*/ 
void Print::print_format_one(int argc,string getsfile,string putsfile)
{
	Scan get;                                                                     //定义scan类 
	Calculation cal;                                                              //定义calculation类，用于计算结果 
	string input;                                                                 //定义一个字符串用来存储输入要计算的式子  

    fstream infile;
    fstream outfile;
        
    infile.open(getsfile.c_str(),ios::in); 
    outfile.open(putsfile.c_str(),ios::out);
        
	string get_str;
        
    while(!infile.eof())                                                       //未处理到文件尾 
    {
        getline(infile,input,'\n');                                           //读入数据 
        get.ToStringQueue(input);   
        if(get.outputqueue.front()=="ERROR")                                  //看是否输入的式子是有问题的，如果有问题就输出error 
        {
    	    cout<<"ERROR"<<endl;
	    }
	    else
	    {
	        outfile<<cal.Calculate(get.outputqueue)<<endl;
		} 
    }
    infile.close();                                                          //关闭文件 
    outfile.close();
}

/*无需文件操作的时候，跟第四次作一样*/


void Print::print_format_two(string input)
{
	Scan get;                                                                   //定义scan类 
	Calculation cal;                                                            //定义calculation类，用于计算结果 
	cout<<input;                                                                // 输出式子                                                        //格式要求
	get.ToStringQueue(input);                                                
	if(get.outputqueue.front()=="ERROR")                                        //看是否输入的式子是有问题的，如果有问题就输出error 
    {
    	cout<<"ERROR"<<endl;
	}
	else
	{
		cout<<cal.Calculate(get.outputqueue)<<endl;                           //输出结果 
	}
}


void Print::print_format_three(string input)
{
	Scan get;                                                                //定义scan类 
	Calculation cal;    
	get.ToStringQueue(input);                                                /*把输入的input放入Scan类的函数进行计算，把计算后的值赋予
		                                                                         Scan的成员 outputqueue*/                                                          //定义calculation类，用于计算结果 
	if(get.outputqueue.front()=="ERROR")                                    //看是否输入的式子是有问题的，如果有问题就输出error 
    {
    	cout<<"ERROR"<<endl;
	}
	else
	{
		cout<<cal.Calculate(get.outputqueue)<<endl;                           //输出结果 
	}
}

