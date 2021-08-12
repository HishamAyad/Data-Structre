#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N= 1<<16;
int arr[N],n,q;
struct node
{
    int sum,pre,suff,mx;
}tree[N<<1];

node merge(const node &lf,const node &rt)
{
    node ret;
    ret.sum = lf.sum + rt.sum;
    ret.pre= max(lf.pre, lf.sum+rt.pre);
    ret.suff= max(rt.suff, rt.sum+lf.suff);
    ret.mx= max({rt.mx, lf.mx, lf.suff+rt.pre});
    return ret;
}

void init(int ni=0,int ns=0,int ne=n-1)
{
    if(ns==ne)
    {
        tree[ni].mx = tree[ni].sum = tree[ni].pre = tree[ni].suff = arr[ns];
        return ;
    }
    int lf = 2 * ni + 1, rt = lf +1, mid =  ns +  (ne - ns)/2;
    init(lf,ns,mid);
    init(rt,mid+1,ne);
    tree[ni]=merge(tree[rt],tree[lf]);
}

node Query (int qs,int qe,int ni=0,int ns=0,int ne=n-1)
{
    if(ne < qs || ns>qe ) return {0,-(int)1e9,-(int)1e9,-(int)1e9};
    if(ns>=qs && ne<= qe) return tree[ni];
    int lf = 2 * ni + 1, rt = lf +1, mid =  ns +  (ne - ns)/2;
    return merge(Query(qs,qe,lf,ns,mid), Query(qs,qe,rt,mid+1,ne));
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",arr+i);
    }
    init();
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n", Query(--l,--r).mx);
    }
    return 0;
}