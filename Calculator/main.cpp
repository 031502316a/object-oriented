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
	Print output; 
	string input=argv[argc-1]; 
	if(argc<2)
	{
		cout  << "ABC" << endl; 
    } 
	else{                                                         
	if((strcmp(argv[1],"-f") == 0))
	{
		string getsfile=argv[argc-2];                                            //输入文件名 
        string putsfile=argv[argc-1];                                            //输出文件名 
        output.print_format_one(argc,getsfile,putsfile);
	}
	else if(strcmp(argv[1],"-a") == 0)  
	{
		output.print_format_two(input);
	}
	else 
	{
		output.print_format_three(input);
	}
}
	return 0;
}
