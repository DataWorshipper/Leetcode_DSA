class Solution {
    unordered_map<int,vector<int>>dp;
    
    bool vis[1<<16];
    vector<int>f(int &skill_mask,vector<int>&people_mask,int mask)
    {       

            if(mask==skill_mask)
            {
                return {};
            }


        if(vis[mask])
        return dp[mask];
        vis[mask]=true;

        vector<int>best;
        
        for(int i=0;i<people_mask.size();i++)
        {
               int  new_mask=mask|people_mask[i];
               if(new_mask==mask)
               continue;

               else
               {    
               
              vector<int>curr =f(skill_mask,people_mask,new_mask);
              curr.push_back(i);
              if(best.empty()||best.size()>curr.size())
              best=curr;
               }

        }

        return dp[mask]=best;

      

    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {
            
            unordered_map<string,int>mpp;
            int index=0;
            for(int i=0;i<req_skills.size();i++)
            {
                string str=req_skills[i];
                mpp[str]=index;
                index++;
            }

            int skill_mask=0;
            for(auto it:mpp)
            {
                int val=it.second;
                skill_mask=(skill_mask|(1<<val));
            }
             vector<vector<int>>people_mask(people.size());
            for(int i=0;i<people.size();i++)
            {
                for(int j=0;j<people[i].size();j++)
                {
                    people_mask[i].push_back(mpp[people[i][j]]);
                }
            }
           
            vector<int>some_mask;
            for(int  i=0;i<people.size();i++)
            {
                vector<int>sample=people_mask[i];
                int mask_sample=0;
                for(int j=0;j<sample.size();j++)
                {
                    mask_sample=(mask_sample|(1<<sample[j])); 
                }

                some_mask.push_back(mask_sample);

            }

            dp[0]={};

           return  f(skill_mask,some_mask,0);




 }
};