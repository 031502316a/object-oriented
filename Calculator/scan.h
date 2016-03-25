#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Scan
{
	public:
		
		void ToStringQueue(string input);            //核心函数，用来完成将输入的字符串转换成队列存储进成员outputqueue
		queue<string>outputqueue;
};
