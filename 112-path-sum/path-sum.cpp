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
    void solve(TreeNode*root , int targetSum , int sum ,int &ans){
        if(root==NULL) return ;
        
        sum+=root->val;

        if(root->right==NULL && root->left == NULL) {
            if(sum==targetSum) ans=1;
        }

        solve(root->left,targetSum,sum,ans);
        solve(root->right,targetSum,sum,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int ans=0;
        int sum=0;
        solve(root,targetSum,sum,ans);
        if(ans) return true;
        else return false;

        
    }
};