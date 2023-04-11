class Solution {
    int m, n;
    const vector<pair<int,int>> directs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(int i, int j, vector<vector<int>>& grid)
    {
        grid[i][j] = 0;
        
        for (auto &direct:directs)
        {
            int x = i + direct.first;
            int y = j + direct.second;

            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;

            if (grid[x][y]) dfs(x, y, grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0]) dfs(i, 0, grid);
            if (grid[i][n - 1]) dfs(i, n - 1, grid);
        }  
        for (int i = 0; i < n; i++)
        {
            if (grid[0][i]) dfs(0, i, grid);
            if (grid[m - 1][i]) dfs(m - 1, i, grid);
        }

        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res += grid[i][j];

        return res;
    }
};
