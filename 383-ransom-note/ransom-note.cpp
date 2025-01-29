class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n1 = magazine.size();
        unordered_map<char, int> umap;
        for(int i=0;i<n1;i++)
        {
            umap[magazine[i]] =  umap[magazine[i]] + 1;
        }
        int n2=ransomNote.size();
        for(int i=0;i<n2;i++)
        {
            if(umap.find(ransomNote[i])==umap.end()) return false;
            if(umap[ransomNote[i]]==0) return false;
            umap[ransomNote[i]] -= 1;
        }
        return true;
    }
};