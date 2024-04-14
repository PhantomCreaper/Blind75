// 994. Rotting Oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i = 0; i < rows; i++){
            for (int j = 0; j<cols; j++) {
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0){
            return 0;
        }
        int min = 0;

        while(!q.empty()){
            min++;
            int count = q.size();
            for(int i =0 ; i< count; i++){
                auto [x, y] = q.front();
                q.pop();
                for(auto& d: dir){
                    int r = x + d[0];
                    int c = y + d[1];
                    if(r >=0 && r < rows && c>=0 && c<cols && grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r, c});
                        fresh--;
                    }
                }
            }
        }
        return fresh == 0 ? min-1 : -1; 

    }
};
