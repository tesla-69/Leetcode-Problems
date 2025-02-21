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
class FindElements {
private: 
    TreeNode*rootNode;
    set<int>s;
public:
    TreeNode* recover(TreeNode*&root, int x){
        if(root == NULL) return NULL;
        recover(root->left,2*x+1);
        recover(root->right,2*x+2);

        root->val = x;
        s.insert(root->val);
        return root;
    }
    FindElements(TreeNode* root) {
        rootNode = root;
        recover(rootNode,0);
    }
    bool find(int target) {
        if(s.find(target) == s.end()) return false;
        else return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */