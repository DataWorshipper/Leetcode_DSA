typedef long long ll;
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low=LLONG_MAX;
        double high=LLONG_MIN;
        for(ll i=0;i<squares.size();i++)
        {
            double y=(double)squares[i][1];
            low=min(low,y);
            high=max(high,y+(double)squares[i][2]);
        }
    double ans=0;
    double eps=1e-5;
        while(high-low>=eps)
        {
            double mid=(low)+(high-low)/2.0;
            double area_below=0.0;
            double area_above=0.0;
            for(ll i=0;i<squares.size();i++)
            {
                 double y=(double)squares[i][1];
                 double len=(double)squares[i][2];
                 if(y>=mid)
                 {
                    area_above+=(len*len);
                 }
                 else if(y+len<=mid)
                 {
                    area_below+=(len*len);
                 }
                 else if(mid>=y &&mid<=y+len)
                 {
                    area_below+=(len*(abs(mid-y)));
                    area_above+=(len*(y+len-mid));
                 }
            }

            if(area_above<=area_below)
            {   
                ans=mid;
                 high=mid; 

            }
            else
            {
                low=mid;
            }
        }

        return ans;


    }
};