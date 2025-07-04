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
    bool checkTree(TreeNode* root) {
        if(root==NULL) return true;

        if(root->left==NULL && root->right == NULL) return true;

        int left = (root->left)? root->left->val : 0;
        int right = (root->right)? root->right->val : 0;

        if(root->val != left+right) return false;

        bool leftCheck = checkTree(root->left);
        bool rightCheck = checkTree(root->right);

        return leftCheck && rightCheck;
    }
};