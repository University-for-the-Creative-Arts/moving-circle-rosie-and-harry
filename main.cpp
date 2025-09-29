#include <iostream>
#include "raylib.h"

class Ball {
    public:
    float x = 20, y = 30;

    void Draw() {
        DrawCircle(x, y, 10, BLUE);
    }
};

Ball ball;

int main() {
    const int screenWidth = 960;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib Starter Template");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        ball.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}