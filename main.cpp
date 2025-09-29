#include <iostream>
#include <raylib.h>
#include "raymath.h"

const int screenWidth = 1600;
const int screenHeight = 900;

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
        direction = Vector2{0, 0};
        if (IsKeyDown(KEY_W)) { direction.y -= 1; }
        if (IsKeyDown(KEY_S)) { direction.y += 1; }
        if (IsKeyDown(KEY_D)) { direction.x += 1; }
        if (IsKeyDown(KEY_A)) { direction.x -= 1; }

        // Applies the normalised movement.
        position += Vector2Normalize(direction) * speed;

        if (position.x - radius < 0) { position.x = 0 + radius; }
        else if (position.x + radius > screenWidth) { position.x = screenWidth - radius; }
        if (position.y - radius < 0) { position.y = 0 + radius; }
        else if (position.y + radius > screenHeight) { position.y = screenHeight - radius; }
    }
};

Ball ball;

int main() {

    InitWindow(screenWidth, screenHeight, "Raylib Project Woa");
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