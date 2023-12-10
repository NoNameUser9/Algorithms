#pragma once
#include <iostream>
#include <string>
// using namespace std;
void searchRabinKarp(std::string const& text, std::string const& pattern, int prime)
{
    int patternLength = pattern.length();
    int textLength = text.length();
    int patternHash = 0; // Хэш подстроки pattern
    int textHash = 0;    // Хэш текущего окна текста

    int h = 1;
    for (int i = 0; i < patternLength - 1; i++)
        h = (h * 256) % prime;

    // Рассчитываем хэш для подстроки pattern и для первого окна текста
    for (int i = 0; i < patternLength; i++)
    {
        patternHash = (256 * patternHash + pattern[i]) % prime;
        textHash = (256 * textHash + text[i]) % prime;
    }

    // Проходимся по тексту
    for (int i = 0; i <= textLength - patternLength; i++)
    {
        // Проверяем совпадение хэшей, если хэши совпали, проверяем посимвольно
        if (patternHash == textHash)
        {
            int j;
            for (j = 0; j < patternLength; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == patternLength)
                std::cout << "Founded similar text from pos " << i << std::endl;
        }

        // Пересчитываем хэш для следующего окна текста
        if (i < textLength - patternLength)
        {
            textHash = (256 * (textHash - text[i] * h) + text[i + patternLength]) % prime;
            if (textHash < 0)
                textHash = (textHash + prime);
        }
    }
}