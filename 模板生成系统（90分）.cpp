#include <bits/stdc++.h>
using namespace std;

vector<string> tem; //模板保存 
map<string,string> dict;    //键值对字典 

int m,n;
string s;
string key,val;

//字符串替换处理 
void strhandle(string str){
    int begin,end,len;
    string k,v;
    while(str.find("{{ ") != string::npos){
        begin = str.find("{{ ") + 3;//由于 {{ 占用了三个字符  
        len = str.find(" }}");
        len -= begin;   //总长度等于末尾位置减去起始位置 
        k = str.substr(begin,len);  //用于查找的键
        if(dict.find(k) == dict.end())
            v = "";
        else 
            v = dict.find(k)->second;   //真正的字典值
        str.replace(begin-3,len+6,v);       //替换字符串  
    }
    cout<<str<<endl;
    return;
} 

int main(){
    //freopen("input.txt","r",stdin);   //!!!!!!!!!!!!!!!!!!!
    
    cin>>m>>n;
    getchar();  //要给出一个空行 
    for(int i=1;i<=m;i++) {
        getline(cin,s);     //读取到s中
        tem.push_back(s);       //放到tem中 
        //cout<<i<<' '<<s; 
    }
    //获取键值对字典 
    for(int i=1;i<=n;i++){
        getline(cin,s);
        int pos = s.find_first_of(" "); //找到空格的位置 
        // 其实substr底层应该是for(i=0;i<pos;i++) 
        key = s.substr(0,pos);  //区间 [0,pos) 不包括pos位置的字符 
        val = s.substr(pos+1,s.length());   //不包括pos位置的字符到结束 
        while (val.find("\"") != string::npos) val.replace(val.find("\""),1,""); //处理双引号 
        //键值对插入map      
        dict.insert(make_pair(key,val));
    }
    
    //开始处理模板替换
    for(int i=0;i<tem.size();i++){
        //一行一行处理 
        s = tem[i];
        strhandle(s);
    }
    
    return 0;
}
