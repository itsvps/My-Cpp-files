#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int main()
{
	cout<<"Initial size of vector : "<<v.size()<<endl;
	v.push_back(5);
	cout<<"\n v = "<<v[0]<<endl;
	cout<<"Size of vector : "<<v.size()<<endl;
	for(int i=0;i<5;i++)
	{
		v.push_back(i*2);
	}
	cout<<"Size of vector : "<<v.size()<<endl;
	for(int i=0;i<6;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}