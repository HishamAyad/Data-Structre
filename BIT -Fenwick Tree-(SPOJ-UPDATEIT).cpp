#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=10005;

struct BIT
{
    int tree[N];
    void init(int n)
    {
        fill(tree,tree+n,0);
    }
    void add(int pos,int val)
    {
        for(++pos;pos<=N;pos+=(pos&(-pos)))
        {
            tree[pos-1]+=val;
        }
    }
    int get (int pos)
    {
        int ret=0;
        for(++pos;pos;pos-=(pos&(-pos)))
        {
            ret+=tree[pos-1];
        }
        return ret;
    }
}bit;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        bit.init(n);
        for(int j=0;j<k;++j)
        {
            int l,r,val;
            scanf("%d%d%d",&l,&r,&val);
            bit.add(l,val);
            bit.add(r+1,-val);
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int pos;
            scanf("%d",&pos);
            printf("%d\n",bit.get(pos));
        }

    }
    return 0;
}