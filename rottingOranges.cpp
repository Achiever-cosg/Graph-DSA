// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cntFresh = 0;

        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }

                if(grid[i][j] == 1)
                    cntFresh++;
            }
        }

        int flag = 0, time = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty())
        {
            int sz = q.size();
            if(flag == 0)
                flag++;
            else
                time++;
                
            for(int a=0; a<sz; a++)
            {
                auto it = q.front();
                q.pop();

                int row = it.first;
                int col = it.second;

                for(int i=0; i<4; i++)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                        && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                        cntFresh--;
                    }
                }
            }
        }

        if(cntFresh == 0)
            return time;

        return -1;
    }
};

