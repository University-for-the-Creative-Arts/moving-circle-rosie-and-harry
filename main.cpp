#include <iostream>
#include <raylib.h>
#include "raymath.h"

const int screenWidth = 960;
const int screenHeight = 600;

class Ball {
    public:
    Vector2 position = Vector2{50, 50}, direction;
    float speed = 10;
    int radius = 40;

    void Draw() {
        DrawCircle(position.x, position.y, radius, BLUE);
    }

    void Update() {

        // Direction Movement
        if (IsKeyDown(KEY_W)) { direction.y = -1; }
        else if (IsKeyDown(KEY_S)) { direction.y = 1; }
        else { direction.y = 0; }
        if (IsKeyDown(KEY_D)) { direction.x = 1; }
        else if (IsKeyDown(KEY_A)) { direction.x = -1; }
        else { direction.x = 0; }

        // Applies the normalised movement.
        position += Vector2Normalize(direction) * speed;
    }
};

Ball ball;

int main() {

    InitWindow(screenWidth, screenHeight, "Raylib Starter Template");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        ball.Update();

        BeginDrawing();
        ClearBackground(BLACK);
        ball.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}