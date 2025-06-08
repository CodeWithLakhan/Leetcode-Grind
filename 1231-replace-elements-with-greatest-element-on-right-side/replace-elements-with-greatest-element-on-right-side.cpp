class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        int maxx = arr[n-1];
        ans[n-1]=-1;
        if(n==0) return ans;
        for(int i=n-2;i>=0;i--)
        {
            ans[i]=maxx;
            maxx=max(maxx,arr[i]);
        }
        return ans;
    }
};