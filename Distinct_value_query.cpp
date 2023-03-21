#include <bits/stdc++.h>
using namespace std;
#define ll        long long int

const ll maxN=2e5+10;
const ll BLOCK=555;
struct query{
    ll l,r,i;
};
query Q[maxN];
ll arr[maxN],ans[maxN];
ll freq[maxN];

ll cnt=0;
bool comp(query a,query b){
   if(a.l/BLOCK !=b.l/BLOCK) 
      return a.l/BLOCK< b.l/BLOCK;
   return a.r<b.r;
}

void add(ll pos)
{
    freq[arr[pos]]++;
    if(freq[arr[pos]]==1)cnt++;
}

void remove(ll pos)
{
    
    freq[arr[pos]]--;
    if(freq[arr[pos]]==0)cnt--;
}

int main()
{
    ll n,q;
    cin>>n>>q;
    map<ll,ll> mpp;
    ll val=1;
    // coordinate compression
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(mpp.find(arr[i])==mpp.end())
        {
            mpp[arr[i]]=val;
            arr[i]=val;
            val++;
        }
        else
        {
            arr[i]=mpp[arr[i]];
        }
    }

    for(int i=0;i<q;i++)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].i=i;
        Q[i].l--;
        Q[i].r--;
    }
    
    sort(Q,Q+q,comp);

    ll ML=0,MR=-1;
    for(int i=0;i<q;i++)
    {
        ll L=Q[i].l;
        ll R=Q[i].r;

        while(ML>L)
        {
            ML--;
            add(ML);
        }

        while(MR<R)
        {
            MR++;
            add(MR);
        }

        while(ML<L)
        {
            remove(ML);
            ML++;
        }

        while(MR>R)
        {
            remove(MR);
            MR--;
        }

        ans[Q[i].i]=cnt;

    }

    for(int i=0;i<q;i++)
    cout<<ans[i]<<"\n";
}
