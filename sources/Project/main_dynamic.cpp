/**
 *
 * File: main.cpp (header.v2)
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

//Interface
#include "Interfaces/graphic3/window/IWindow.hpp"
#include "Interfaces/graphic3/graphic/IPolygon.hpp"
//EngineCore
#include "Libraries/DynamicSwitchCore/DynamicSwitchCore.hpp"

#include <dlfcn.h>
#include <map>
#include <iostream>
#include <utility>
#include <filesystem>
#include <sys/stat.h>
#include <filesystem>

class FirstGameCore: public DynamicSwitchLibCore/*NoEngineCore*/ {
    public:
        FirstGameCore(std::vector<std::string> files): DynamicSwitchLibCore(files) {}
    protected:

        void initHandler() override {
            std::cout << "initHandler " << std::endl;
            std::vector<__v2f_t> star_points = {{125, 200}, {175, 200}, {200, 150}, {225, 200}, {275, 200},  {250, 250}, {255, 305}, {200, 285}, {145, 305}, {150, 250}};
            std::vector<__v2f_t> heart_points = {{500, 100}, {600, 100}, {600, 200}, {700, 200}, {700, 300},  {500, 300}};
            poly_star = createPolygon(star_points);
            poly_heart = createPolygon(heart_points);
            sprite = createSprite("./Assets/image.png");
            camera = createCamera();
            model = createModel();
        }

        void eventHandler() override {
            //std::cout << "eventHandler " << std::endl;
        }

        void updateHandler() override {
            //std::cout << "updateHandler " << std::endl;
        }

        void displayHandler() override {
            std::cout << "displayHandler" << std::endl;
            window->drawSprite(sprite);

            window->beginMode3(camera);
                window->drawModel(model);
            window->endMode3();
            window->drawPoly(poly_star);
            window->drawPoly(poly_heart);
        }

    private:
        graphic3::IPolygon *poly_star;
        graphic3::IPolygon *poly_heart;
        graphic3::ISprite *sprite;
        graphic3::ICamera *camera;
        graphic3::IModel *model;
};

#include "Libraries/FlagParser.hpp"
#include "Libraries/FileSearcher.hpp"

int main(int ac, char **av) {
    std::vector<std::string> files = FileSearcher::searchSharedLibraries("./Shared");
    FirstGameCore fgc(files);

    std::cout << "--------------------" << std::endl;
    for(auto& file: files)
        std::cout << file << std::endl;
    std::cout << "--------------------" << std::endl;
    return fgc.Run();
}