class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        using T= tuple<double,double,double>;
        priority_queue<T>pq;
        double i_pass=0;
        for(auto it:classes)
        {
            double a=(double)it[0];
            double b=(double)it[1];
            double change=(a+1)/(b+1)-(a/b);
            pq.push({change,a+1,b+1});
            i_pass+=(a/b);
        }
        


        while(extraStudents>0)
        {
         tuple t=pq.top();
         double frac=get<0>(t);
         double num=get<1>(t);
         double denom=get<2>(t);
        i_pass+=frac;
         pq.pop();
         extraStudents--;
         double a=(num+1)/(denom+1)-(num/denom);
         pq.push({a,num+1,denom+1});
        }

        return (i_pass/classes.size());


    }
};