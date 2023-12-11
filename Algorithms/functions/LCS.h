#pragma once

#include <iostream>
#include <vector>

// using namespace std;

size_t longestCommonSubsequence(const std::string& text1, const std::string& text2) {
    const size_t m = text1.size();
    const size_t n = text2.size();
    std::vector<std::vector<size_t>> dp(m + 1, std::vector<size_t>(n + 1, 0));

    for (size_t i = 1; i <= m; i++)
        for (size_t j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[m][n];
}
