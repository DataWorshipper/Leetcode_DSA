#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> a, seg;

    void buildtree(int l, int r, vector<int>& seg, int i, vector<int>& arr) {
        if (l == r) {
            seg[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        buildtree(l, mid, seg, 2 * i + 1, arr);
        buildtree(mid + 1, r, seg, 2 * i + 2, arr);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void update(int l, int r, vector<int>& seg, int val, int i, int idx) {
        if (l == r) {
            seg[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(l, mid, seg, val, 2 * i + 1, idx);
        } else {
            update(mid + 1, r, seg, val, 2 * i + 2, idx);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    int rangesum(int l, int r, int start, int end, int i) {
        if (end < l || start > r) return 0; 
        if (start <= l && r <= end) return seg[i]; 

        int mid = (l + r) / 2;
        return rangesum(l, mid, start, end, 2 * i + 1) +
               rangesum(mid + 1, r, start, end, 2 * i + 2);
    }

    NumArray(vector<int>& nums) {
        int n = nums.size();
        a = nums;
        seg.assign(4 * n, 0);
        if (n > 0) buildtree(0, n - 1, seg, 0, a);
    }
    
    void update(int index, int val) {
        a[index] = val;
        update(0, (int)a.size() - 1, seg, val, 0, index);
    }
    
    int sumRange(int left, int right) {
        return rangesum(0, (int)a.size() - 1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
