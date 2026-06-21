class Solution {
public:
    int maxDistance(string moves) {
        int c=0;
        int x=0;
        int y=0;
        for(char ch:moves)
        {
            if(ch=='_')
            c++;
            if(ch=='L')
            x--;
            if(ch=='R')
            x++;
            if(ch=='U')
            y++;
            if(ch=='D')
            y--;



        }
        x=abs(x);
        y=abs(y);
        return x+y+c;
    }
};