typedef long long ll;
class WordFilter {
    struct TrieNode
    {
        TrieNode* node[26];
         vector<int>idx;
         TrieNode()
         {
        for(ll i=0;i<26;i++)
        {
            node[i]=nullptr;
        }
    }

};
    TrieNode* prefix=new TrieNode();
    TrieNode* suffix=new TrieNode();
       
    public:
    void insert(string word,TrieNode* root,int index)
    {
            TrieNode* a=root;
            for(char ch:word)
            {
                int idx=ch-'a';
                if(a->node[idx]==nullptr)
                {
                    a->node[idx]=new TrieNode();
                }
                
                a=a->node[idx];
                a->idx.push_back(index);
            }
            
    }
    public:
    vector<int>* searchpref(string word,TrieNode* root)
    {
          TrieNode* a=root;
            for(char ch:word)
            {
                int idx=ch-'a';
                if(a->node[idx]==nullptr)
                {
                    return nullptr;
                }
              
                a=a->node[idx];
            }

           
            return &(a->idx);
    }
public:
    WordFilter(vector<string>& words) {

          
            for(ll i=0;i<words.size();i++)
            {
                string s=words[i];
                reverse(words[i].begin(),words[i].end());
                string rev=words[i];
                insert(s,prefix,i);
                insert(rev,suffix,i);
            }


            
    }
    
    int f(string pref, string suff) {
        vector<int>*arr1=searchpref(pref,prefix);
        reverse(suff.begin(),suff.end());
        vector<int>*arr2=searchpref(suff,suffix);
      if(arr1 == nullptr || arr2 == nullptr)
    return -1;
       
        int i=arr1->size()-1;
        int j=arr2->size()-1;
        
       while(i >= 0 && j >= 0)
{
    if((*arr1)[i] == (*arr2)[j])
        return (*arr1)[i];

    if((*arr1)[i] > (*arr2)[j])
        i--;
    else
        j--;
}
        return -1;
    

    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */