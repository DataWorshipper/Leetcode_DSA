typedef long long ll;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

            priority_queue<int>pq;
            for(auto it:happiness)
            {
                pq.push(it);
            }   
            ll sum=0;
            ll c=0;
            sum+=pq.top();
            pq.pop();
            for(ll i=1;i<=k-1;i++)
            {
                ll diff=i-c;
                sum+=max(pq.top()-diff,0LL);
                pq.pop();

            }
            return sum;

    }
};