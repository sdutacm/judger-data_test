#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>
using namespace std;


int table[16]={0xf888,0xf444,0xf222,0xf111,0x8f88,0x4f44,0x2f22,0x1f11,
                0x88f8,0x44f4,0x22f2,0x11f1,0x888f,0x444f,0x222f,0x111f};

int flag[65536];
int con[65536];
int parent[65536];
int step[65536];

int s=0;
queue<int> q;
stack<int> path;
int BFS();

int main()
{
    int i,j;
    string str;
    for(i=0;i<4;i++)
    {
        cin>>str;
        for(j=0;j<4;j++){
            if(str[j]=='-'){//'-'==0
                s=s<<1;
            }else{
                s=s<<1|1;
            }
        }
    }

    int result;
    result = BFS();
    int n = step[result];


    for(i=0;i<n;i++){
        path.push(con[result]);
        result = parent[result];
    }
    cout<<path.size()<<endl;
    while(!path.empty()){
        result = path.top();
        path.pop();
        cout<<result/4+1<<" "<<result%4+1<<endl;
    }
    return 0;
}

int BFS()
{
    int i,j;
    int temp1,temp2;
    memset(flag,false,sizeof(flag));
    memset(step,0,sizeof(step));
    memset(con,-1,sizeof(con));
    memset(parent,-1,sizeof(parent));
    if(s==0){
        return 0;
    }else {
        flag[s]==true;
        q.push(s);
        while(!q.empty()){
            temp1 = q.front();
            q.pop();
            for(i=0;i<16;i++){
                temp2=temp1^table[i];

                if(!flag[temp2]){
                    flag[temp2]=true;
                    step[temp2]=step[temp1]+1;
                    con[temp2] = i;
                    parent[temp2] = temp1;
                    q.push(temp2);
                }
                if(temp2==0){
                    return temp2;
                }
            }
        }
    }
    return -1;
}
