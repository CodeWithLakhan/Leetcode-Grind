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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        bool f=true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* x =  q.front();
                q.pop();

                int idx = f? i : size-i-1;
                row[idx]=x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
                f=!f;
                ans.push_back(row);
        }
        return ans;
    }
};