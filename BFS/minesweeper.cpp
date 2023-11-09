// https://leetcode.com/problems/minesweeper/

class Solution {
public:
    
    bool inboard(const vector<vector<char>>& board, int x, int y){
        return (x>=0 and x<board.size() and y>=0 and y<board[0].size());
    }
    
    void bfs(vector<vector<char>>& board, int sr, int sc)
    {
        vector<vector<int>>dirs = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},
        {-1,1}};
        
        queue<pair<int, int>>q;
        q.push({sr, sc});
            
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();   
            int x = cur.first;
            int y = cur.second;
            
            int count = 0;
            for(auto d : dirs)
            {
                int nx = x + d[0];
                int ny = y + d[1];        
                if(inboard(board, nx, ny) and board[nx][ny] == 'M')
                    count++;
            }
            
            if(count > 0){
                board[x][y] = count + '0';
            }
            else 
            { 
                board[x][y] = 'B';
                for(auto d : dirs){
                    
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(inboard(board, nx, ny) and board[nx][ny] == 'E') {
                        q.push({nx, ny});
                        board[nx][ny] = 'B';
                    }
                        
                }
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

        int r = click[0];
        int c = click[1];

        if(board[r][c] == 'M'){
            board[r][c]= 'X';
            return board;
        }
        
        bfs(board, r, c);
        return board;
    }
};