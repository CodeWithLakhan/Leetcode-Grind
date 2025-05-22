class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0;
        int cnt=0;
        for(int i=0;i<n;)
        {
            char currChar= chars[i];
            cnt=0;

            while(i<n && chars[i]==currChar)
            {
                i++;
                cnt++;
            }

            chars[idx] = currChar;
            idx++;

            if(cnt>1)
            {
                string temp= to_string(cnt);
                for(char c: temp)
                {
                    chars[idx]=c;
                    idx++;
                }
            }
        }
        return idx;
    }
};