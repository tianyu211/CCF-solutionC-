#include <bits/stdc++.h>
using namespace std;
queue<int> m[21];
int n,num;
int i,j,row;

int main(){
	//freopen("input/trainticket.txt","r",stdin);	//ģ�����룬�ǵ��ύǰ�ر� 
	for(row=1,j=1;row<=20;row++){	//��ʼ������ 
		m[row].push(j++);
		m[row].push(j++);
		m[row].push(j++);
		m[row].push(j++);
		m[row].push(j++);
	}
	
	cin>>n;	//��Ʊ���� 
	
	for(i=1;i<=n;i++){
		cin>>num;	//��Ʊ��
		bool find = false;
		//����������λ 
		for(row=1;row<=20;row++){
			if(m[row].size() >= num){		//��ǰ���п��� 
				find = true;	//���ҵ�λ�� 
				for(j=0;j<num;j++){
					cout<<m[row].front()<<" ";
					m[row].pop();	//ɾ�����������е�Ԫ�� 
				}
				break;	
			}
		}
		//��������λ
		if(!find){
			for(row=1;row<=20;row++){
				while(!m[row].empty() && num>0){	//һֱ�жϵ�numΪ0 
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
