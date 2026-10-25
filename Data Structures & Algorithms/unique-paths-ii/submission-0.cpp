class Solution {
public:
    vector<vector<int>> dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int ROWS = obstacleGrid.size(), COLS = obstacleGrid[0].size();
        dp.resize(ROWS, vector<int>(COLS,0));

        return dfs(0,0, ROWS, COLS, obstacleGrid);
    
    }

    int dfs(int r, int c, int ROWS, int COLS, vector<vector<int>>& grid){

        if(r == ROWS || c == COLS || grid[r][c] == 1){
            return 0;
        }
        if( r == ROWS-1 && c == COLS-1){
            return 1;
        }
        if(dp[r][c]>0){
            return dp[r][c];
        }

        dp[r][c] = dfs(r + 1, c, ROWS, COLS, grid) + dfs(r, c + 1, ROWS, COLS, grid);
        return dp[r][c];
    }
};