class Solution {
public:
    vector<vector<string>> subsets;

    void genSubsets(int idx, vector<string>& curr, vector<string>& words) {
        if (idx == words.size()) {
            subsets.push_back(curr);
            return;
        }
        genSubsets(idx + 1, curr, words);
        curr.push_back(words[idx]);
        genSubsets(idx + 1, curr, words);
        curr.pop_back();
    }

    bool isValidSubset(const vector<string>& subset,
                       const vector<int>& letterHash) {
        vector<int> used(26, 0);
        for (const string& w : subset) {
            for (char c : w) {
                used[c - 'a']++;
                if (used[c - 'a'] > letterHash[c - 'a'])
                    return false;
            }
        }
        return true;
    }

    int calcScore(const vector<string>& subset,
                  const vector<int>& score) {
        int total = 0;
        for (const string& w : subset) {
            for (char c : w) {
                total += score[c - 'a'];
            }
        }
        return total;
    }

    int maxScoreWords(vector<string>& words,
                      vector<char>& letters,
                      vector<int>& score) {
        vector<int> letterHash(26, 0);
        for (char c : letters)
            letterHash[c - 'a']++;

        vector<string> curr;
        genSubsets(0, curr, words);

        int ans = 0;
        for (const auto& subset : subsets) {
            if (isValidSubset(subset, letterHash)) {
                ans = max(ans, calcScore(subset, score));
            }
        }
        return ans;
    }
};
