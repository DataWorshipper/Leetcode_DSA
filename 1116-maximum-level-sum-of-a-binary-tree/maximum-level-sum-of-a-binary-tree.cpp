/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
      
        vector<vector<int>>ans;
        while(!q.empty())
        {
            vector<int>level;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* node=q.front();
                level.push_back(node->val);
                q.pop();
                  if(node->right!=NULL)
                   q.push(node->right);
                if(node->left!=NULL)
                q.push(node->left);
            }
            ans.push_back(level);                   
                           
         }


         int maxsum=INT_MIN;
         int mlevel=-1;
         for(int i=0;i<ans.size();i++)
         {
            vector<int>b=ans[i];
            int s=accumulate(b.begin(),b.end(),0);
            if(s>maxsum)
            {
                maxsum=s;
                mlevel=i+1;
            }
         }

         return mlevel;

        }
    
};