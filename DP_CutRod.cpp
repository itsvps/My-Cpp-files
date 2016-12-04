#include<iostream>
#include<limits>
using namespace std;

int Max(int a, int b)
{
	return a > b ? a : b;
}

int CutRod(int price[], int n)
{
	if(n == 0)
		return 0;
	int max_len = INT_MIN;		// max_len = 0 ; should also be fine. 
	for(int i=1; i<=n; i++)
	{
		max_len = Max(max_len, price[i-1] + CutRod(price,n-i));
	}
	return max_len;
}

int main()
{
	int price[] = {1,6,3,4,5};	// price of the rod pieces
	int n = 5;				// Length of the rod
	cout<<"\nMaximum amount can be gained from the rod is : "<<CutRod(price,n)<<endl;
	return 0;
}