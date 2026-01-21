class Solution {
public:
    vector<int> nums;
    int n;

    long long countAtMost(int x) {
        unordered_map<int,int> mpp;
        int l = 0;
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            mpp[nums[r]]++;

            while ((int)mpp.size() > x) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }

            ans += (r - l + 1);
        }
        return ans;
    }

    int medianOfUniquenessArray(vector<int>& a) {
        nums = a;
        n = nums.size();

     
        long long total = 1LL * n * (n + 1) / 2;

  
        long long need;
        if (total % 2 == 1) {
            need = (total + 1) / 2;
        } else {
            need = total / 2;
        }

    
        unordered_set<int> s(nums.begin(), nums.end());
        int maxDistinct = s.size();

        int low = 1, high = maxDistinct, ans = maxDistinct;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (countAtMost(mid) >= need) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
