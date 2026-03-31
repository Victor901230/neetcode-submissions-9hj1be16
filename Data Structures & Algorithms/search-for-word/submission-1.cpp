class Solution {
    int col,row;
    set<pair<int,int>> path;
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for(int i = 0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word,int r,int c,int i){
        if(i==word.size()) return true;
        if(r<0||c<0||r>=row||c>=col||word[i]!=board[r][c]||path.count({r,c})) return false;

        path.insert({r,c});
        bool res = dfs(board,word,r+1,c,i+1)||
                    dfs(board,word,r,c+1,i+1)||
                    dfs(board,word,r-1,c,i+1)||
                    dfs(board,word,r,c-1,i+1);
        path.erase({r,c});
        return res;
    }
};
