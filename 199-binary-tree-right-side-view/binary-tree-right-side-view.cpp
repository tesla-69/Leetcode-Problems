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

    void solve(TreeNode*root, vector<int>&arr, int l) {
        if(!root) return;

        if(l == arr.size()) arr.push_back(root->val);

        solve(root->right, arr, l + 1);
        solve(root->left, arr, l+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> a;
        solve(root, a, 0);
        return a;
    }
};