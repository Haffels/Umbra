#ifndef HAVLOCK_ENCRYPT_H
#define HAVLOCK_ENCRYPT_H
#include <openssl/evp.h>
#include <vector>

#include "Random.h"

class Encrypt
{
    public:
    static std::vector<unsigned char> AES256GCM (
        const std::string& plainText,
        const std::array<unsigned char, 32>& secretKey,
        const std::array<unsigned char, 12>& nonce,
        std::array<unsigned char, 16>& tag
        )
    {
        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
        std::vector<unsigned char> cipherText(plainText.size());
        int len;

        EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL);
        EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, nonce.size(), NULL);
        EVP_EncryptInit_ex(ctx, NULL, NULL, secretKey.data(), nonce.data());
        EVP_EncryptUpdate(ctx, cipherText.data(), &len, (const unsigned char*)plainText.data(), plainText.size());
        int finalLen;

        EVP_EncryptFinal_ex(ctx, nullptr, &finalLen);
        EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, 16, tag.data());

        EVP_CIPHER_CTX_free(ctx);
        return cipherText;
    }

    static std::vector<unsigned char> D_AES256GCM (
        const std::string& cipherText,
        const std::array<unsigned char, 32>& secretKey,
        const std::array<unsigned char, 12>& nonce,
        std::array<unsigned char, 16>& tag
        )
    {
        std::vector<unsigned char> plainText(cipherText.size());

        return plainText;
    }
};

#endif