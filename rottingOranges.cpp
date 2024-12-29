// https://leetcode.com/problems/rotting-oranges/

class Solution {
private:
    bool isValid(int index, int n)
    {
        if(index >= 0 && index < n)
            return true;
        
        return false;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis (m, vector<int>(n,0));
        queue<pair<pair<int, int>, int>> q;
        int cntFresh = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }

                if(grid[i][j] == 1)
                    cntFresh++;
            }
        }

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        int maxTime = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto it = q.front();
                q.pop();

                int row = it.first.first;
                int col = it.first.second;
                int time = it.second;
                maxTime = max(time, maxTime);

                for(int i=0; i<4; i++)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(isValid(nrow, m) && isValid(ncol, n) && !vis[nrow][ncol] 
                        && grid[nrow][ncol] == 1)
                    {
                        q.push({{nrow, ncol}, time+1});
                        vis[nrow][ncol] = 1;
                        cntFresh--;
                    }
                }
            }
            
        }

        return (cntFresh == 0) ? maxTime : -1;
    }
};
