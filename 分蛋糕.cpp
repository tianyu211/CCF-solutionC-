#include <stdio.h> 
#include<iostream>
using namespace std;
int main()
{
	int n,k;
	int a[1000] = {0};
	int temp;
	int all=0;
	int num=0;
	
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//得到a[]数组
	for(int i=0;i<n;i++)
	{
		
		all = a[i] + all;
		if(all >= k){
			all = 0;
			num++;
		}
		if(i == n-1 && all > 0)
		{
			num++;
		}
	}
	printf("%d",num);
	return 0;	
}
