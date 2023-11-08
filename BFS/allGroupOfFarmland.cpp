// https://leetcode.com/problems/find-all-groups-of-farmland/

/*
    Approach: Perform BFS for each farm and mark its all adjacents lands ans visited
        The last visited land(cell) will be the end of that group.
*/

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& land, vector<vector<int>>& vis,
        vector<vector<int>>& ans, int delrow[], int delcol[])
        {
            queue<pair<int, int>> q;
            q.push({row, col});
            vis[row][col] = 1;
            pair<int, int> tempAns;
            int n = land.size();
            int m = land[0].size();

            vector<int> v;
            v.push_back(row);
            v.push_back(col);

            while(!q.empty())
            {
                auto it = q.front();
                q.pop();

                int row = it.first;
                int col = it.second;
                tempAns = {row, col};

                for(int i=0; i<4; i++)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                        && !vis[nrow][ncol] && land[nrow][ncol] == 1)
                        {
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                }
            }

            v.push_back(tempAns.first);
            v.push_back(tempAns.second);

            ans.push_back(v);
        }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        if(n == 1 && m == 1)
        {
            if(land[0][0] == 0)
                return {};
            else
                return {{0, 0, 0, 0}};
        }
        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<vector<int>> ans;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, -1, 0, +1};

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && land[i][j] == 1)
                {
                    bfs(i, j, land, vis, ans, delrow, delcol);
                }
            }
        }

        return ans;
    }
};