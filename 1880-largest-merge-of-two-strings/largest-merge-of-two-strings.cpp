class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        string merge = "";

        while (i < word1.size() || j < word2.size()) {
            
            if (j == word2.size()) {
                merge.push_back(word1[i++]);
            }
            
            else if (i == word1.size()) {
                merge.push_back(word2[j++]);
            }
           
            else if (word1[i] > word2[j]) {
                merge.push_back(word1[i++]);
            }
            else if (word1[i] < word2[j]) {
                merge.push_back(word2[j++]);
            }
           
            else {
                if (word1.substr(i) > word2.substr(j)) {
                    merge.push_back(word1[i++]);
                } else {
                    merge.push_back(word2[j++]);
                }
            }
        }
        return merge;
    }
};
