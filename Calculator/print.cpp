#include"Print.h"

void Print::printqueue(queue<string> que)
{
	while(!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}
}
