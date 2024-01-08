#include <random>
#include <iostream>
#include <algorithm>

#include "include/color.hpp"
#include "include/clipboardxx.hpp"

std::string random_string( size_t length)
{
    std::random_device rd;
    std::mt19937_64 rng(rd());

    auto randchar = [&rng]() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!@#$%^&*()";
        const size_t max_index = (sizeof(charset) - 1);
        std::uniform_int_distribution<int> dist(0, max_index);
        int id = dist(rng);
        return charset[id];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

int main()
{
    std::string pswrd = random_string(16);
    clipboardxx::clipboard cb;
    cb << pswrd;
    std::cout << "Password: " << colors::green << pswrd << colors::reset << std::endl << std::endl;

    return 0;
}