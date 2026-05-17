class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {

        const long long P = 911382323LL;

        const long long MOD1 = 1000000007LL;
        const long long MOD2 = 1000000009LL;

        int n = s.size();

        vector<long long> pref1(n + 1, 0);
        vector<long long> pref2(n + 1, 0);

        vector<long long> power1(n + 1, 1);
        vector<long long> power2(n + 1, 1);

        for(int i = 0; i < n; i++)
        {
            int val = s[i] - 'A' + 1;

            pref1[i + 1] =
                (pref1[i] * P + val) % MOD1;

            pref2[i + 1] =
                (pref2[i] * P + val) % MOD2;

            power1[i + 1] =
                (power1[i] * P) % MOD1;

            power2[i + 1] =
                (power2[i] * P) % MOD2;
        }

        int l = 0;
        int r = 0;

        map<pair<long long,long long>, int> mpp;

        vector<string> ans;

        while(r < n)
        {
            while(r - l + 1 == 10)
            {
                long long h1 =
                (
                    pref1[r + 1]
                    - (pref1[l] * power1[r - l + 1]) % MOD1
                    + MOD1
                ) % MOD1;

                long long h2 =
                (
                    pref2[r + 1]
                    - (pref2[l] * power2[r - l + 1]) % MOD2
                    + MOD2
                ) % MOD2;

                pair<long long,long long> hash = {h1, h2};

                mpp[hash]++;

                if(mpp[hash] == 2)
                {
                    ans.push_back(s.substr(l, 10));
                }

                l++;
            }

            r++;
        }

        return ans;
    }
};