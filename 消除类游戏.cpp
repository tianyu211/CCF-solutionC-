#include <bits/stdc++.h>
using namespace std;
	int m,n;
	int i,j;
	int row=0,col=0;
	int a[32][32]={10};
void p(){
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}

int main(){
		
	//freopen("xclyx.txt","r",stdin);
		
	cin>>n>>m;	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	//�м��� 
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++){
			
			if(a[i][j] == a[i][j+1]){
				row++;
			}else{
				if(row >= 2){	//���������ֻ���������Ⱥ� 
					for(int x=j;x>=j-row;x--)
					a[i][x]=0;
				}
				row = 0;
			}
		}
		row=0;
	}
	//�м���ʱ��m�ǲ�������n���Ա��� 
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++){
			 if(a[i][j] == a[i+1][j]){
				col++;
			}else{
				if(col >= 2){
					for(int x=i;x>=i-col;x--)
						a[x][j]=0;
				}
				col=0;
			}
		}
		col=0;
	}
	
	p();
	return 0;
}
