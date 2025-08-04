class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        unordered_map<int, int> mpp;
        int max_fruits = 0;

        while (r < fruits.size()) {
            mpp[fruits[r]]++;

            while (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }

            max_fruits = max(max_fruits, r - l + 1);  
            r++;
        }

        return max_fruits;
    }
};