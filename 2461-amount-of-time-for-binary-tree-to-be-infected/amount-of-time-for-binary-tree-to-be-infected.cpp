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
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode* , TreeNode*> mpp;
        TreeNode* node = find(root , mpp , start);
        int ans = solve(node , mpp );
        return ans;
    }

    int solve(TreeNode* node , map<TreeNode* , TreeNode*>& mpp){
        int ans = 0;
        map<TreeNode* , int> vis;
        queue<TreeNode*> q;
        q.push(node);
        vis[node]=1;

        while(!q.empty()){
            int n=q.size();
            int f=0;

            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left != NULL && !vis[temp->left]){
                    vis[temp->left]=1;
                    f=1;
                    q.push(temp->left);
                }
                if(temp->right != NULL && !vis[temp->right]){
                    vis[temp->right] =1;
                    f=1;
                    q.push(temp->right);
                }
                if(mpp[temp] && !vis[mpp[temp]]){
                    vis[mpp[temp]]=1;
                    f=1;
                    q.push(mpp[temp]);
                }
            }
            if(f) ans++;
        }
        return ans;
    }

    TreeNode* find(TreeNode* root , map<TreeNode* , TreeNode*>& mpp, int target){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;

        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp->val==target) res=temp;
            q.pop();

            if(temp->left !=NULL){
                mpp[temp->left] = temp;
                q.push(temp->left);
            }

            if(temp->right != NULL){
                mpp[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return res;
    }
};