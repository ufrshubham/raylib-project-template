#include <iostream>
#include <filesystem>

#include "Version.hpp"
#include "raylib.h"

static void modifyCurrentWorkingDirectory();

int main()
{
    modifyCurrentWorkingDirectory();
    std::cout << "Raylib Project Template v" << GetVersion() << std::endl;
    std::cout << "Based on Raylib v" << RAYLIB_VERSION << std::endl;

    const auto screenWidth = 800;
    const auto screenHeight = 450;

    const auto fontSize = 50;
    const auto fontSpacing = 1.5;
    const auto text = "Raylib Project Template v" + GetVersion();

    InitWindow(screenWidth, screenHeight, "Raylib-Project");
    {
        const auto font = LoadFont("resources/PixelMiddle.ttf");
        const auto textWidth = MeasureTextEx(font, text.c_str(), fontSize, fontSpacing);
        const auto x = (screenWidth * 0.5f - textWidth.x * 0.5f);
        const auto position = Vector2{x, 200};

        SetTargetFPS(60);

        while (!WindowShouldClose())
        {
            BeginDrawing();
            {
                ClearBackground(BLACK);

                DrawTextEx(font, text.c_str(), position, fontSize, fontSpacing, WHITE);
            }
            EndDrawing();
        }
        UnloadFont(font);
    }
    CloseWindow();
}

void modifyCurrentWorkingDirectory()
{
    while (!std::filesystem::exists("resources"))
    {
        std::filesystem::current_path(std::filesystem::current_path().parent_path());
    }
    auto cwd = std::filesystem::current_path();
}
