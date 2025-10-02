class TrieNode
{public:
    TrieNode* child[2];
    TrieNode()
    {
        child[0]=nullptr;
        child[1]=nullptr;
    }

};



class Solution {
public:
TrieNode* root;
Solution()
{
    root=new TrieNode();
}
void insert(int num)
{
    TrieNode* node=root;
    for(int i=31;i>=0;i--)
    {
        int bit=(num>>i)&1;
        if(!node->child[bit])
        node->child[bit]=new TrieNode();
        node=node->child[bit];
    }

}
int maxxor(int num)
{
    TrieNode* node=root;
    int ans=0;
    for(int i=31;i>=0;i--)
    {
        int bit=(num>>i)&1;
        int toggle=1-bit;
        if(!node->child[toggle])
        node=node->child[bit];
        else
        {ans+=(1<<i);
        node=node->child[toggle];
        }}
        return ans;
}
    int findMaximumXOR(vector<int>& nums) {

            for(int i=0;i<nums.size();i++)
            {
                insert(nums[i]);
            }
            int m=INT_MIN;
            for(int i=0;i<nums.size();i++)
            {
                m=max(m,maxxor(nums[i]));

            }
            return m;
    }
};