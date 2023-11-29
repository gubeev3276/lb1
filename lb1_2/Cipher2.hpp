#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Cipher2
{
private:
    int p;
public:
    Cipher2()=delete;
    Cipher2(int w);
    wstring CoderCipher2(Cipher2 w, wstring& s);
    wstring DecoderCipher2(Cipher2 w, wstring& s);
};