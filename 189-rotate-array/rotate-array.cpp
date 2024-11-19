class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>0 && nums.size()>1 && k%nums.size()>0)
        {
            
            k = k%nums.size();
            int temp[k];
            int n=nums.size();
            int j=0;
            for(int i=n-k;i<n;i++)
            {
                temp[j]=nums[i];
                j++;
            }
            // for(int i=0;i<k;i++) cout<<temp[i];
            for(int i=n-k-1;i>=0;i--)
            {
                nums[i+k]=nums[i];
            }
            int x=nums.size()-k;
            j=0;
            for(int i=0;i<k;i++)
            {
                nums[i]=temp[j];
                j++;
            }
        }
    
    }
};