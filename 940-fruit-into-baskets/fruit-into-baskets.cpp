class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        map<int,int> mpp;
        int ans=0;
        int l=0;
        int r=0;

        while(r<n){
            mpp[arr[r]]++;
            
            while(mpp.size()>2){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) mpp.erase(arr[l]);
                l++;
            }
            
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;


    }
};