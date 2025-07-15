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

    void solve(TreeNode* root, int &tar, long long sum, unordered_map<long long,int> &mp, int &cnt) {
        if(!root) return;
        sum += root->val;
        if(mp.find(sum - tar) != mp.end()) {
            cnt += mp[sum - tar];
        }
        mp[sum]++;
        solve(root->left, tar, sum, mp, cnt);
        solve(root->right, tar, sum, mp, cnt);
        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;
        mp[0] = 1;
        int cnt = 0;
        solve(root, targetSum, 0*1ll, mp, cnt);
        return cnt;
    }
};