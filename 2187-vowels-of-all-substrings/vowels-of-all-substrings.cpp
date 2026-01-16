class Solution {
public:
    long long countVowels(string s) {
        int n = s.size();
        long long ans = 0;

        auto isVowel = [&](char c){
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };

        for(int i = 0; i < n; i++){
            if(isVowel(s[i])){
                ans += 1LL * (i + 1) * (n - i);
            }
        }
        return ans;
    }
};
