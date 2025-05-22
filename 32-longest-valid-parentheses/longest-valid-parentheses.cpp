class Solution {
public:
    int longestValidParentheses(string s) {
        int o=0;
        int c=0;
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')  o++;
            else c++;
            if(o==c)
            {
                ans = max(ans,o+c);
            }
            else if(c>o)
            {
                c=0,o=0;
            }
        }

        o = c = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') o++;
            else c++;
            if (o == c) ans = max(ans, o + c);
            else if (o > c) o = c = 0;
        }

        return ans;
    }
};