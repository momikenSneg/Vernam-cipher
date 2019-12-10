//
// Created by momik on 27.11.2019.
//
#include <iostream>
#include "VernamCipher.h"

void VernamCipher::encrypt(const std::string& pathName){
    std::ifstream in(pathName, std::ifstream::binary);
    std::ofstream out("code.txt");
    std::ofstream kout("key.txt");
    srand (time(nullptr));

    char * buffer = new char [BUF_SIZE];

    in.read(buffer, BUF_SIZE);
    while (in.gcount() > 0){
        char *key = generatingKey(in.gcount());
        char * cod = vernamCipher(key, buffer, in.gcount());
        kout.write(key, in.gcount());
        out.write(cod, in.gcount());
        delete[] key;
        delete[] cod;
        in.read(buffer, BUF_SIZE);
    }

    delete[]  buffer;
    in.close();
    out.close();
    kout.close();
}

void VernamCipher::decrypt(const std::string& pathKey, const std::string& pathIn){
    std::ifstream in(pathIn, std::ifstream::binary);
    std::ifstream kin(pathKey, std::ifstream::binary);

    char *buf = new char[BUF_SIZE];
    char *key = new char[BUF_SIZE];

    in.read(buf, BUF_SIZE);
    kin.read(key, BUF_SIZE);

    while (in.gcount() > 0 && kin.gcount() > 0){
        for(int i = 0; i < in.gcount(); i++){
            std::cout << static_cast<char>(buf[i] ^ key[i]);
        }
        in.read(buf, BUF_SIZE);
        kin.read(key, BUF_SIZE);
    }

    delete[] buf;
    delete[] key;
    in.close();
    kin.close();
}

char *VernamCipher::vernamCipher(const char* key, const char *buffer, int length){
    char *cod = new char[length];
    for (int i = 0; i < length; i++){
        cod[i] = static_cast<char>(buffer[i] ^ key[i]);
    }
    return cod;
}

char *VernamCipher::generatingKey(int len){
    char *key = new char[len];
    for (int i = 0; i < len; i++){
        char c = static_cast<char>(rand() % 255);
        key[i] = c;
    }
    return key;
}