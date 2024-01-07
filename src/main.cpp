#include <ctime>
#include <iostream>
#include <algorithm>

#include "include/color.hpp"
#include "include/clipboardxx.hpp"

std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!@#$%^&*()";;
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

int main()
{
    std::srand(std::time(nullptr));
    std::string pswrd = random_string(16);
    clipboardxx::clipboard cb;
    cb << pswrd;
    std::cout << "Password: " << colors::green << pswrd << colors::reset << std::endl << std::endl;

    return 0;
}