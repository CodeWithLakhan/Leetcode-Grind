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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postidx = postorder.size() - 1;

        return solve( postorder , inorder , postidx , 0 , postorder.size() - 1);        
    }

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& postidx, int left , int right){
        if(left>right){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postidx]);
        int inidx = search(inorder,left,right,postorder[postidx]);
        postidx--;

        root->right = solve(postorder,inorder,postidx,inidx+1,right);
        root->left = solve(postorder,inorder,postidx,left,inidx-1);

        return root;

    }
    int search(vector<int>& inorder, int left, int right, int val){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val) return i;
        }
        return -1;
    }

};