//
// Created by momik on 27.11.2019.
//

#ifndef VERNAMCIPHER_VERNAMCIPHER_H
#define VERNAMCIPHER_VERNAMCIPHER_H

#include <string>
#include <fstream>
#include <time.h>

class VernamCipher{
private:
    static const int BUF_SIZE = 100;
    static char *vernamCipher(const char* key, const char *buffer, int length);
    static char *generatingKey(int len);
public:
    static void encrypt(const std::string& pathName);
    static void decrypt(const std::string&, const std::string&);
};

#endif //VERNAMCIPHER_VERNAMCIPHER_H
