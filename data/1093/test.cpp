#include <cstdlib>
#include <cstdio>

using namespace std;

int num[11111];

int main()
{
	freopen("data1.in","r",stdin);
	freopen("data1.out","w",stdout);
    int i,j,k,n;
    num[1] = 1;
    for(i = 2,j = 1; j <= 10000; ++i)
    {
        k = i;
        while(k)
        {
            j++;
            k--;
            num[j] = num[j-1] + i;
        }
    }
    while(~scanf("%d",&n) && n)
    {
        printf("%d %d\n",n,num[n]);
    }
    return 0;
}
