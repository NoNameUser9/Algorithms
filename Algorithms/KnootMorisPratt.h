#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Функция для создания префикс-функции
vector<int> computeLPSArray(string pattern)
{
    int patternLength = pattern.length();
    vector<int> lps(patternLength);
    int len = 0;
    lps[0] = 0; // LPS для первого символа всегда 0

    int i = 1;
    while (i < patternLength)
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
void KMPSearch(string text, string pattern)
{
    int textLength = text.length();
    int patternLength = pattern.length();

    vector<int> lps = computeLPSArray(pattern);

    int i = 0; // Индекс для текста
    int j = 0; // Индекс для образца
    while (i < textLength)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }
        if (j == patternLength)
        {
            cout << "Найдено совпадение с позиции " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < textLength && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
