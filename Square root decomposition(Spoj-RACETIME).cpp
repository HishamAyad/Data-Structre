#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5,SQ=175;
int arr[N],pre[N],n,sq;

int Query(int st,int en,int val)
{
    int stB=st/sq,enB=en/sq;
    int ret=0;
    if(stB==enB)
    {
        for(int i=st;i<=en;++i)
        {
            ret+=(arr[i]<=val);
        }
        return ret;
    }
    for(int i=st;i<(stB+1)*sq;++i)
    {
        ret+=(arr[i]<=val);
    }
    for(int i=(enB*sq);i<=en;++i)
    {
        ret+=(arr[i]<=val);
    }
    for(int i=(stB+1);i<enB;++i)
    {
        ret += upper_bound(pre+(i*sq),pre+(i+1)*sq,val)-(pre+(i*sq));
    }
    return ret;
}

void Modify(int pos,int val)
{
    int bId=pos/sq;
    int bSt=bId*sq;
    int bEn=min(n,bSt+sq);
    int ind= lower_bound(pre+bSt,pre+bEn,arr[pos])-pre;
    arr[pos]=val;
    pre[ind]=val;
    sort(pre+bSt,pre+bEn);
}

int main()
{
    int q;
    scanf("%d%d",&n,&q);
    sq=ceil(sqrt(n));
    for(int i=0,j=0;i<n;i+=sq,++j)
    {
        int k;
        for(k=0;k<sq && k+i<n;k++)
        {
            scanf("%d",arr+i+k);
            pre[i+k]=arr[i+k];
        }
        sort(pre+j*sq,pre+j*sq+k);
    }
    while(q--)
    {
        int l,r,val,pos;
        char c;
        scanf(" %c",&c);
        if(c=='C')
        {
            scanf("%d%d%d",&l,&r,&val);
            printf("%d\n", Query(--l,--r,val));
        }
        else
        {
            scanf("%d%d",&pos,&val);
            Modify(--pos,val);
        }
    }
    return 0;
}