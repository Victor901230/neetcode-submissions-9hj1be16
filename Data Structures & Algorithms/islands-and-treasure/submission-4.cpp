class Solution {
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int rows;
    int cols;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        queue<pair<int,int>> que;

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==0){
                    que.push({r,c});
                }
            }
        }    

        while(!que.empty()){
            auto [row,col] = que.front();
            que.pop();
            for(int i=0;i<4;i++){
                int nr = row+dirs[i][0];
                int nc = col+dirs[i][1];
                if(nr<0||nc<0||nr>=rows||nc>=cols||grid[nr][nc]!=INT_MAX){
                    continue;
                }
                grid[nr][nc] = grid[row][col]+1;
                que.push({nr,nc});
            }
        }
    }
};
