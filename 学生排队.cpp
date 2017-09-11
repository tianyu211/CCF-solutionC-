#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int a[1001]={0};
	int b[1001][3]={0};
	int i,j,k,p,q,m,n=0;
	int x,y;
	cin>>n>>m;
	//输入移动 
	for(i=1;i<=m;i++)
	{
		cin>>b[i][1]>>b[i][2];
	}
		//初始化数组 
	for(i=1;i<=n;i++)
	{
		a[i]=i;
	}
	//运算 
	
	for(i=1;i<=m;i++)
	{
		p=b[i][1];q=b[i][2];
		
		for(j=1;j<=n;j++) 
		{
			if(a[j] == p) 
				y = j;	//原位置 
		}
		//新位置计算要对 
		x = y+q;	//新位置 	
			
		if(q >= 0){
			//向后移动 
			for(k=y;k<x;k++){
				a[k] = a[k+1];
			}
		}else{
			//向前移动
			for(k=y;k>=x;k--) {
				a[k] = a[k-1];
			}
		}
		a[x] = p;
	}

	//查看输出 
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	
	return 0;
}
