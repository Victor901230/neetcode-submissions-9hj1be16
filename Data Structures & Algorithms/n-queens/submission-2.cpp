class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        dfs(board,0);
        return res; 
    }

    void dfs(vector<string>& board,int row){
        if(row>=board.size()){
            res.push_back(board);
            return;
        }

        for(int i = 0;i<board.size();i++){
            if(isSafe(board,row,i)){
                board[row][i]='Q';
                dfs(board,row+1);
                board[row][i]='.';
            }
        }
    }

    bool isSafe(vector<string>& board,int r,int c){
        for(int i = c-1;i>=0;i--){//列
            if(board[r][i]=='Q') return false;
        }
        for(int i = r-1;i>=0;i--){//行
            if(board[i][c]=='Q') return false;
        }
        for(int i = c-1,j=r-1;i>=0&&j>=0;i--,j--){//左上
            if(board[j][i]=='Q') return false;
        }
        for(int i = c+1,j=r-1;i<=board.size()&&j>=0;i++,j--){//左上
            if(board[j][i]=='Q') return false;
        }
        return true;
    }
};
