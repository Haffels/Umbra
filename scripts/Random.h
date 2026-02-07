#ifndef HAVLOCK_RANDOM_H
#define HAVLOCK_RANDOM_H
#include <array>
#include <random>
#include <openssl/rand.h>

class Random
{
    public:
    static std::array<unsigned char, 32> generateAESKey() {
        std::array<unsigned char, 32> key;

        if (!RAND_bytes(key.data(), key.size()))
            throw std::runtime_error("Failed to generate cryptographic key");

        return key;
    }

    static std::array<unsigned char, 12> generateNonce() {
        std::array<unsigned char, 12> key;

        if (!RAND_bytes(key.data(), key.size()))
            throw std::runtime_error("Failed to generate nonce");

        return key;
    }
};


#endif