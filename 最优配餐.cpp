#include <bits/stdc++.h> 
using namespace std;
const int N = 1005;	//最大大小 
const int DIRECTSIZE = 4;	//上下左右四个方向 
int order[N][N]; 	//某坐标位置的订单数
int visited[N][N] ;		//某坐标是否已经访问过 

struct direct{	//定义一个关于方向的结构体 
	int drow,dcol;
}direct[DIRECTSIZE] = {{-1,0},{1,0},{0,-1},{0,1}};

struct node{	//用于记录每个坐标走了多少步 
	int row,col,step;
	node(){}
	node(int r,int c,int s){row = r,col = c,step = s;}
};

queue<node> q;	// 定义一个node队列 
int coord = 0;	//总坐标数量 
long long ans = 0;	//答案 

//广度优先搜索 
void bfs(int n){
	//v用来保存所有数据，包括走到某点坐标时的步数
	//front用以临时保存 
	node front,v;	
	//如果队列中有元素，就一直执行 
	while(!q.empty()){
		front = q.front();	//取出q中第一个元素
		q.pop();	//删除q中第一个元素 
		//搜索该点的四个方位 
		for(int i=0;i<DIRECTSIZE;i++){	//注意这里下标是从0开始的 
			v.row = direct[i].drow + front.row;	
			v.col = direct[i].dcol + front.col;
			v.step = front.step + 1; //坐标位置加一步
			
			//判断是否超出方格图大小 
			if(v.row < 1 || v.row > n || v.col < 1 || v.col > n) 
				continue;	//跳出本次循环
			//是否已经搜索过 
			if(visited[v.row][v.col]) 
				continue;	
			
			//如果有订单 
			if(order[v.row][v.col] > 0){
				//因为 每一个订单每走一个单位的距离需要花费1块钱 
				ans += v.step * order[v.row][v.col];	//有可能坐标点不止一个订单 
				visited[v.row][v.col] = 1;	//可以不加 
				coord--;		//坐标数减少 
				if(coord == 0)
					return;	//结束 
			}
			
			//把搜索过的地点标记
			visited[v.row][v.col] = 1;
			//把没有走到头的v放进队列
			q.push(v);
		}	
	}
}


int main(){
	//freopen("input.txt","r",stdin);	//直接本地读取数据 
	
	int n,m,k,d,x,y,c; 	//用以接收的变量 
	//初始化变量 
	memset(order,0,sizeof(order));
	memset(visited,0,sizeof(visited));
	//输入
	cin>>n>>m>>k>>d;
	for(int i=1;i<=m;i++){//输入分店坐标，分店坐标不能搜索 ，所以设置为true
		cin>>x>>y;
		q.push(node(x,y,0));	//把分店坐标压入队列中，以此为基础  //queue<node> q;  
		visited[x][y] = 1;
	} 
	for(int i=1;i<=k;i++) {
		cin>>x>>y;	//订单坐标
		cin>>c; 	//该坐标订单数量 
		if(order[x][y] == 0)	//如果该坐标没有搜索过
			 coord++;	//emmmmmmmmmmmm
		order[x][y] += c;	//把订单数赋给坐标位置 
	}
	for(int i=1;i<=d;i++) {
		cin>>x>>y;
		visited[x][y] = 1;	//把不能通过的也标记成已搜索 
	}
	
	//开启广度优先搜索 
	bfs(n);	
	
	cout<<ans<<endl; 
	
	return 0;
}



