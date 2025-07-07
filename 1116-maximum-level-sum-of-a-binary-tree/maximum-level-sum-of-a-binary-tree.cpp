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

    void solve(TreeNode*root, map<int,int>& mp, int l) {
        if(!root) return;

        mp[l] += root->val;

        solve(root->left, mp, l+1);
        solve(root->right, mp, l + 1);
    }

    int maxLevelSum(TreeNode* root) {
        map<int,int> mp;
        solve(root, mp, 1);
        int ans = INT_MIN;

        int lev = 0;
        for(auto it : mp) {
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second > ans) {
                ans = it.second;
                lev = it.first;
            }
        }
        return lev;
    }
};