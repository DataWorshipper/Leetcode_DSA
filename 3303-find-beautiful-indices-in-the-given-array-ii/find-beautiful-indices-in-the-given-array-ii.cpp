class Solution {
public:
    
    vector<int> buildLPS(const string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0; 
        for (int i = 1; i < m;) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }

    vector<int> kmpSearch(const string &text, const string &pat) {
        int n = text.size(), m = pat.size();
        vector<int> lps = buildLPS(pat), res;
        int i = 0, j = 0; 
        while (i < n) {
            if (text[i] == pat[j]) {
                i++; j++;
                if (j == m) {
                    res.push_back(i - m); 
                    j = lps[j - 1];
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return res;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> A = kmpSearch(s, a); 
        vector<int> B = kmpSearch(s, b);
        vector<int> ans;

        for (int i : A) {
            int left = i - k, right = i + k;
            auto it = lower_bound(B.begin(), B.end(), left);
            if (it != B.end() && *it <= right) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
