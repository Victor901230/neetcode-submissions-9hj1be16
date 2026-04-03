class Solution {
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==1){
                    area=max(area,dfs(grid,r,c));
                }
            }
        }
        return area;
    }

    int dfs(vector<vector<int>>&grid,int r,int c){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==0) return 0;
        grid[r][c]=0;
        int res=1;
        for(int i=0;i<4;i++){
            res+=dfs(grid,r+dirs[i][0],c+dirs[i][1]);
        }
        return res;
        
    }
};
