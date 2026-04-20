class Solution {
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;
public:
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        m = grid[0].size();
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        int minH = grid[0][0],maxH = grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                minH = min(minH,grid[i][j]);
                maxH = max(maxH,grid[i][j]);
            }
        }

        //在水位高度為 $t$ 的時候，我能不能從起點走到終點
        int l = minH,r = maxH;
        while(l<r){
            int m = (l+r)/2;
            if(dfs(grid,visit,0,0,m)){//可通，往下找更小
                r = m;
            }else{
                l = m+1;//不通，調大
            }
            for(int i=0;i<n;i++){
                // 重置 visit 矩陣，為了下一次不同水位的測試
                fill(visit[i].begin(),visit[i].end(),false);
            }
        }
        return r;
    }

    bool dfs(vector<vector<int>>& grid,vector<vector<bool>>& visit,int r,int c,int t){
        if(r<0||c<0||r>=n||c>=m||visit[r][c]||grid[r][c]>t) return false;
        if(r==n-1&&c==m-1) return true;
        visit[r][c] = true;
        for(int i=0;i<4;i++){
            if(dfs(grid,visit,r+dirs[i][0],c+dirs[i][1],t)){
                return true;
            }
        }
        return false;
    }
};
