class Solution {
public:
bool check(vector<int>& heights, int bricks, int ladders,int index)
{
  priority_queue<int>pq;
  for(int i=1;i<=index;i++)
  {
    int diff=heights[i]-heights[i-1];
    if(diff>0)
    pq.push(diff);

}

      if(ladders>=pq.size())
      return true;
      int i=0;
      while(i!=ladders)
      {
        pq.pop();
        i++;
      }
      int sum=0;
      while(!pq.empty())
      {
        sum+=pq.top();
        pq.pop();
      }
      if(sum<=bricks)
      return true;
      else
      return false;

      


}
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int low=0;
        int high=heights.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(heights,bricks,ladders,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};