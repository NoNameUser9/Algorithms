#pragma once

#include <iostream>
#include <vector>
#include <string>
// using namespace std;

// Функция для создания префикс-функции
inline std::vector<size_t> compute_lps_array(const std::string& pattern)
{
    const size_t pattern_length = pattern.length();
    std::vector<size_t> lps(pattern_length);
    size_t len = 0;
    lps[0] = 0; // LPS для первого символа всегда 0

    size_t i = 1;
    while (i < pattern_length)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1]; // Не сбрасываем len, а просто переходим к предыдущему символу, т.к. совпадение возможно по префиксу
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Функция для поиска всех вхождений подстроки в строке с помощью алгоритма КМП
void KMPSearch(const std::string& text, const std::string& pattern)
{
    const size_t text_length = text.length();
    const size_t pattern_length = pattern.length();

    const std::vector<size_t> lps = compute_lps_array(pattern);

    size_t i = 0; // Индекс для текста
    size_t j = 0; // Индекс для образца
    while (i < text_length)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }
        if (j == pattern_length)
        {
            // cout << "Найдено совпадение с позиции " << i - j << endl;
            std::cout << "Founded similar text from pos " << i - j << std::endl;
            j = lps[j - 1];
        }
        else if (i < text_length && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
