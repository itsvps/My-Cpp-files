#include<iostream>
using namespace std;

class Box
{
	int width, hight;
	public:
	Box()
	{
		cout<<"Constructer called !!\n";
	}
	~Box()
	{
		cout<<"Destructer called !!\n";
	}
};

int main()
{
	Box obj1;
	return 0;
}