#include<iostream>
using namespace std;

template <class T> T Max(T a, T b)
{
	return((a>b)?a:b);
}

int main()
{
	int i=4, j=3;
	float k=9.8, m=6.7;
	cout<<Max(i,j)<<endl;
	cout<<Max(14,15)<<endl;
	cout<<Max(k,m)<<endl;
	cout<<Max('a','b')<<endl;
	return 0;
}