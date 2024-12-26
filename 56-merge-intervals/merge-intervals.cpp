class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n= arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);

        int x=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i][0]<=ans[x][1])
            {
                if(arr[i][1]>ans[x][1])
                {
                    ans[x][1]=arr[i][1];
                }
                
            }
            else
            {
                ans.push_back(arr[i]);
                x++;
            }
        }
        return ans;
    }
};