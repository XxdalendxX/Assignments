#pragma once
#include <functional>

namespace HashFunction {

    typedef std::function< unsigned int(const char*, unsigned int)> HashFunc;

    // implementation of a basic addition hash
    unsigned int badHash(const char* data, unsigned int length);

    // 
    unsigned int BKDRHash(const char* data, unsigned int size);

    // 
    unsigned int ELFHash(const char* data, unsigned int size);

    // ADD YOUR FUNCTIONS HERE
    
    // a helper to access a default hash function
    static HashFunc Dfault = BKDRHash;
}