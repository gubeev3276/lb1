#include <iostream>
#include <cctype>
#include "modAlphaCipher.hpp"
#include <locale>
using namespace std;
bool isValid(const wstring& s) // Проверка строки
{
    for(auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring key;
    wstring text;
    unsigned op;
    wcout<<L"Введите ключ: ";
    wcin>>key;
    if (!isValid(key)) {
        wcerr<<L"Формат ключа задан неправильно\n"; //Ключ должен быть в формате слова
        return 1;
    }
    wcout<<L"Ключ подошел\n";
    modAlphaCipher cipher(key);
    do {
        wcout<<L"Операции (0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
        if (op > 2) {
            wcout<<L"Невозможная операция\n"; 
        } else if (op >0) {
            wcout<<L"Введите тект: ";
            wcin>>text;
            if (isValid(text)) {
                if (op==1) {
                    wcout<<L"Зашифрованный текст: "<<cipher.encrypt(text)<<endl;
                } else {
                    wcout<<L"Расшифрованный текст: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                wcout<<L"Текст задан не в том формате\n";
            }
        }
    } while (op!=0);
    return 0;
}