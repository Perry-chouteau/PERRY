#include <iostream>
#include <ostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
//libraries
#include "libraries/system/std.hpp"
#include "libraries/finder/FileSearcher.hpp"

//interface 
#include "interfaces/InfoSharedLoader.hpp"
 
//  graphic
#include "interfaces/graphic/GraphicSharedLoader.hpp"
#include "interfaces/serial/SerialSharedLoader.hpp"

//ecs
#include "modules/core/ecs/Ecs.hpp"
#include "includes/Component.hpp"
#include "includes/Systems.hpp"

class Game: public CustomisableEngine<GraphicSharedLoader> {
    public:
        //todo change vector to variadic template
        Game(std::string graphic): CustomisableEngine(graphic) {};
        ~Game() = default;

        int start() override {
            // main loop
            this->initHandler();
            while (window->isOpen()) {
                while (window->pollEvent()) {
                    window->eventClose();
                    this->eventHandler();
                }
                this->updateHandler();
                window->beginDraw();
                this->displayHandler();
                window->endDraw();
            }
            window->close();

            this->destroyHandler();
            return 0;
        }

    protected:
        void initHandler() override {
            std::cout << "initHandler " << std::endl;
            window = createWindow(800, 500, "Perry");
            event = createEvent();
            window->linkEvent(event);
            std::vector<__v2f_t> star_points = {{125, 200}, {175, 200}, {200, 150}, {225, 200}, {275, 200},  {250, 250}, {255, 305}, {200, 285}, {145, 305}, {150, 250}};
            std::vector<__v2f_t> heart_points = {{500, 100}, {600, 100}, {600, 200}, {700, 200}, {700, 300},  {500, 300}};
            poly_star = createPolygon(star_points);
            poly_heart = createPolygon(heart_points);
            sprite = createSprite("./assets/image.png");
            camera = createCamera();
            model = createModel();
            keyboard = createKeyboard(event);
            mouse = createMouse(event);
            window->setFrameLimit(120);
        }

        void eventHandler() override {
            if (keyboard != nullptr) {
                if (keyboard->isKeyDown(graphic::IKeyboard::Keys::KEY_SPACE)) {
                    std::cout << "SPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACESPACE" << std::endl;
                    __v2f_t pos = sprite->getPosition();
                    sprite->setPosition({pos.x + 1, pos.y});
                    sprite->setRotation(sprite->getRotation() + 1);
                }
            } else {
                std::cout << "isNULL" << std::endl;
            }
            //std::cout << "eventHandler " << std::endl;
        }

        void updateHandler() override {
            std::cout << window->getDelta() << std::endl;
            //std::cout << "updateHandler " << std::endl;
        }

        void displayHandler() override {
            std::cout << "displayHandler" << std::endl;
            window->drawSprite(sprite);

            window->drawPoly(poly_star);
            window->drawPoly(poly_heart);
            window->beginMode3(camera);
            window->drawModel(model);
            window->endMode3();
        }

        void destroyHandler() override {
            deleteWindow(window);
            deleteEvent(event);
            deletePolygon(poly_star);
            deletePolygon(poly_heart);
            deleteSprite(sprite);
            deleteCamera(camera);
            deleteModel(model);
            deleteKeyboard(keyboard);
            deleteMouse(mouse);
        }

    public:
        graphic::IWindow *window;
        graphic::IEvent *event;
        graphic::IPolygon *poly_star;
        graphic::IPolygon *poly_heart;
        graphic::ISprite *sprite;
        graphic::ICamera *camera;
        graphic::IModel *model;
        //event
        graphic::IKeyboard *keyboard;
        graphic::IMouse *mouse;

};

std::map<std::string, std::vector<std::string>> sortSharedLibrary(std::vector<std::string> files) {
    std::map<std::string, std::vector<std::string>> map;
    for (auto& file: files) {
        std::cout << file << std::endl;
        InfoSharedLoader info_shared(file);
        if (!info_shared.getType()) {
            continue;
        }
        std::cout << info_shared.getType() << std::endl;
        map[info_shared.getType()].push_back(file);
    }
    return map;
}

int main() {
    std::vector<std::string> files = FileSearcher::searchSharedLibraries("./shared");
    std::cout << "Shared Libraries:" << std::endl;
    std::map<std::string, std::vector<std::string>> map = sortSharedLibrary(files);

    for (auto& [key, value]: map) {
        std::cout << key << std::endl;
        for (auto& file: value) {
            std::cout << "\t" << file << std::endl;
        }
    }

    Registry r;
    Math m = Math();

    r.registerComponentsByExtraction<config::components>();
    auto e = r.createEntity();

    e.addComponent<Position>({0.0f, 0.0f});
    e.addComponent<Velocity>({1.0f, 2.0f});

    r.addSystem<MovementSystem>("Move");
    r.addSystem<DisplaySystem>(m);

    std::cout << "----------------" << std::endl;
    r.callSystem<DisplaySystem>();
    r.callSystem<MovementSystem>();
    r.callSystem<DisplaySystem>();
    std::cout << "----------------" << std::endl;

    return 0;

    for (int i = 0; i < 3; ++i) {
        Game game(map["graphic"][i]);
        game.start();
    }

    return 0;
}