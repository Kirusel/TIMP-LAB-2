#include <stdio.h>
#include <iostream>
#include <cctype>
#include "Cipher.h"
#include <locale>
using namespace std;
void check(const wstring& Text, const int & key)
{
    wstring s=Text;
    try {
        Cipher skey(key);
        wcout<<skey.CoderPerestanCipher(key, s)<<endl;
        wstring g=skey.CoderPerestanCipher(key, s);
        wcout<<skey.DecoderPerestanCipher(key,g)<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"HelLOW0rLD",8);
	check(L"HelLOW0rLD",4);
    check(L"TESTMESSAGE",10);
    check(L"LDFHFEUFHWBCD",5);
    return 0;
}