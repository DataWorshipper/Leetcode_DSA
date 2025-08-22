#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<ll> seg, arr;

    void buildtree(ll l, ll r, ll i) {
        if (l == r) {
            seg[i] = l; 
            return;
        }
        ll mid = (l + r) / 2;
        buildtree(l, mid, 2*i+1);
        buildtree(mid+1, r, 2*i+2);

        ll leftIdx = seg[2*i+1];
        ll rightIdx = seg[2*i+2];
        seg[i] = (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
    }

    ll rangemax(ll l, ll r, ll ql, ll qr, ll i) {
        if (qr < l || ql > r) return -1; 
        if (ql <= l && r <= qr) return seg[i];

        ll mid = (l + r) / 2;
        ll leftIdx = rangemax(l, mid, ql, qr, 2*i+1);
        ll rightIdx = rangemax(mid+1, r, ql, qr, 2*i+2);

        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;
        return (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        arr.assign(heights.begin(), heights.end());
        seg.assign(4*n, 0);

        buildtree(0, n-1, 0);

        vector<int> ans(queries.size(), -1);

        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            if (a == b) {
                ans[i] = a;
                continue;
            }

            int maxidx = max(a, b);
            int minidx = min(a, b);

            if (heights[maxidx] > heights[minidx]) {
                ans[i] = maxidx;
                continue;
            }

            int l = maxidx+1, r = n-1;
            int temp_ans = -1;

            while (l <= r) {
                int mid = (l + r) / 2;
                ll rmiq = rangemax(0, n-1, maxidx+1, mid, 0);

                if (rmiq != -1 && heights[rmiq] > max(heights[maxidx], heights[minidx])) {
                    temp_ans = rmiq;
                    r = mid - 1; 
                } else {
                    l = mid + 1;
                }
            }
            ans[i] = temp_ans;
        }
        return ans;
    }
};
