class Solution {
    vector<vector<string>> res;
    unordered_set<int> checkCol;
    unordered_set<int> checkRow;
    unordered_set<int> checkDig;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        dfs(board,0);
        return res;
    }

    void dfs(vector<string>& board,int r){
        if(r==board.size()){
            res.push_back(board);
            return;
        }
        
        for(int c = 0;c<board.size();c++){
            if(checkCol.count(c)||checkRow.count(r+c)||checkDig.count(r-c)) continue;
            board[r][c] = 'Q';
            checkCol.insert(c);
            checkRow.insert(r+c);
            checkDig.insert(r-c);

            dfs(board,r+1);
            board[r][c] = '.';
            checkCol.erase(c);
            checkRow.erase(r+c);
            checkDig.erase(r-c);
        }
    }
};
