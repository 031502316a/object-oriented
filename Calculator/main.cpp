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
	Scan get;                                                                     //����scan�� 
	Print output;                                                                 //����print�࣬��������ûʲô�á������� 
	Calculation cal;                                                              //����calculation�࣬���ڼ����� 
	string input,_input;                                                          //����һ���ַ��������洢����Ҫ�����ʽ��  
	cin>>input;
    if(input=="-a")                                                               //���������-a�Ļ��͵��������ʽ�� 
	{ 
	    cin >>_input;                                                             /*�������-a�Ļ��Ȳ��������룬��Ϊinput���Ѿ���Ҫ�����ʽ���ˣ�
		                                                                          �����-a����Ҫ������Ҫ�����ʽ�� */ 
	    cout<<_input;                                                             // ���ʽ�� 
		cout<<"= ";                                                               //��ʽҪ��
		get.ToStringQueue(_input);                                                
	}
	else
	{
	    get.ToStringQueue(input);                                                /*�������input����Scan��ĺ������м��㣬�Ѽ�����ֵ����
		                                                                           Scan�ĳ�Ա outputqueue*/
	}                                                  
    if(get.outputqueue.front()=="ERROR")                                         //���Ƿ������ʽ����������ģ��������������error 
    {
    	cout<<"ERROR"<<endl;
	}
	else
	{
		cout<<cal.Calculate(get.outputqueue)<<endl;                              //������ 
	}
	return 0;
}
