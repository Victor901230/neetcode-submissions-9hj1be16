class Solution {
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> toPacific(m,vector<bool>(n,false));
        vector<vector<bool>> toAtlantic(m,vector<bool>(n,false));

        for(int i = 0;i<n;i++){
            dfs(heights,toPacific,0,i);
            dfs(heights,toAtlantic,m-1,i);
        }
        for(int i = 0;i<m;i++){
            dfs(heights,toPacific,i,0);
            dfs(heights,toAtlantic,i,n-1);
        }

        for(int r = 0;r<m;r++){
            for(int c=0;c<n;c++){
                if(toPacific[r][c]&&toAtlantic[r][c]){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }

    //修改ocean陣列判斷能否走到/是否處理過(海邊一定走到、)
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& ocean,int r,int c){
        ocean[r][c] = true;//處理過&&可走到，因上一步判斷範圍等條件，所以一定可以走到
        for(int i=0;i<4;i++){
            int nr = r+dirs[i][0];
            int nc = c+dirs[i][1];
            if(nr>=0&&nc>=0&&nr<heights.size()&&nc<heights[0].size()&&ocean[nr][nc]==false&&heights[nr][nc]>=heights[r][c]){
                dfs(heights,ocean,nr,nc);
            }
        }
    }
};
