#include <iostream>
#include"Scan.h"
#include"Print.h"
using namespace std;

int main()
{
	Scan get;
	Print output;
	string input;
	cin>>input;                                             //����ʱҪע���Ƿ�ת����Ӣ�ģ�����������������ַ��Ļ����᲻ƥ�� 
    get.ToStringQueue(input);                              //�������input����Scan��ĺ������м��㣬�Ѽ�����ֵ����Scan�ĳ�Ա outputqueue
    output.printqueue(get.outputqueue);                   //������ ��ֵ��Print��ĺ������ 
	return 0;
}
