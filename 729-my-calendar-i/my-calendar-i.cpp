class MyCalendar {
public:
  map<int,int>mpp;
    MyCalendar() {
        

    }
    
    bool book(int startTime, int endTime) {
        
        mpp[startTime]++;
        mpp[endTime]--;
        int prefix=0;
        for(auto it:mpp)
        {
            prefix+=it.second;
            if(prefix>=2)
            {

                mpp[startTime]--;
                mpp[endTime]++;
                 if (mpp[startTime] == 0) mpp.erase(startTime);
                if (mpp[endTime] == 0) mpp.erase(endTime);
                return false;
            }
            
           
        }
        return true;
      

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */