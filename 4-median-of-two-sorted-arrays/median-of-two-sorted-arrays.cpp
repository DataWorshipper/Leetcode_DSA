class Solution {
public:
long long countLE(long long x, vector<int>& a, vector<int>& b) {
    return upper_bound(a.begin(), a.end(), x) - a.begin()
         + upper_bound(b.begin(), b.end(), x) - b.begin();
}
long long kth(vector<int>& a, vector<int>& b, int k) {
   long long low, high;
if (a.empty()) return b[k-1];
if (b.empty()) return a[k-1];

    low = min(a[0], b[0]);
    high = max(a.back(), b.back());


    long long ans = low;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (countLE(mid, a, b) >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int total = m + n;
  if (m == 0 && n == 0) return 0.0;
    if (total % 2 == 1) {
        return kth(nums1, nums2, total/2 + 1);
    } else {
        long long a = kth(nums1, nums2, total/2);
        long long b = kth(nums1, nums2, total/2 + 1);
        return (a + b) / 2.0;
    }
}

    };
