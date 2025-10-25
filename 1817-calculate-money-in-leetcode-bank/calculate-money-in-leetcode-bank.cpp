class Solution {
public:
    int totalMoney(int n) {
        int a=n/7;
        int b=n%7;
        int s=28;
        int sum=0;
        for(int i=1;i<=a;i++)
        {
            sum+=s;
            s+=7;
        }
        int s1=a+1;

        for(int i=1;i<=b;i++)
        {
            sum+=s1;
            s1++;
        }

        return sum;

    }
};