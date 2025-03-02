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
    int maxPathSum(TreeNode* root) {
        int fans = INT_MIN;
        ans(root,fans);
        return fans;
    }
    int ans(TreeNode* node, int& fans )
    {
        if(node==NULL) return 0;

        int lsum = ans(node->left , fans );
        int rsum = ans(node->right , fans );

        if(lsum<0) lsum=0;
        if(rsum<0) rsum=0;

        fans = max(fans , lsum+rsum+node->val);

        return node->val + max(rsum,lsum);

    }
};