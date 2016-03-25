#include <iostream>
#include"Scan.h"
#include"Print.h"
using namespace std;

int main()
{
	Scan get;
	Print output;
	string input;
	cin>>input;                                             //输入时要注意是否转换成英文，如果是以中文输入字符的话将会不匹配 
    get.ToStringQueue(input);                              //把输入的input放入Scan类的函数进行计算，把计算后的值赋予Scan的成员 outputqueue
    output.printqueue(get.outputqueue);                   //将队列 的值用Print类的函数输出 
	return 0;
}
