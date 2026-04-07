class Solution {
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int rows;
    int cols;
public:
    void solve(vector<vector<char>>& board) {
        rows=board.size();
        cols = board[0].size();
        for(int r=0;r<rows;r++){
            dfs(board,r,0);
            dfs(board,r,cols-1);
        }
        for(int c=0;c<cols;c++){
            dfs(board,0,c);
            dfs(board,rows-1,c);
        }
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(board[r][c]=='O') board[r][c]='X';
                if(board[r][c]=='T') board[r][c]='O';
            }
        }
    }

    void dfs(vector<vector<char>>& board,int r,int c){
        if(r<0||c<0||r>=rows||c>=cols||board[r][c]!='O') return;
        board[r][c] = 'T';
        for(int i=0;i<4;i++){
            dfs(board,r+dirs[i][0],c+dirs[i][1]);
        }
    }
};
