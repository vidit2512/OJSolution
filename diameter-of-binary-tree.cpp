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
    int rc(TreeNode* root,int &ans)
    {
         if(root==NULL)return 0;
       int l=rc(root->left,ans);
        int r=rc(root->right,ans);
        ans=max(ans,l+r+1);
        return max(l,r)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
       int ans=0;
        ans=max(ans,rc(root,ans));
        return ans-1;
    }
};
