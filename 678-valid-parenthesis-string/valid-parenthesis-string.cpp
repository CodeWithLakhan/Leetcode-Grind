class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int max=0,min=0;
        for(int i=0;i<n;i++)
        {
            
            if(s[i]=='(')
            {
                max=max+1;
                min=min+1;
            }
            else if(s[i]==')')
            {
                max=max-1;
                min=min-1;
            }
            else
            {
                min=min-1;
                max=max+1;
            }
            if(min<0) min=0;
            if(max<0) return false;
        }
        return min==0;
    }
};