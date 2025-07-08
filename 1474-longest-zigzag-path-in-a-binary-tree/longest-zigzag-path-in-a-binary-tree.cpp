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

    void solve(TreeNode*root, int len, int &ans, bool flag) {
        if(!root) return;

        ans = max(ans, len);
        if(flag) {
            solve(root->left, len + 1, ans, !flag);
            solve(root->right, 1, ans, flag);
        }
        else {
            solve(root->left, 1, ans, flag);
            solve(root->right, len + 1, ans, !flag);
        }

    }

    int longestZigZag(TreeNode* root) {
        int ans = INT_MIN;
        int len = 0;
        solve(root, len, ans, true);
        return ans;
    }
};