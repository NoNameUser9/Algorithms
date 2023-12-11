#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

// Функция вычисления редакционного расстояния
size_t editDistance(const std::string& word1, const std::string& word2) {
    const size_t m = word1.length();
    const size_t n = word2.length();
    std::vector<std::vector<size_t>> dp(m + 1, std::vector<size_t>(n + 1, 0));

    for (size_t i = 0; i <= m; i++) {
        for (size_t j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
            }
        }
    }

    return dp[m][n];
}
