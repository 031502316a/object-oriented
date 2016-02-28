#include <iostream>
#include"Scan.h"
#include"Print.h"
using namespace std;

int main()
{
	Scan get;
	Print out;
	string input;
	cin>>input;
	get.ToStringQueue(input);
	queue<string> operation=get.getqueue(); 
	out. printqueue(operation);
	return 0;
}
