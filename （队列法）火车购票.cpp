#include <bits/stdc++.h>
using namespace std;
queue<int> m[21];
int n,num;
int i,j,row;

int main(){
	//freopen("input/trainticket.txt","r",stdin);	//模拟输入，记得提交前关闭 
	for(row=1,j=1;row<=20;row++){	//初始化队列 
		m[row].push(j++);
		m[row].push(j++);
		m[row].push(j++);
		m[row].push(j++);
		m[row].push(j++);
	}
	
	cin>>n;	//购票行数 
	
	for(i=1;i<=n;i++){
		cin>>num;	//购票数
		bool find = false;
		//查找连续座位 
		for(row=1;row<=20;row++){
			if(m[row].size() >= num){		//当前队列可用 
				find = true;	//已找到位置 
				for(j=0;j<num;j++){
					cout<<m[row].front()<<" ";
					m[row].pop();	//删除最早进入队列的元素 
				}
				break;	
			}
		}
		//不连续座位
		if(!find){
			for(row=1;row<=20;row++){
				while(!m[row].empty() && num>0){	//一直判断到num为0 
					cout<<m[row].front()<<' ';
					m[row].pop();
					num--;
				}
			}
		}	
		cout<<endl;	 
	}
	return 0;
}
