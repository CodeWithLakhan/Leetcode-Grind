class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xr = 0;
        long n=nums.size();
        for(int i=0;i<n;i++){
            xr = xr ^ nums[i];
        }

        int n1=0;
        int n2=0;
        int rightMost = (xr & xr-1) ^ xr;
        
        for(int i=0;i<n;i++){
            if(nums[i] & rightMost){
                n1=n1^nums[i];
            }
            else{
                n2=n2^nums[i];
            }
        }
        return {n1,n2};
    }
};