class Solution {
    int res=0;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]=='1'){
                    dfs(grid,r,c);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>&grid,int r,int c){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]=='0') return;
        grid[r][c]='0';
        for(int i=0;i<4;i++){
            dfs(grid,r+dirs[i][0],c+dirs[i][1]);
        }
    }
};
