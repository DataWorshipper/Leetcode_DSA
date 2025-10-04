
class TrieNode
{   public:
    TrieNode *children[26];
    bool flag;
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            children[i]=nullptr;
            flag=false;
        }
    }
};
class Trie {
public:

TrieNode* root;
    Trie() {
         root =new TrieNode();

    }
    
    void insert(string word) {

            TrieNode *node = root;

            for(int i=0;i<word.size();i++)
            {
                int index=word[i]-'a';
                if(!node->children[index])
                {
                    node->children[index]=new TrieNode();
                }

                node=node->children[index];
                
            }
            node->flag=true;

    }
    
    bool search(string word) {
        
 TrieNode *node = root;
 bool c=false;
 for(int i=0;i<word.size();i++)
 {
        int index=word[i]-'a';
        if(!node->children[index])
        return false;


        node=node->children[index];
        c=node->flag;
        
 }
 return c==true;

    }
    
    bool startsWith(string word) {
        TrieNode *node = root;
for(int i=0;i<word.size();i++)
 {
        int index=word[i]-'a';
  if(!node->children[index])
        return false;


        node=node->children[index];
 }

 return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */