class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int s=nums.size();
        vector<int> ans(s);
        stack<int>st;
        for(int i=(2*s)-1 ; i>=0 ; i--)
        {
            while(!st.empty() && st.top()<=nums[i%s])
            {
                st.pop();
            }
            if(i<s)
            {
                if(st.empty())
                {
                    ans[i]=-1;
                }
                else
                {
                    ans[i]=st.top();
                }
            }
            st.push(nums[i%s]);
        }
        return ans;
    }
};