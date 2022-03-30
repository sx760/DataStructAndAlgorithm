#ifndef MINIMUMPATHSUM_H
#define MINIMUMPATHSUM_H

class MinPathSum
{
public:
    static int solver(int grid[][3], int m, int n)
    {
        int dp[MAX][MAX] = {0};
        dp[0][0] = grid[0][0];
        // 第一行只能从左边来
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        // 第一列只能从上边来
        for (int j = 1; j < n; j++)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

private:
    static const int MAX = 101;
};

#endif /* MINIMUMPATHSUM_H */
