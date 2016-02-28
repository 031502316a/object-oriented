#include"Print.h"
using namespace std;


void Print::printqueue(queue<string> que)
{
	int size,i;   
	size = que.size();
	for (i=0;i<size;i++)
	{
	cout << que.front() << endl;
	que.pop();
	}
}
