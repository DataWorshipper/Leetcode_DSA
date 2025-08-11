class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()<s2.size())
        swap(s1,s2);

        vector<string>w1,w2;

       
        stringstream ss(s1);
         string word;
         while(ss>>word)
         {
            w1.push_back(word);
         }

 stringstream ss1(s2);
        
         while(ss1>>word)
         {
            w2.push_back(word);
         }

         int i=0;
         int l=0;
         int j=w1.size()-1;
         int r=w2.size()-1;
         while(i<w1.size() &&l<w2.size() &&w1[i]==w2[l])
         {
            i++;
            l++;
         }
           while(j<w1.size() &&r<w2.size() &&w1[j]==w2[r])
         {
            j--;
            r--;
         }

         return (r<l);






    }
};