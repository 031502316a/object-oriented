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
	Print output;                                                
	if((strcmp(argv[1],"-f") == 0))
	{
		string getsfile=argv[argc-2];                                            //�����ļ��� 
        string putsfile=argv[argc-1];                                            //����ļ��� 
        output.print_format_one(getsfile,putsfile);
	}
	else if(strcmp(argv[1],"-a") == 0)  
	{
		string input=argv[argc-1];    
		output.print_format_two(input);
	}
	else 
	{
		string input=argv[argc-1];    
		output.print_format_three(input);
	}
	return 0;
}
