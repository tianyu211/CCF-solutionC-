#include <bits/stdc++.h> 
using namespace std;
const int N = 1005;	//����С 
const int DIRECTSIZE = 4;	//���������ĸ����� 
int order[N][N]; 	//ĳ����λ�õĶ�����
int visited[N][N] ;		//ĳ�����Ƿ��Ѿ����ʹ� 

struct direct{	//����һ�����ڷ���Ľṹ�� 
	int drow,dcol;
}direct[DIRECTSIZE] = {{-1,0},{1,0},{0,-1},{0,1}};

struct node{	//���ڼ�¼ÿ���������˶��ٲ� 
	int row,col,step;
	node(){}
	node(int r,int c,int s){row = r,col = c,step = s;}
};

queue<node> q;	// ����һ��node���� 
int coord = 0;	//���������� 
long long ans = 0;	//�� 

//����������� 
void bfs(int n){
	//v���������������ݣ������ߵ�ĳ������ʱ�Ĳ���
	//front������ʱ���� 
	node front,v;	
	//�����������Ԫ�أ���һֱִ�� 
	while(!q.empty()){
		front = q.front();	//ȡ��q�е�һ��Ԫ��
		q.pop();	//ɾ��q�е�һ��Ԫ�� 
		//�����õ���ĸ���λ 
		for(int i=0;i<DIRECTSIZE;i++){	//ע�������±��Ǵ�0��ʼ�� 
			v.row = direct[i].drow + front.row;	
			v.col = direct[i].dcol + front.col;
			v.step = front.step + 1; //����λ�ü�һ��
			
			//�ж��Ƿ񳬳�����ͼ��С 
			if(v.row < 1 || v.row > n || v.col < 1 || v.col > n) 
				continue;	//��������ѭ��
			//�Ƿ��Ѿ������� 
			if(visited[v.row][v.col]) 
				continue;	
			
			//����ж��� 
			if(order[v.row][v.col] > 0){
				//��Ϊ ÿһ������ÿ��һ����λ�ľ�����Ҫ����1��Ǯ 
				ans += v.step * order[v.row][v.col];	//�п�������㲻ֹһ������ 
				visited[v.row][v.col] = 1;	//���Բ��� 
				coord--;		//���������� 
				if(coord == 0)
					return;	//���� 
			}
			
			//���������ĵص���
			visited[v.row][v.col] = 1;
			//��û���ߵ�ͷ��v�Ž�����
			q.push(v);
		}	
	}
}


int main(){
	//freopen("input.txt","r",stdin);	//ֱ�ӱ��ض�ȡ���� 
	
	int n,m,k,d,x,y,c; 	//���Խ��յı��� 
	//��ʼ������ 
	memset(order,0,sizeof(order));
	memset(visited,0,sizeof(visited));
	//����
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++){//����ֵ����꣬�ֵ����겻������ ����������Ϊtrue
		cin>>x>>y;
		q.push(node(x,y,0));	//�ѷֵ�����ѹ������У��Դ�Ϊ����  //queue<node> q;  
		visited[x][y] = 1;
	} 
	for(int i=1;i<=k;i++) {
		cin>>x>>y;	//��������
		cin>>c; 	//�����궩������ 
		if(order[x][y] == 0)	//���������û��������
			 coord++;	//emmmmmmmmmmmm
		order[x][y] += c;	//�Ѷ�������������λ�� 
	}
	for(int i=1;i<=d;i++) {
		cin>>x>>y;
		visited[x][y] = 1;	//�Ѳ���ͨ����Ҳ��ǳ������� 
	}
	
	//��������������� 
	bfs(n);	
	
	cout<<ans<<endl; 
	
	return 0;
}



