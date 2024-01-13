#include <iostream>

#include "Version.hpp"
#include "raylib.h"

int main()
{
    std::cout << "Raylib Project Template v" << GetVersion() << std::endl;
    std::cout << "Based on Raylib v" << RAYLIB_VERSION << std::endl;
}
