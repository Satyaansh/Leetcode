class Solution {
public:
    void rec(vector<vector<int>> &grid, vector<vector<bool>> &vis, int &temp_area, int row, int col, int n, int m){
        if(row < 0 || col < 0 || row >= n || col >= m || vis[row][col] == true || grid[row][col] == 0)
            return;
        temp_area++;
        vis[row][col] = true;
        rec(grid, vis, temp_area, row + 1, col, n, m);
        rec(grid, vis, temp_area, row, col + 1, n, m);
        rec(grid, vis, temp_area, row - 1, col, n, m);
        rec(grid, vis, temp_area, row, col - 1, n, m);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0, temp_area = 0;
        vector<vector<bool>> vis (n, vector<bool> (m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    rec(grid, vis, temp_area, i, j, n, m);
                    ans = max(ans, temp_area);
                    temp_area = 0;
                }
            }
        }
        return ans;
    }
};
