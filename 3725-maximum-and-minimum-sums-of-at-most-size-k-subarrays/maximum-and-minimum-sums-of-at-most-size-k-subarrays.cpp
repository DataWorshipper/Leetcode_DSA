typedef long long ll;

class Solution {
public:
    ll calcMax(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pge(n), nge(n);
        {
            vector<int> st;
            for(int i=0;i<n;i++){
                while(!st.empty() && nums[st.back()] <= nums[i]) st.pop_back();
                pge[i] = st.empty() ? -1 : st.back();
                st.push_back(i);
            }
        }
        {
            vector<int> st;
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && nums[st.back()] < nums[i]) st.pop_back();
                nge[i] = st.empty() ? n : st.back();
                st.push_back(i);
            }
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll L = i - pge[i] - 1;
            ll R = nge[i] - i - 1;
            ll limit = min(L, (ll)k-1);
            ll x0 = k - (R );

            ll a = min(limit, x0 - 1);
            ll sum1 = (a >= 0 ? (a + 1) * (R + 1) : 0);

            ll b = max(0LL, x0);
            ll sum2 = 0;
            if(b <= limit){
                ll t = limit - b + 1;
                ll first = k - b;
                ll last  = k - limit;
                sum2 = t * (first + last) / 2;
            }

            ll ways = sum1 + sum2;
            ans += ways * nums[i];
        }
        return ans;
    }

    ll calcMin(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pse(n), nse(n);
        {
            vector<int> st;
            for(int i=0;i<n;i++){
                while(!st.empty() && nums[st.back()] >= nums[i]) st.pop_back();
                pse[i] = st.empty() ? -1 : st.back();
                st.push_back(i);
            }
        }
        {
            vector<int> st;
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && nums[st.back()] > nums[i]) st.pop_back();
                nse[i] = st.empty() ? n : st.back();
                st.push_back(i);
            }
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll L = i - pse[i] - 1;
            ll R = nse[i] - i - 1;
            ll limit = min(L, (ll)k-1);
            ll x0 = k - (R );

            ll a = min(limit, x0 - 1);
            ll sum1 = (a >= 0 ? (a + 1) * (R + 1) : 0);

            ll b = max(0LL, x0);
            ll sum2 = 0;
            if(b <= limit){
                ll t = limit - b + 1;
                ll first = k - b;
                ll last  = k - limit;
                sum2 = t * (first + last) / 2;
            }

            ll ways = sum1 + sum2;
            ans += ways * nums[i];
        }
        return ans;
    }

    long long minMaxSubarraySum(vector<int>& nums, int k) {
        return calcMax(nums, k) + calcMin(nums, k);
    }
};
