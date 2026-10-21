
class Solution {  
    class TrieNode
{   
    public:
    vector<TrieNode*>arr;
    int cnt;
    
    TrieNode()
    {   
        arr.resize(10,nullptr);
        
        cnt=0;
    }
};
public:
class Trie
{   public:
    TrieNode* root;
    public:
        Trie()
        {
            root=new TrieNode();
        }
        void insert(string &s,TrieNode* root)
        {   
            TrieNode* node=root;
            for(int i=0;i<s.size();i++)
            {
                int ch=s[i]-'0';
                if(node->arr[ch]==NULL)
                {
                    node->arr[ch]=new TrieNode();
                    
                }
                
                node=node->arr[ch];
                node->cnt+=1;
            }
        }

        long long length(string &prefix,TrieNode* root)
        {
            long long l=0;
            TrieNode* node=root;
            for(int i=0;i<prefix.size();i++)
            {   
                 int ch=prefix[i]-'0';
                if(!node->arr[ch])
                {
                    break;
                }
                else
                {
                    l+=1;
                    node=node->arr[ch];
                }
            }
            return l;
     }


};
   int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    Trie obj1, obj2;
    TrieNode* root1 = obj1.root;
    TrieNode* root2 = obj2.root;

    for (int i = 0; i < arr1.size(); i++) {
        string s = to_string(arr1[i]);
        obj1.insert(s, root1);
    }

    for (int i = 0; i < arr2.size(); i++) {
        string s = to_string(arr2[i]);
        obj2.insert(s, root2);
    }

    int ans = 0;

    for (int i = 0; i < arr1.size(); i++) {
        string s = to_string(arr1[i]);
        ans = max(ans, (int)obj2.length(s, root2));
    }

    for (int i = 0; i < arr2.size(); i++) {
        string s = to_string(arr2[i]);
        ans = max(ans, (int)obj1.length(s, root1));
    }

    return ans;
}
};