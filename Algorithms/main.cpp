#include <iostream>
#include <string>

#include "functions\EditDistance.h"
#include "support_functions/io.h"
#include "functions/KnootMorisPratt.h"
#include "functions\LongestCommonSubsequence.h"
#include "functions/RabinKarp.h"
#include "support_functions/time.h"

// Функция для поиска подстроки pattern в строке text с помощью алгоритма Рабина-Карпа

std::string path = R"(C:\Users\User\Documents\test.txt)";
int main()
{
    setlocale(LC_ALL, "rus");
    // std::string pattern = "test text for algorithm";
    // std::string pattern = "test text for algorithm and for test of test";
    std::string pattern = "Rayanov Daniil Ilgizovich";
    const unsigned short prime = 101; // Простое число для вычисления хэша, обычно берут большое простое число
    std::string text;
    read_file(text, path);
  
    size_t choice = 0;
    while (true)
    {
        main:
        system("cls");

        std::cout << "1. Найти подстроку с помощью алгоритма Рабина-Карпа\n"
                "2. Найти подстроку с помощью алгоритма Кнута-Мориса-Пратта\n"
                "3. Найти наибольшую общюю подпоследовательность\n"
                "4. Вычислить редакционное расстояние\n"
                "5. Ввести текст для поиска [" << pattern << "]\n"
                "6. Выход\n";

        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            NNU9::time t;
            t.start();
            try
            {
                searchRabinKarp(text, pattern, prime);
            }
            catch (std::exception& ex)
            {
                std::cerr << ex.what();
            }
            t.end();
            std::cout << t.count().count() << "\n";
            
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            NNU9::time t;
            t.start();
            KMPSearch(text, pattern);
            t.end();

            std::cout << t.count().count() << "\n";
            system("pause");

            break;
        }
        case 3:
        {
            system("cls");

            // a.start_timer();
            /*char* lcs = */
            NNU9::time t;
            t.start();
            auto lcs = LongestCommonSubsequence(text, pattern);
            t.end();
            std::cout << t.count().count() << "\n";
            std::cout << "Наибольшая общая подпоследовательность: " << lcs << '\n';

            system("pause");

            break;
        }
        case 4:
        {
            std::string word1 = "kitten";
            std::string word2 = "sitting";
            while (true)
            {
                system("cls");
                NNU9::time t;
                t.start();
                std::cout << "Edit distance between " << word1 << " and " << word2 << " is: " << editDistance(word1, word2) << '\n';
                t.end();

                std::cout << t.count().count() << "\n";
                std::cout << "1.change 1 word [" << word1 << "]\n"
                            "2.change 2 word [" << word2 << "]\n"
                            "3.exit\n";

                unsigned short ch4 = 0;
                std::cin >> ch4;
                switch (ch4)
                {
                case 1:
                {
                    char c[1] {};
                    std::string ts;
                    constexpr unsigned short size = 1024;
                    ts.resize(size);
                    std::cout << "Enter the word: ";
                    std::cin.getline(c, 1);
                    std::cin.getline(const_cast<char*>(ts.c_str()), size);
                    word1 = ts;
                    
                    break;
                }
                case 2:
                {
                    char c[1] {};
                    std::string ts;
                    constexpr unsigned short size = 1024;
                    ts.resize(size);
                    std::cout << "Enter the word: ";
                    std::cin.getline(c, 1);
                    std::cin.getline(const_cast<char*>(ts.c_str()), size);
                    word2 = ts;
                    break;
                }
                case 3:
                {
                    goto main;
                }
                default:
                {
                    break;
                }
                }
                
            }
            
            break;
        }
        case 5:
            {
                system("cls");
                char c[1] {};
                std::string ts;
                constexpr unsigned short size = 1024;
                ts.resize(size);
                std::cout << "Enter the word: ";
                std::cin.getline(c, 1);
                std::cin.getline(const_cast<char*>(ts.c_str()), size);
                // std::cout << "Введите слово:";
                // std::cin >> pattern;
                pattern = ts;
                // system("pause");
                break;
            }
        case 6:
        {
            exit(EXIT_SUCCESS);
        }
        default:
            break;
        }
    }
    
    return 0;
}