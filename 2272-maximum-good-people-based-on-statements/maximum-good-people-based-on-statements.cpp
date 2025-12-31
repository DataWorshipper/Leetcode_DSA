class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size();
        int m=INT_MIN;
        for(int i=0;i<=(1<<n)-1;i++)
        {

            int mask=i;
             bool flag=true;
            for(int j=0;j<n;j++)
            {
                if(mask&(1<<j))
                {   
                   
                    for(int k=0;k<statements[j].size();k++)
                    {
                       if(statements[j][k]==2)
                       continue;
                       else if(statements[j][k]==0)
                       {
                        if(mask&(1<<k))
                        {
                            flag=false;
                        }

                       }
                       else
                        {
                            if(!(mask&(1<<k)))
                        {
                            flag=false;
                        }
                        }

                
                    }
                }


                    if(flag==false)
                    break;}

            if(flag==true)
            {
                int cnt = __builtin_popcount(mask);
                m=max(m,cnt);

            }
        }

        return m;
    }
};