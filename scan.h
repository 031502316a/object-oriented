#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Scan
{
public:
	void ToStringQueue(string input);
	queue<string> getqueue();  

private:
	queue<string> inputqueue;  
};

