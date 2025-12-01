#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> prefixSums(const vector<int>& a) {
    int n = a.size();
    vector<ll> p(n+1,0);
    for(int i=0;i<n;i++) p[i+1]=p[i]+(ll)a[i];
    return p;
}

vector<int> slidingWindowMax(const vector<int>& a, int k) {
    int n=a.size();
    if(k==0) return {};
    deque<int> dq;
    vector<int> res;
    res.reserve(max(0,n-k+1));
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
        while(!dq.empty() && a[dq.back()]<=a[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) res.push_back(a[dq.front()]);
    }
    return res;
}

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n=chargeTimes.size();
        vector<ll> pref=prefixSums(runningCosts);

        auto ok=[&](int k){
            if(k==0) return true;
            if(k>n) return false;
            vector<int> mx=slidingWindowMax(chargeTimes,k);
            int w=n-k+1;
            for(int i=0;i<w;i++){
                ll s=pref[i+k]-pref[i];
                __int128 cost=(__int128)mx[i]+(__int128)k*s;
                if(cost<=budget) return true;
            }
            return false;
        };

        int low=0,high=n,ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ok(mid)) ans=mid, low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};
