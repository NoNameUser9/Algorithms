#pragma once
#include <iostream>
#include <string>
// using namespace std;
void searchRabinKarp(std::string const& text, std::string const& pattern, const int prime)
{
    const size_t pattern_length = pattern.length();
    const size_t text_length = text.length();
    int pattern_hash = 0; // Хэш подстроки pattern
    int text_hash = 0;    // Хэш текущего окна текста

    int h = 1;
    for (size_t i = 0; i < pattern_length - 1; i++)
        h = (h * 256) % prime;

    // Рассчитываем хэш для подстроки pattern и для первого окна текста
    for (size_t i = 0; i < pattern_length; i++)
    {
        pattern_hash = (256 * pattern_hash + pattern[i]) % prime;
        text_hash = (256 * text_hash + text[i]) % prime;
    }

    // Проходимся по тексту
    for (size_t i = 0; i <= text_length - pattern_length; i++)
    {
        // Проверяем совпадение хэшей, если хэши совпали, проверяем посимвольно
        if (pattern_hash == text_hash)
        {
            size_t j;
            for (j = 0; j < pattern_length; j++)
                if (text[i + j] != pattern[j])
                    break;
            if (j == pattern_length)
                std::cout << "Founded similar text from pos " << i << std::endl;
        }

        // Пересчитываем хэш для следующего окна текста
        if (i < text_length - pattern_length)
        {
            text_hash = (256 * (text_hash - text[i] * h) + text[i + pattern_length]) % prime;
            if (text_hash < 0)
                text_hash = (text_hash + prime);
        }
    }
}