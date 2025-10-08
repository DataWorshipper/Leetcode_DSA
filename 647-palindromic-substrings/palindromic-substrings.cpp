class manacher {
public:
    vector<int> p;

    string build_string(string &s) {
        string t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }
        return t;
    }

    void run_manacher(const string &t) {
        int n = t.size();
        p.assign(n, 0);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int mirror = l + r - i;
            if (i < r)
                p[i] = min(r - i, p[mirror]);
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
                p[i]++;
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    int getlongest(int cen, bool odd) {
        int pos = 2 * cen + 1 + !odd;
        return p[pos] - 1;
    }

    bool check(int l, int r) {
        return r - l + 1 <= getlongest((l + r) / 2, l % 2 == r % 2);
    }
};
class Solution {
public:
    int countSubstrings(string s) {
    if (s.empty()) return 0;
        manacher m;
        string t = m.build_string(s);
        m.run_manacher(t);

        int ans = 0;
        for (int x : m.p) {
            ans += (x + 1) / 2;

        }
        return ans;
    }

    
};