#include <iostream>
#include <string>

#include "functions\EditDistance.hxx"
#include "support_functions\io.hxx"
#include "functions\KnootMorisPratt.hxx"
#include "functions\LongestCommonSubsequence.hxx"
#include "functions\RabinKarp.hxx"
#include "support_functions\time.hxx"

#define VER "0.1.0"

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
    text.pop_back();
  
    size_t choice = 0;
    while (true)
    {
        main:
        system("cls");

        std::cout << "Algorithms program v" << VER << "\n"
                     "1. Найти подстроку с помощью алгоритма Рабина-Карпа\n"
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
            try
            {
                NNU9::time t;
                t.start();
                searchRabinKarp(text, pattern, prime);
                t.end();
                std::cout << t.count().count() << "\n";
            }
            catch (std::exception& ex)
            {
                std::cerr << "Caught: " << ex.what() << "\n";
                std::cerr << "Type: " << typeid(ex).name() << "\n";
            }
            
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
            while (true)
            {
                system("cls");
                try
                {
                    NNU9::time t;
                    t.start();
                    auto lcs = LongestCommonSubsequence(text, pattern);
                    t.end();
                    std::cout << t.count().count() << "\n";
                    std::cout << "Наибольшая общая подпоследовательность: " << lcs << '\n';
                }
                catch (std::exception& ex)
                {
                    std::cerr << "Caught: " << ex.what() << '\n';
                    std::cerr << "Type: " << typeid(ex).name() << '\n';
                }
                unsigned short sw = 0;
                std::cout << "1 word [" << text << "]\n"
                             "2 word [" << pattern << "]\n"
                             "1.swap\n"
                             "2.exit\n";
                std::cin >> sw;
                switch (sw)
                {
                case 1:
                {
                    const auto temp = pattern;
                    pattern = text;
                    text = temp;
                    break;
                }
                case 2:
                {
                    goto main;
                }
                }
                // system("pause");
            }
        }
        case 4:
        {
            while (true)
            {
                system("cls");
                NNU9::time t;
                t.start();
                std::cout << "Edit distance between " << text << " and " << pattern << " is: " << editDistance(text, pattern) << '\n';
                t.end();

                std::cout << t.count().count() << "\n";
                std::cout << "1.change 1 word [" << text << "]\n"
                             "2.change 2 word [" << pattern << "]\n"
                             "3.swap\n"
                             "4.exit\n";

                unsigned short ch4 = 0;
                std::cin >> ch4;
                switch (ch4)
                {
                case 1:
                {
                    char c[1] {};
                    std::cout << "Enter the word: ";
                    std::cin.getline(c, 1);
                    std::getline(std::cin, text);

                    break;
                }
                case 2:
                {
                    char c[1] {};
                    std::cout << "Enter the word: ";
                    std::cin.getline(c, 1);
                    std::getline(std::cin, pattern);

                    break;
                }
                case 3:
                {
                    const auto temp = pattern;
                    pattern = text;
                    text = temp;
                    break;
                }
                case 4:
                {
                    goto main;
                }
                default:
                {
                    break;
                }
                }
            }
        }
        case 5:
            {
                system("cls");
                char c[1] {};
                std::cout << "Enter the word: ";
                std::cin.getline(c, 1);
                std::getline(std::cin, pattern);
            
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
}