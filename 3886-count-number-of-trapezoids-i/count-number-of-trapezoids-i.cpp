typedef long long ll;
const int MOD=1e9+7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<ll,ll>mpp;
        for(auto it:points)
        {
            int x=it[0];
            int y=it[1];
            mpp[y]++;
        }

        vector<long long>freq;
        for(auto it:mpp)
        {   int f=it.second;
            if(it.second>=2)
            freq.push_back((long long)f*(f-1)/2);

        }
        ll sum=accumulate(freq.begin(),freq.end(),0LL);
        ll s1=0;
        ll ans=0;
        for(int i=0;i<freq.size();i++)
        {
            ll num=freq[i];
            s1+=num;
        ans+=(num)*(sum-s1);

        }

        return (ans+MOD)%MOD;

        




    }
};