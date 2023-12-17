#pragma once

#include <iostream>
#include <string>
#include <algorithm>

inline std::string LongestCommonSubsequence(const std::string& str1, const std::string& str2)
{
    const size_t m = str1.size();
    const size_t n = str2.size();

    // Создаем двумерный массив для хранения длин подпоследовательностей
    const auto dp = new size_t* [m + 1];
    for (size_t i = 0; i <= m; ++i)
    {
        dp[i] = new size_t[n + 1];
        memset(dp[i], 0, sizeof(int) * (n + 1));
    }

    for (size_t i = 0; i <= m; ++i)
        for (size_t j = 0; j <= n; ++j)
            dp[i][j] = 0;
    // Заполняем массив длин подпоследовательностей
    for (size_t i = 1; i <= m; ++i)
        for (size_t j = 1; j <= n; ++j)
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

    // Восстанавливаем наибольшую общую подпоследовательность
    std::string lcs;
    lcs.resize((m+1)*(n+1));
    // size_t t = dp[m][n];

    if(dp[m][n] == 0)
        throw std::logic_error("error of LCS");
    lcs[dp[m][n]] = '\0';

    
    size_t i = m, j = n, index = dp[m][n];
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[--index] = str1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}
