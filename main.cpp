#include "raylib.h"
#include <vector>
#include <string> // Include this header for std::to_string

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int CELL_SIZE = SCREEN_WIDTH / 9;

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();
    void clear();
    void present();
    bool isOpen();
    void pollEvents();

private:
    bool open;
};

Window::Window(const char* title, int width, int height) {
    InitWindow(width, height, title);
    open = true;
    SetTargetFPS(60);  // Set the frame rate
}

Window::~Window() {
    CloseWindow();
}

void Window::clear() {
    BeginDrawing();
    ClearBackground(RAYWHITE);  // White background
}

void Window::present() {
    EndDrawing();
}

bool Window::isOpen() {
    return !WindowShouldClose();
}

void Window::pollEvents() {
    // Raylib handles events internally with WindowShouldClose, so no need for explicit event polling here
}

class GameObject {
public:
    virtual void render() = 0;
};

class Cell : public GameObject {
public:
    Cell(int x, int y, int size, int value) : x(x), y(y), size(size), value(value) {}
    void render() override {
        DrawRectangle(x, y, size, size, LIGHTGRAY); // Grey color
        if (value != 0) {
            DrawText(std::to_string(value).c_str(), x + size / 2 - 10, y + size / 2 - 10, 20, DARKGRAY);
        }
    }

private:
    int x, y, size, value;
};

int main() {
    Window window("Sudoku", SCREEN_WIDTH, SCREEN_HEIGHT);

    std::vector<std::vector<int>> grid(9, std::vector<int>(9, 0));
    grid[0][0] = 5;
    grid[1][1] = 3;
    grid[2][2] = 6;

    while (window.isOpen()) {
        window.pollEvents();
        window.clear();

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                Cell cell(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, grid[i][j]);
                cell.render();
            }
        }

        window.present();
    }

    return 0;
}
