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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int s=0;
        int lvl=1;
        int anslvl=1;
        int ans=root->val;
        while(!q.empty())
        {
            s=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                s=s+node->val;
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            if(ans<s){
                ans=s;
                anslvl=lvl;
            }
            lvl++;
        }
        return anslvl;
    }
};