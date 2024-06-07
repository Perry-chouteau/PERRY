/**
 *
 * File: raylib.cpp (header.v2)
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

#ifndef RAYLIB_CPP_
#define RAYLIB_CPP_

//Raylib
#include "window/RayWindow.hpp"
#include "graphic/RayPolygon.hpp"
#include "graphic/RayModel.hpp"
#include "window/RayCamera.hpp"
#include "event/RayKeyboard.hpp"
#include "event/RayMouse.hpp"
#include "event/RayEvent.hpp"

///Windowing
extern "C" graphic::IWindow *createWindow(__int32_t screenWidth, __int32_t screenHeight, std::string title) {
    return new RayWindow(screenWidth, screenHeight, std::string("Raylib " + title));
}

extern "C" void deleteWindow(graphic::IWindow *window) {
    delete window;
}

extern "C" graphic::ICamera *createCamera(__v3f_t position) {
    return new RayCamera();
}

extern "C" void deleteCamera(graphic::ICamera *camera) {
    delete camera;
}

///Event
extern "C" graphic::IEvent *createEvent() {
    return new RayEvent();
}

extern "C" void deleteEvent(graphic::IEvent *event) {
    delete event;
}

extern "C" graphic::IKeyboard *createKeyboard(graphic::IEvent *event) {
    return new RayKeyboard(event);
}

extern "C" void deleteKeyboard(graphic::IKeyboard *keyboard) {
    delete keyboard;
}

extern "C" graphic::IMouse *createMouse(graphic::IEvent *event) {
    return new RayMouse(event);
}

extern "C" void deleteMouse(graphic::IMouse *mouse) {
    delete mouse;
}

///Graphics
extern "C" graphic::IPolygon *createPolygon(std::vector<__v2f_t> points) {
    return new RayPolygon(points);
}

extern "C" void deletePolygon(graphic::IPolygon *polygon) {
    delete polygon;
}

extern "C" graphic::ISprite *createSprite(std::string sprite) {
    return new RaySprite(sprite);
}

extern "C" void deleteSprite(graphic::ISprite *sprite) {
    delete sprite;
}

extern "C" graphic::IModel *createModel() {
    return new RayModel();
}

extern "C" void deleteModel(graphic::IModel *model) {
    delete model;
}

#endif /* !RAYLIB_CPP_ */