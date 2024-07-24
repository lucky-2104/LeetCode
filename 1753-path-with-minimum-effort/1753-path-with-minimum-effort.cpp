class Solution {
public:
    vector<pair<int, int>> dirc = {{0, -1}, {1, 0}, {-1, 0}, {0, 1}};
    
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> effort(n, vector<int>(m, 1e9));

        int r_src = 0;
        int c_src = 0;
        int r_dest = n - 1;
        int c_dest = m - 1;

        effort[r_src][c_src] = 0;

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;

        q.push({0, {r_src, c_src}});

        while (!q.empty()) {
            auto p = q.top();
            int eff = p.first;
            int row = p.second.first;
            int col = p.second.second;
            q.pop();

            if (row == r_dest && col == c_dest) {
                return eff;
            }

            for (auto d : dirc) {
                int new_row = row + d.first;
                int new_col = col + d.second;

                if (new_row >= 0 && new_col >= 0 && new_row < n &&
                    new_col < m) {

                    int new_eff = max(abs(grid[row][col] - grid[new_row][new_col]), eff);

                    if (effort[new_row][new_col] > new_eff) {
                        effort[new_row][new_col] = new_eff;
                        q.push({effort[new_row][new_col], {new_row, new_col}});
                    }
                }
            }
        }

        return 0;
    }
};