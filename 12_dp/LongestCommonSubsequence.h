#ifndef LONGESTCOMMONSUBSEQUENCE_H
#define LONGESTCOMMONSUBSEQUENCE_H

#include <string>

/**
 * @brief 最长公共子序列
 * 
 */
class LCS
{
public:
    static int solver(std::string &s1, std::string &s2)
    {
        int dp[MAX][MAX] = {0}; // dp[i][j]: s1[0...i]与s2[0...j]的LCS长度
        int l1 = s1.length(), l2 = s2.length();
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[l1][l2];
    }

private:
    static const int MAX = 101;
};

#endif /* LONGESTCOMMONSUBSEQUENCE_H */
