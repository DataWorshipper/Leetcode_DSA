#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

class Solution {
public:
    int totalStrength(vector<int>& a) {
        int n = a.size();
        vector<ll> pre(n+1, 0), pre2(n+2, 0);
        for (int i = 0; i < n; ++i) pre[i+1] = (pre[i] + a[i]) % MOD;
        for (int i = 0; i <= n; ++i) pre2[i+1] = (pre2[i] + pre[i]) % MOD;

        vector<int> L(n), R(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && a[st.top()] > a[i]) st.pop();
            L[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n-1; i >= 0; --i) {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            R[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll leftCnt = i - L[i];
            ll rightCnt = R[i] - i;

            ll sumRight = (pre2[R[i] + 1] - pre2[i + 1] + MOD) % MOD; 
            ll sumLeft  = (pre2[i + 1] - pre2[L[i] + 1] + MOD) % MOD; 

            ll term = ( (leftCnt % MOD) * sumRight % MOD - (rightCnt % MOD) * sumLeft % MOD + MOD ) % MOD;
            ll contrib = ( (ll)a[i] % MOD ) * term % MOD;
            ans = (ans + contrib) % MOD;
        }

        return (int)ans;
    }
};
