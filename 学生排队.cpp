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
	//�����ƶ� 
	for(i=1;i<=m;i++)
	{
		cin>>b[i][1]>>b[i][2];
	}
		//��ʼ������ 
	for(i=1;i<=n;i++)
	{
		a[i]=i;
	}
	//���� 
	
	for(i=1;i<=m;i++)
	{
		p=b[i][1];q=b[i][2];
		
		for(j=1;j<=n;j++) 
		{
			if(a[j] == p) 
				y = j;	//ԭλ�� 
		}
		//��λ�ü���Ҫ�� 
		x = y+q;	//��λ�� 	
			
		if(q >= 0){
			//����ƶ� 
			for(k=y;k<x;k++){
				a[k] = a[k+1];
			}
		}else{
			//��ǰ�ƶ�
			for(k=y;k>=x;k--) {
				a[k] = a[k-1];
			}
		}
		a[x] = p;
	}

	//�鿴��� 
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	
	return 0;
}
