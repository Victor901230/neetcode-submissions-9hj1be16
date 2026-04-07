class Solution {
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int rows;
    int cols;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==INT_MAX){
                    grid[r][c] = bfs(grid,r,c);
                }
            }
        }    
    }

    int bfs(vector<vector<int>>& grid,int r,int c){
        vector<vector<bool>> visit(rows,vector<bool>(cols,false));
        queue<pair<int,int>> que;
        que.push({r,c});
        visit[r][c]=true;
        int steps=0;
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                auto [row,col] = que.front();
                que.pop();
                if(grid[row][col]==0) return steps;

                for(int i=0;i<4;i++){
                    int nr = row+dirs[i][0];
                    int nc = col+dirs[i][1];
                    if(nr>=0&&nc>=0&&nr<rows&&nc<cols&&visit[nr][nc]==false&&grid[nr][nc]!=-1){
                        que.push({nr,nc});
                        visit[nr][nc]=true;
                    }
                }
            }
            steps++;
        }
        return INT_MAX;
    }
};
