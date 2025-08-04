class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<tuple<int,int,char,int>> r;
        for (int i = 0; i < healths.size(); i++) {
            r.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(r.begin(), r.end());

        stack<tuple<int,int,char,int>> st;
        vector<int> res(healths.size(), 0);

        for (auto &[pos, h, dir, idx] : r) {
            if (st.empty() || dir == 'R') {
                st.push({pos, h, dir, idx});
            } else {
                while (!st.empty() && dir == 'L' && get<2>(st.top()) == 'R') {
                    auto [p, h1, d, index] = st.top();
                    if (h > h1) {
                        st.pop();
                        h--;
                    } else if (h == h1) {
                        st.pop();
                        h = 0;
                        break;
                    } else { 
                        st.pop();
                        st.push({p, h1 - 1, d, index});
                        h = 0;
                        break;
                    }
                }
                if (h > 0) {
                    st.push({pos, h, dir, idx});
                }
            }
        }

        while (!st.empty()) {
            auto [p, h1, d, idx] = st.top();
            res[idx] = h1;
            st.pop();
        }

        vector<int> ans;
        for (auto it : res) {
            if (it != 0) ans.push_back(it);
        }

        return ans;
    }
};
