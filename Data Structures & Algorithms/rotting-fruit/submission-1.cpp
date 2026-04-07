class Solution {
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> que;
        int fresh = 0;//統計新鮮果數量
        int time = 0;
        
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1) fresh++;
                if(grid[r][c]==2) que.push({r,c});
            }
        }
        
        while(fresh>0&&!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                auto [row,col] = que.front();
                que.pop();
                for(int j=0;j<4;j++){
                    int nr = row+dirs[j][0];
                    int nc = col+dirs[j][1];
                    if(nr<0||nc<0||nr>=m||nc>=n||grid[nr][nc]!=1){
                        continue;
                    }
                    grid[nr][nc] = 2;
                    que.push({nr,nc});
                    fresh--;
                }
            }
            time++;
        }
        return fresh==0?time:-1;
    }
};
