#include <bits/stdc++.h> 
using namespace std;
long int a[2561][1441]={0};

void p(){
	for(int i=0;i<=10;i++){
			for(int j=0;j<=10;j++)
		cout<<a[i][j]<<' ';
	cout<<endl;
	}
	cout<<endl;
}
int main(){
	
	//freopen("ck.txt","r",stdin);//!!!!!!!!!!!!!!!!!!!!!!!
	
	int n,m,w;
	int x,y;
	int x1[11],y1[11],x2[11],y2[11];	//用以保存点击的坐标 
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		w=i+1;
		cin>>x1[w]>>y1[w]>>x2[w]>>y2[w];	//注意：坐标最小可以为0 
		for(int j=x1[w];j<=x2[w];j++)
			for(int k=y1[w];k<=y2[w];k++)
				a[j][k]=w;	//由小到大赋值，最终数为最大值 
	}

	for(int i=0;i<m;i++){
 		cin>>x>>y;
		if(a[x][y] != 0){
			cout<<a[x][y]<<endl;
			w=a[x][y];
			for(int j=x1[w];j<=x2[w];j++)
				for(int k=y1[w];k<=y2[w];k++)
					a[j][k]=w;
		}
		else
			cout<<"IGNORED"<<endl;
//		p();
	}	
	
	return 0;
}

