class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> counts;
        for (auto &row : bank) {
            int c = count(row.begin(), row.end(), '1');
            if (c > 0) counts.push_back(c);
        }

        int beams = 0;
        for (int i = 0; i + 1 < counts.size(); i++)
            beams += counts[i] * counts[i+1];
        return beams;
    }
};
