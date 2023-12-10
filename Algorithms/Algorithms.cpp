#include <iostream>
#include <string>

#include "KnootMorisPratt.h"
#include "RabinKarp.h"
using namespace std;

// Функция для поиска подстроки pattern в строке text с помощью алгоритма Рабина-Карпа


int main()
{
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    int prime = 101; // Простое число для вычисления хэша, обычно берут большое простое число

    searchRabinKarp(text, pattern, prime);

    // string text = "ABABDABACDABABCABAB";
    // string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
    
    return 0;
}