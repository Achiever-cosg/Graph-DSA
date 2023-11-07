// https://leetcode.com/problems/surrounded-regions/description/

/*
    The 'O' which are either on the border or connected to an 'O'
    on which is there on hte the border will not be converted
    else the remaining 'O' will be converted to 'X' 
*/

class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>&  vis, int delrow[], int delcol[])
    {
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;
        for(int i=0; i<4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
a
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] 
                && board[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, board, vis, delrow, delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, -1, 0, +1};

        for(int j=0; j<m; j++)
        {
            // first row
            if(!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, board, vis, delrow, delcol);

            // last row
            if(!vis[n-1][j] && board[n-1][j] == 'O')
                dfs(n-1, j, board, vis, delrow, delcol);
        }

        for(int i=0; i<n; i++)
        {
            // first column
            if(!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, board, vis, delrow, delcol);

            // last column
            if(!vis[i][m-1] && board[i][m-1] == 'O')
                dfs(i, m-1, board, vis, delrow, delcol);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j] == 0 && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

    }
};

/*
    Complexity Analysis:
        T(N) = O(n*m)
        S(N) = O(n*m)
*/