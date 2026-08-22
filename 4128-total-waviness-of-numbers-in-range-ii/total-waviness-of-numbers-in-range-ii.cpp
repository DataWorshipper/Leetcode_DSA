typedef long long ll;

class Solution {
public:

    struct Node {
        ll cnt;
        ll wave;
    };

    Node dp[16][2][12][12][2];
    bool vis[16][2][12][12][2];

    Node f(ll index, ll tight, ll prev, ll sprev,
           ll valid, string &s)
    {
        if(index == s.size())
        {
            return {1, 0};
        }

        if(vis[index][tight][prev+1][sprev+1][valid])
            return dp[index][tight][prev+1][sprev+1][valid];

        vis[index][tight][prev+1][sprev+1][valid] = true;

        Node ans = {0, 0};

        ll limit = tight ? s[index] - '0' : 9;

        for(ll i = 0; i <= limit; i++)
        {
            ll newtight = tight && (i == s[index] - '0');

            Node cur;

            if(valid == 0)
            {
                if(i == 0)
                {
                    cur = f(index + 1, newtight, -1, -1, 0, s);
                }
                else
                {
                    cur = f(index + 1, newtight, i, -1, 1, s);
                }
            }
            else
            {
                cur = f(index + 1, newtight, i, prev, 1, s);

                if(sprev != -1 &&
                   ((prev > sprev && prev > i) ||
                    (prev < sprev && prev < i)))
                {
                    cur.wave += cur.cnt;
                }
            }

            ans.cnt += cur.cnt;
            ans.wave += cur.wave;
        }

        return dp[index][tight][prev+1][sprev+1][valid] = ans;
    }

    ll solve(string s)
    {
        memset(vis, false, sizeof(vis));

        Node res = f(0, 1, -1, -1, 0, s);

        return res.wave;
    }

    long long totalWaviness(long long num1, long long num2)
    {
        ll a1 = solve(to_string(num1 - 1));
        ll a2 = solve(to_string(num2));

        return a2 - a1;
    }
};