#include<iostream>
using namespace std;

int Count(int S[], int m, int n)
{
	if(n == 0)
		return 1;
	if(n < 0)
		return 0;
	if(m <= 0 && n >= 1)
		return 0;
	return Count(S,m-1,n) + Count(S,m,n-S[m-1]);
}

int main()
{
	int arr[] = {1,2,3};
	int m = 3, n = 4;
	cout<<"\n Number of ways is : "<<Count(arr,m,n)<<endl;
	return 0;
}