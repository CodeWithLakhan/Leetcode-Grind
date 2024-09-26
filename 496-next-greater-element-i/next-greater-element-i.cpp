class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int s = nums2.size();
        stack<int> st;
        vector<int> ans(s);
        ans[s-1]=-1;
        st.push(nums2[s-1]);
        
        for(int i=s-2;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[i]=-1;
            }
            else
            {
                ans[i]=st.top();
            }
            st.push(nums2[i]);
        }
        unordered_map<int,int> mp;
        for(int i=0;i<s;i++)
        {
            mp[nums2[i]]=ans[i];
        }
        vector<int> fans(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            fans[i]=mp[nums1[i]];
        }
        return fans;
    }
};