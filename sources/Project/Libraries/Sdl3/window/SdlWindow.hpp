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
#include "../event/SdlEvent.hpp"
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
                    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
        //event
        void linkEvent(graphic3::IEvent *event) override {
            _event = static_cast<SdlEvent *>(event);
        };

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
            return SDL_PollEvent(&_event->_event) > 0;
        }

        void eventClose() override {
            if (_event->_event.type == SDL_QUIT || _event->_event.key.keysym.sym == SDLK_ESCAPE) {
                is_open = false;
            }
        };

    private:
        bool is_open;
        SDL_Window   *_window;
        //SDL_Surface *_surface;
        SDL_Renderer *_renderer;
        //IEvent *_event;
        SdlEvent *_event;
};

void SdlWindow::drawPoly(graphic3::IPolygon *polygon) {
    std::cout << "SdlWindow::drawPoly not implemented" << std::endl;
    SdlPolygon *sdlPolygon = static_cast<SdlPolygon *>(polygon);

    std::vector<graphic3::triangle_t> triangles = sdlPolygon->_triangles;
    std::vector<SDL_Vertex> points = sdlPolygon->_points;

    std::cout << "StartDraw" << std::endl;
    for (int i = 0; i < triangles.size(); i++) {
        //raylib ask for counter clockwise it's why I reverse the order
//        SDL_RenderGeometry(_renderer, nullptr, points.data(), points.size(), nullptr, 0);
        int rColor = rand()%255;
        std::vector<SDL_Vertex> vertices = {
            SDL_Vertex{SDL_FPoint{static_cast<float>(triangles[i].A.x), static_cast<float>(triangles[i].A.y)}, 
                        SDL_Color{static_cast<unsigned char>(rColor), 0, 0, 255}, SDL_FPoint{0, 0}},
            SDL_Vertex{SDL_FPoint{static_cast<float>(triangles[i].B.x), static_cast<float>(triangles[i].B.y)}, 
                        SDL_Color{static_cast<unsigned char>(rColor), 0, 0, 255}, SDL_FPoint{0, 0}},
            SDL_Vertex{SDL_FPoint{static_cast<float>(triangles[i].C.x), static_cast<float>(triangles[i].C.y)}, 
                        SDL_Color{static_cast<unsigned char>(rColor), 0, 0, 255}, SDL_FPoint{0, 0}},
        }; 
        SDL_RenderGeometry(_renderer, nullptr, vertices.data(), vertices.size(), nullptr, 0);
        //DrawTriangle({static_cast<float>(triangles[i].C.x), static_cast<float>(triangles[i].C.y)},
        //            {static_cast<float>(triangles[i].B.x), static_cast<float>(triangles[i].B.y)},
        //            {static_cast<float>(triangles[i].A.x), static_cast<float>(triangles[i].A.y)},
        //            Color{static_cast<unsigned char>(rand()%255), 0, 0, 255});
    }
    std::cout << "EndDraw" << std::endl;
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
    SDL_RenderCopy(_renderer, sdlSprite->_texture, NULL, NULL);
};

void SdlWindow::beginMode3(graphic3::ICamera *camera) {
    std::cout << "SdlWindow::beginMode3 not implemented" << std::endl;
};

void SdlWindow::drawModel(graphic3::IModel *model) {
    std::cout << "SdlWindow::drawModel not implemented" << std::endl;
};

#endif /* !SDLWINDOW_HPP_ */