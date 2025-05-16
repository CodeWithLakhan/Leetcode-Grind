class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        if((num[n-1]-'0')%2==1) return num;

        int x=-1;
        for(int i=n-2;i>=0;i--)
        {
            if((num[i]-'0')%2==1)
            {
                x=i;
                break;
            }
        }
        if(x==-1) return "";
        return num.substr(0,x+1);
    }
};