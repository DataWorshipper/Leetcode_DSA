class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> hp;
        hp.push(a);
        hp.push(b);
        hp.push(c);

        int ans = 0;

        while (hp.size() >= 2) {
            int x = hp.top();
            hp.pop();

            int y = hp.top();
            hp.pop();

            x--;
            y--;
            ans++;

            if (x > 0) hp.push(x);
            if (y > 0) hp.push(y);
        }

        return ans;
    }
};