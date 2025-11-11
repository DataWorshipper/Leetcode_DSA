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

            ll x0 = k-1-R;

            ll a = min(limit, x0-1);
            ll cnt1 = (a >= 0 ? a+1 : 0);
            ll sum1 = cnt1 * R;

            ll l = max(0LL, x0);
            ll sum2 = 0;
            if(l <= limit){
                ll cnt2 = limit - l + 1;
                ll first = k-1-l;
                ll last = k-1-limit;
                sum2 = cnt2 * (first + last) / 2;
            }

            ll ways = (limit + 1) + sum1 + sum2;
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

            ll x0 = k-1-R;

            ll a = min(limit, x0-1);
            ll cnt1 = (a >= 0 ? a+1 : 0);
            ll sum1 = cnt1 * R;

            ll l = max(0LL, x0);
            ll sum2 = 0;
            if(l <= limit){
                ll cnt2 = limit - l + 1;
                ll first = k-1-l;
                ll last = k-1-limit;
                sum2 = cnt2 * (first + last) / 2;
            }

            ll ways = (limit + 1) + sum1 + sum2;
            ans += ways * nums[i];
        }
        return ans;
    }

    long long minMaxSubarraySum(vector<int>& nums, int k) {
        return calcMax(nums, k) + calcMin(nums, k);
    }
};
