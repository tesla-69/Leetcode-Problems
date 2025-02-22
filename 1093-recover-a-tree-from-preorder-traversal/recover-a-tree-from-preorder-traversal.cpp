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
private:
    TreeNode* solve(int d, string &s, int &i, int n) {
        if(i == n) return NULL;
        int j = i;
        while(j<n && s[j] == '-') j++;
        int dash = j - i;
        if(d != dash) {
            return NULL;
        }
        i += dash;
        int num = 0;
        while(i<n && isdigit(s[i])) {
            num = num*10 + (s[i] - '0');
            i++;
        }
        TreeNode*root = new TreeNode(num);
        root->left = solve(d+1,s,i,n);
        root->right = solve(d+1,s,i,n);
        return root;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int i = 0;
        TreeNode*root = solve(0, traversal, i, n);
        return root;
    }
};