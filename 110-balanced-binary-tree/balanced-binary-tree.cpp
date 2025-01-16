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
    bool isBalanced(TreeNode* root) {

        if(root==NULL) return true;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        if(abs(l-r)>1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;

        return true;

    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return 1 + max(l,r);
    }
};