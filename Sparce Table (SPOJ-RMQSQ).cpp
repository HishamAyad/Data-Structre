#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5,LG=17;
int arr[N],sp[LG][N],lg[N],n;

void pre()
{
    lg[0]=-1;
    for(int i=0;i<N-1;++i)
    {
        sp[0][i]=i;
        lg[i+1]=lg[i]+ !(i&(i+1));
    }
}

void bulidSp()
{
    static int dummy = (pre(),0);
    for(int j=1;(1<<j)<=n;++j)
    {
        for(int i=0 ; i+(1<<j) <=n ;++i)
        {
            int a=sp[j-1][i];
            int b=sp[j-1][i+ (1<< (j-1) ) ];
            sp[j][i]= arr[a]<arr[b] ? a : b;
        }
    }
}

int getInd(int st,int en)
{
    int sz=en-st+1;
    int l=lg[sz];
    int a=sp[l][st],b=sp[l][en-(1<<l)+1];
    return arr[a] <arr[b] ? a:b;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",arr+i);
    bulidSp();
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int st,en;
        scanf("%d%d",&st,&en);
        printf("%d\n",arr[getInd(st,en)]);
    }
    return 0;
}