#include <bits/stdc++.h>
using namespace std;

vector<string> tem; //ģ�屣�� 
map<string,string> dict;    //��ֵ���ֵ� 

int m,n;
string s;
string key,val;

//�ַ����滻���� 
void strhandle(string str){
    int begin,end,len;
    string k,v;
    while(str.find("{{ ") != string::npos){
        begin = str.find("{{ ") + 3;//���� {{ ռ���������ַ�  
        len = str.find(" }}");
        len -= begin;   //�ܳ��ȵ���ĩβλ�ü�ȥ��ʼλ�� 
        k = str.substr(begin,len);  //���ڲ��ҵļ�
        if(dict.find(k) == dict.end())
            v = "";
        else 
            v = dict.find(k)->second;   //�������ֵ�ֵ
        str.replace(begin-3,len+6,v);       //�滻�ַ���  
    }
    cout<<str<<endl;
    return;
} 

int main(){
    //freopen("input.txt","r",stdin);   //!!!!!!!!!!!!!!!!!!!
    
    cin>>m>>n;
    getchar();  //Ҫ����һ������ 
    for(int i=1;i<=m;i++) {
        getline(cin,s);     //��ȡ��s��
        tem.push_back(s);       //�ŵ�tem�� 
        //cout<<i<<' '<<s; 
    }
    //��ȡ��ֵ���ֵ� 
    for(int i=1;i<=n;i++){
        getline(cin,s);
        int pos = s.find_first_of(" "); //�ҵ��ո��λ�� 
        // ��ʵsubstr�ײ�Ӧ����for(i=0;i<pos;i++) 
        key = s.substr(0,pos);  //���� [0,pos) ������posλ�õ��ַ� 
        val = s.substr(pos+1,s.length());   //������posλ�õ��ַ������� 
        while (val.find("\"") != string::npos) val.replace(val.find("\""),1,""); //����˫���� 
        //��ֵ�Բ���map      
        dict.insert(make_pair(key,val));
    }
    
    //��ʼ����ģ���滻
    for(int i=0;i<tem.size();i++){
        //һ��һ�д��� 
        s = tem[i];
        strhandle(s);
    }
    
    return 0;
}
