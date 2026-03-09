class Solution {
public:
    static const int MOD = 1e9+7;

    long long dp[350][2][2][11];
    vector<int> dig;
    int base;

    string sub1(string s){
        int i=s.size()-1;
        while(i>=0 && s[i]=='0'){
            s[i]='9';
            i--;
        }
        if(i>=0) s[i]--;
        if(s.size()>1 && s[0]=='0') s.erase(s.begin());
        return s;
    }

    vector<int> toBase(string s,int b){
        vector<int> res;
        while(!(s.size()==1 && s[0]=='0')){
            string q="";
            int rem=0;
            for(char c:s){
                int cur=rem*10+(c-'0');
                if(!q.empty() || cur/b>0) q.push_back('0'+cur/b);
                rem=cur%b;
            }
            res.push_back(rem);
            if(q.empty()) q="0";
            s=q;
        }
        reverse(res.begin(),res.end());
        return res;
    }

    long long dfs(int pos,int tight,int started,int prev){
        if(pos==dig.size()) return 1;

        long long &res=dp[pos][tight][started][prev];
        if(res!=-1) return res;
        res=0;

        int lim=tight?dig[pos]:base-1;

        for(int d=0;d<=lim;d++){
            int ntight = tight && (d==lim);

            if(!started){
                if(d==0)
                    res=(res+dfs(pos+1,ntight,0,prev))%MOD;
                else
                    res=(res+dfs(pos+1,ntight,1,d))%MOD;
            }
            else{
                if(d>=prev)
                    res=(res+dfs(pos+1,ntight,1,d))%MOD;
            }
        }

        return res%MOD;
    }

    long long solve(string s,int b){
        dig=toBase(s,b);
        base=b;
        memset(dp,-1,sizeof(dp));
        return dfs(0,1,0,0);
    }

    int countNumbers(string l, string r, int b) {
        string lm1=sub1(l);
        long long ans=(solve(r,b)-solve(lm1,b)+MOD)%MOD;
        return ans;
    }
};