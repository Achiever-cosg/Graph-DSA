// https://leetcode.com/problems/number-of-islands/description/

class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, -1, 0, +1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {   int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow<m && nrow >= 0 && ncol <n && ncol >= 0 && !vis[nrow][ncol] 
                && grid[nrow][ncol] == '1') {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && grid[i][j] == '1' ) {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};