//If needs 8 direction there is a slightly change so it may be done when required.

class Solution {
private:
    void bfs(int i, int j, int n, int m,
             vector<vector<int>>& visited,
             vector<vector<char>>& grid) {

        visited[i][j] = 1;

        queue<pair<int, int>> que;
        que.push({i, j});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!que.empty()) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();

            for (int k = 0; k < 4; k++) {
                int neighbourRow = row + delRow[k];
                int neighbourCol = col + delCol[k];

                if (neighbourRow >= 0 && neighbourRow < n &&
                    neighbourCol >= 0 && neighbourCol < m &&
                    !visited[neighbourRow][neighbourCol] &&
                    grid[neighbourRow][neighbourCol] == '1') {

                    visited[neighbourRow][neighbourCol] = 1;
                    que.push({neighbourRow, neighbourCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int counter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(i, j, n, m, visited, grid);
                    counter++;
                }
            }
        }

        return counter;
    }
};
