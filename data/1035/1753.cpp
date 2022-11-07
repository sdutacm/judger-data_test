#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int conv[16]={0xc800,0xe400,0x7200,0x3100,0x1c80,0x4e40,0x2720,0x1310,
			0x08c8,0x04e4,0x0272,0x0131,0x008c,0x004e,0x0027,0x0013};
int map = 0;
queue<int> q;
bool flag[65535];
int step[65535];
int BFS()
{
    int i;
    memset(flag,false,sizeof(flag));
    memset(step,0,sizeof(step));
    int temp1,temp2;
    if(map==0||map==65535){
        return 0;
    }else{
        flag[map]=true;
        q.push(map);
        while(!q.empty()){
            temp1 = q.front();
            q.pop();
            for(i=0;i<16;i++){
                temp2 = temp1^conv[i];

                if(!flag[temp2])
                {
                    flag[temp2] = true;
                    step[temp2]=step[temp1]+1;
                    q.push(temp2);
                }
                if(temp2==0||temp2==65535)
                {
                    return step[temp2];
                }
            }
        }
    }
    return -1;
}

int main()
{
    int i,j,k;
    string str;
    for(i=0;i<4;i++)
    {
        cin>>str;
        for(j=0;j<4;j++){
            if(str[j]=='b')//b==0
                map = map<<1;
            else{//w==1
                map = map<<1|1;
            }
        }
    }
    int ss = BFS();
    if(ss==-1){
        cout<<"Impossible"<<endl;
    }else{
        cout<<ss<<endl;
    }
    return 0;
}
