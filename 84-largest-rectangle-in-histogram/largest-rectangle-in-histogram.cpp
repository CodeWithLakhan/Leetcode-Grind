class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st ;
        int maxArea = 0;
        for(int i=0;i<heights.size();i++)
        {
            while(!(st.empty()) && heights[i] < heights[st.top()])
            {
                int e = st.top();
                st.pop();
                int nse = i;
                int pse = (st.empty())? -1 : st.top();
                maxArea = max( (heights[e] * (nse - pse - 1)) , maxArea);
            }
            st.push(i);
        }
        while(!(st.empty()))
        {
            int nse = heights.size();
            int e = st.top();
            st.pop();
            int pse = (st.empty())? -1 : st.top();
            
            maxArea = max( (heights[e] * (nse -pse - 1)) , maxArea);
        }
        return maxArea;
        
    }
};