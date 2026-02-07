#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "Encrypt.h"

std::string loadFile()
{
    std::string plainText;
    std::string fileDir = "/Users/harry/Projects/C:C++/Havlock/file.txt";
    std::ifstream file(fileDir);

    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return std::string();
    }
    std::string line;
    while (std::getline(file, line))
        plainText.append(line);

    return plainText;
}

void displayStartScreen()
{
    std::cout << "\033[2J\033[1;1H";
    std::cout << "\033[1;34m" << R"(
:::    :::     :::     :::     ::: :::        ::::::::   ::::::::  :::    :::
:+:    :+:   :+: :+:   :+:     :+: :+:       :+:    :+: :+:    :+: :+:   :+:
+:+    +:+  +:+   +:+  +:+     +:+ +:+       +:+    +:+ +:+        +:+  +:+
+#++:++#++ +#++:++#++: +#+     +:+ +#+       +#+    +:+ +#+        +#++:++
+#+    +#+ +#+     +#+  +#+   +#+  +#+       +#+    +#+ +#+        +#+  +#+
#+#    #+# #+#     #+#   #+#+#+#   #+#       #+#    #+# #+#    #+# #+#   #+#
###    ### ###     ###     ###     ########## ########   ########  ###    ###
)" << "\033[0m";

    //Padding ---------------------------------
    std::cout << std::endl;
    //Padding ---------------------------------

    std::cout << "\x1b[1;38;5;222;49m" << "Your files. Your encryption." << "\x1b[0m";
}

int main()
{
    // displayStartScreen();

    std::string plainText = loadFile();
    std::array<unsigned char, 32> secretKey = Random::generateAESKey();
    std::array<unsigned char, 12> nonce  = Random::generateNonce();
    std::array<unsigned char, 16> tag;

    std::vector<unsigned char> encryptedText = Encrypt::AES256GCM(plainText, secretKey, nonce, tag);

    for (auto i : encryptedText)
        std::cout << i;
    return 0;
}
