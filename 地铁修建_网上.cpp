#include <bits/stdc++.h>

using namespace std;  
int n,m;  
struct node{  
    int f,to,w;  
    friend bool operator < (const node& a,const node& b){  
        return a.w<b.w;  
    }  
};  
node k[200010];  
int parents[200010];  
void init(int x){  
    for(int i=0;i<=x;++i) parents[i]=i;  
}  
int find(int x){  
    if(parents[x]==x) return x;  
    else return parents[x]=find(parents[x]);  
}  
int ans=0;  
void slove(){  
    for(int i=0;i<m;++i){  
        int x=find(k[i].f);  
        int y=find(k[i].to);  
        if(x!=y){  
            if(x>y) parents[x]=y;  
            else parents[y]=x;  
            ans=max(ans,k[i].w);
        }  
        if(find(n)==1) break;  
    }  
}  
int main(){  
	freopen("input/subway.txt","r",stdin);
    scanf("%d %d",&n,&m);  
    for(int i=0;i<m;++i){  
        scanf("%d%d%d",&k[i].f,&k[i].to,&k[i].w);  
    }  
    init(n);  
    sort(k,k+m);  //从k到k+m 从小到大排序 
    slove();  
    printf("%d\n",ans);  
    return 0;  
}  
