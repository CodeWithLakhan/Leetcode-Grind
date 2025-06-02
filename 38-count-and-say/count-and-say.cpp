class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        if(n==1) return "1";
        else if(n==2) return "11";
        ans="11";
        while(n-2>0)
        {
            string temp="";
            int cnt=1;
            for(int i=1;i<ans.size();i++)
            {
                if(ans[i]==ans[i-1])cnt++;
                else
                {
                    temp=temp+to_string(cnt)+ans[i-1];
                    cnt=1;
                }
            }
            temp=temp+to_string(cnt)+ans[ans.size()-1];
            cnt=1;
            ans=temp;
            cout<<ans<<endl;
            n--;
        }
        return ans;
    }
};