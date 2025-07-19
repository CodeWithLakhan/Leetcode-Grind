class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        bool anss = false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if (board[i][j] == word[0]) {
                    if (solve(i, j, 0, board, word)) {
                        return true;
                    }
                }
            }
        }
        return anss;
    }

    bool solve(int r , int c , int wordidx ,  vector<vector<char>>& board, string& word){
        int row = board.size();
        int col = board[0].size();

        if(r>=row || c>=col || r<0 || c<0 || board[r][c]=='.' || board[r][c]!=word[wordidx]) return false;

        if(wordidx==word.size()-1 && word[wordidx]==board[r][c]) return true;

        int drow[4] = {0,1,0,-1};
        int dcol[4] = {1,0,-1,0};

        char temp = board[r][c];
        board[r][c] = '.';
        bool ans=false;

        for(int i=0;i<4;i++){
            if (solve(r + drow[i], c + dcol[i], wordidx + 1, board, word)) {
                board[r][c] = temp; 
                return true;
            }
        }

        board[r][c] = temp;

        return ans;

    }
};