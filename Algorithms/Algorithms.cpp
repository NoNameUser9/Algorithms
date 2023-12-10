#include <iostream>
#include <string>

#include "KnootMorisPratt.h"
#include "RabinKarp.h"
using namespace std;

// ������� ��� ������ ��������� pattern � ������ text � ������� ��������� ������-�����


int main()
{
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    int prime = 101; // ������� ����� ��� ���������� ����, ������ ����� ������� ������� �����

    searchRabinKarp(text, pattern, prime);

    // string text = "ABABDABACDABABCABAB";
    // string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
    
    return 0;
}