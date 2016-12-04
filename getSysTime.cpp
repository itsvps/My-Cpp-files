#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	char *ch ;
	time_t now = time(0);
	ch = ctime(&now);
	cout<<"time is "<<ch;
	return 0;
}