class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin() , arr.end());
        vector<int> ans;
        vector<vector<int>> fans;
        getAns(arr , 0 , ans , fans , target);
        return fans;
    }

    void getAns(vector<int>& arr, int idx , vector<int>& ans , vector<vector<int>>& fans ,int target)
    {
        if(target==0)
        {
            fans.push_back(ans);
            return;
        }
        for(int i=idx ; i<arr.size();i++)
        {
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ans.push_back(arr[i]);
            getAns(arr , i+1 , ans , fans , target-arr[i]);
            ans.pop_back();
        }
    }

};