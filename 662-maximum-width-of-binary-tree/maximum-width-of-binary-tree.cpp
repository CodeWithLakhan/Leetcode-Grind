class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        int ans = 0;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            unsigned long long minn = q.front().second;
            unsigned long long f = 0, l = 0;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front().first;
                unsigned long long idx = q.front().second - minn;
                q.pop();
                if(i==0) f = idx;
                if(i==n-1) l = idx;
                if(node->left)
                    q.push({node->left, 2*idx+1});
                if(node->right)
                    q.push({node->right, 2*idx+2});
            }
            ans = max(ans, (int)(l - f + 1));
        }
        return ans;
    }
};
