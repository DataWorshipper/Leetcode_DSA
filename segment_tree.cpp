#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];
class SegmentTree{
    ll n;
    vector<ll>seg,lazy;
    public:
    SegmentTree(ll n1)
    {
      n=n1;
       seg.assign(4*n, 0);
       lazy.assign(4*n, 0);
    }
    public:
    void buildtree(ll l,ll r,vector<ll>&seg,ll i,vector<ll>&arr)
    {
        ll mid=(l+r)/2;
        if(l==r)
        {
            seg[i]=arr[r];
            return;
        }
        buildtree(l,mid,seg,2*i+1,arr);
        buildtree(mid+1,r,seg,2*i+2,arr);
        seg[i]=seg[2*i+1]+seg[2*i+2];
        
    }
    
    void update(ll l,ll r,vector<ll>&seg,ll val,ll i,ll idx)
    {
        ll mid=(l+r)/2;
        if(l==r)
        {
            seg[i]=val;
            return;
        }
        if(idx<=mid)
        {
            update(l,mid,seg,val,2*i+1,idx);
        }
        else
         update(mid+1,r,seg,val,2*i+2,idx);
         
          seg[i]=seg[2*i+1]+seg[2*i+2];
        
        
    }
   ll rangesum(ll l, ll r, ll start, ll end, ll i) {
        if (end < l || start > r) return 0; 
        if (start <= l && r <= end) return seg[i]; 

        ll mid = (l + r) / 2;
        return rangesum(l, mid, start, end, 2*i+1) +
               rangesum(mid+1, r, start, end, 2*i+2);
    }
    
    void range(ll start,ll end,ll l ,ll r,ll val,ll i)
    {
        if(lazy[i]!=0)
        {
            seg[i]+=(r-l+1)*lazy[i];
            if(l!=r)
            {
                lazy[2*i+1]+=lazy[i];
                lazy[2*i+2]+=lazy[i];
            }
            lazy[i]=0;}
            
            if(start>r ||end<l)
            return;
            
            if(start<=l &&end>=r)
            {
                seg[i]+=(r-l+1)*val;
                 if(l!=r)
            {
                lazy[2*i+1]+=val;
                lazy[2*i+2]+=val;
            }
            return;
                
            }
            ll mid=(l+r)/2;
            range(start,end,l,mid,val,2*i+1);
            range(start,end,mid+1,r,val,2*i+2);
             seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    
    
};