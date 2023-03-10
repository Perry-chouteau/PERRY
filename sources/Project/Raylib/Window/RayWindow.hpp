/**
 *
 * File: IWindow.hpp
 * Created Date: Fr Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Fri Mar 10 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#include "../../Interface/Window/IWindow.hpp"
#include "raylib.h"
#include <iostream>

class RayWindow : public IWindow {

    public:
        RayWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
            InitWindow(screenWidth, screenHeight, "raylib");
//            SetTargetFPS(60);
        };

        bool isReady() override {
            return IsWindowReady();
        };

        bool isOpen() override {
            return !WindowShouldClose();
        };

        void close() override {
            CloseWindow();
        };

        void beginDraw() override {
            BeginDrawing();
            ClearBackground(BLACK);
        };

        void endDraw() override {
            EndDrawing();
        };

    private:
};