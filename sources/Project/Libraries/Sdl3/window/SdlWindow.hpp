/**
 *
 * File: RayWindow.hpp (header.v2)
 * Created Date: Tue 14/03/2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Sat 18/03/2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#ifndef SDLWINDOW_HPP_
#define SDLWINDOW_HPP_
//Sdl
#include "SDL.h" //#include <SDL2/SDL.h>
#include "SDL_image.h"

//Interface
#include "../../../Interfaces/graphic3/window/IWindow.hpp"
#include "../../../Interfaces/system/math.hpp"
//encapsulation
#include "../graphic/SdlPolygon.hpp"
#include "../graphic/SdlSprite.hpp"
#include "../graphic/SdlModel.hpp"
#include "SdlCamera.hpp"


#include <iostream>

class SdlWindow : public graphic3::IWindow {

    public:
        SdlWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
            std::cout << "SdlWindow::SdlWindow implemented" << std::endl;
            is_open = false;
            if(!(SDL_Init(SDL_INIT_VIDEO) < 0)) {
                std::cout << "SDL_Init success1" << std::endl;
                _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
                if (_window) {
                    std::cout << "SDL_Init success2" << std::endl;
                    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
                    //_surface = SDL_GetWindowSurface(_window);
                    if(_renderer) {
                        std::cout << "SDL_Init success3" << std::endl;
                        is_open = true;
                    }
                }
            }
        };

        ~SdlWindow() {
            std::cout << "SdlWindow::~SdlWindow implemented" << std::endl;
            //SDL_FreeSurface(_surface);
            SDL_DestroyRenderer(_renderer);
            SDL_DestroyWindow(_window);
        }

        //GLOBAL
        bool isOpen() override {
            return is_open;
        };

        void close() override {
            SDL_Quit();
        };

        //DRAW
        void beginDraw() override {
            std::cout << "SdlWindow::beginDraw not implemented" << std::endl;
            //BeginDrawing();
            //ClearBackground(BLACK);
        };

        void drawPoly(graphic3::IPolygon *polygon) override;
        void drawSprite(graphic3::ISprite *sprite) override;

        void endDraw() override {
            //std::cout << "SdlWindow::endDraw not implemented" << std::endl;
           SDL_RenderPresent(_renderer);

            //EndDrawing();
        };

        //Draw3 (Carve)
        void beginMode3(graphic3::ICamera *camera) override;
        
        virtual void drawModel(graphic3::IModel *model) override;

        void endMode3() override {
            std::cout << "SdlWindow::endMode3 not implemented" << std::endl;
            //EndMode3D();
        };

        //EVENT
        bool isPoll() override {
            return true;
        }

        bool pollEvent() override {
            return SDL_PollEvent(&event) > 0;
        }

        void eventClose() override {
            std::cout << "SdlWindow::eventClose implemented" << std::endl;
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
                is_open = false;
            }
        };

    private:
        bool is_open;
        SDL_Window   *_window;
        //SDL_Surface *_surface;
        SDL_Renderer *_renderer;

        SDL_Event event;
};

void SdlWindow::drawPoly(graphic3::IPolygon *polygon) {
    std::cout << "SdlWindow::drawPoly not implemented" << std::endl;
//    SdlPolygon *rayPolygon = static_cast<SdlPolygon *>(polygon);
//    std::vector<graphic3::triangle_t> triangles = rayPolygon->_triangles;
//
//    std::cout << "StartDraw" << std::endl;
//    for (int i = 0; i < triangles.size(); i++) {
//        //raylib ask for counter clockwise it's why I reverse the order
//        DrawTriangle({static_cast<float>(triangles[i].C.x), static_cast<float>(triangles[i].C.y)},
//                    {static_cast<float>(triangles[i].B.x), static_cast<float>(triangles[i].B.y)},
//                    {static_cast<float>(triangles[i].A.x), static_cast<float>(triangles[i].A.y)},
//                    Color{static_cast<unsigned char>(rand()%255), 0, 0, 255});
//    }
//    std::cout << "EndDraw" << std::endl;
};

void SdlWindow::drawSprite(graphic3::ISprite *sprite) {
    std::cout << "SdlWindow::drawSprite implemented" << std::endl;
    SdlSprite *sdlSprite = static_cast<SdlSprite *>(sprite);
    if (sdlSprite->_texture == nullptr && sdlSprite->_surface != nullptr) {
        sdlSprite->_texture = SDL_CreateTextureFromSurface(_renderer, sdlSprite->_surface);

        if (sdlSprite->_surface != nullptr)
            SDL_FreeSurface(sdlSprite->_surface);
    }
    SDL_Rect rect = {0, 0, sdlSprite->_surface->w, sdlSprite->_surface->h};
//    SDL_RenderCopy(_renderer, sdlSprite->_texture, &rect, &rect);
    SDL_RenderCopy(_renderer, sdlSprite->_texture, NULL, NULL);
};

void SdlWindow::beginMode3(graphic3::ICamera *camera) {
    std::cout << "SdlWindow::beginMode3 not implemented" << std::endl;

//    RayCamera *raycamera = static_cast<RayCamera *>(camera);
//
//    BeginMode3D(raycamera->_camera);
};

void SdlWindow::drawModel(graphic3::IModel *model) {
    std::cout << "SdlWindow::drawModel not implemented" << std::endl;
//    RayModel *raymodel = static_cast<RayModel *>(model);
//
//    DrawCubeV(raymodel->_position, raymodel->_scale, RED);
//    DrawCubeWiresV(raymodel->_position, raymodel->_scale, BLACK);
//    //DrawModel(raymodel->);
};

#endif /* !SDLWINDOW_HPP_ */