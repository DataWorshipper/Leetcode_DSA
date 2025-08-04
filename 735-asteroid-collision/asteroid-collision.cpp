class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {
        
vector<int>res;
        stack<int>st;
        for(int i=0;i<asteroid.size();i++)
        {
           if(asteroid[i]>0)
           st.push(asteroid[i]);
            else
            {
           while(!st.empty() &&st.top()>0 &&st.top()<abs(asteroid[i]))
           {
            st.pop();
           }

           if(!st.empty() &&st.top()>abs(asteroid[i]))
           {
                continue;
           }

           if(!st.empty() &&st.top()==abs(asteroid[i]))
           {
            st.pop();
            continue;
           }

           if(st.empty() ||st.top()<0)
           st.push(asteroid[i]);


            }
        }

        while(!st.empty())
        {
            res.push_back(st.top());

            st.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};