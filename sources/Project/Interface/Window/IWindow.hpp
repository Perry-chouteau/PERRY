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

#ifndef IWINDOW_HPP_
    #define IWINDOW_HPP_
    #include "../Graphics/IModel2.hpp"
    #include "../Graphics/IModel3.hpp"
    #include "../Graphics/ICamera.hpp"

//class IModel2;

class IWindow {

    public:
        virtual ~IWindow() = default;
        //global
        virtual bool isOpen() = 0;
        virtual void close() = 0;
        //draw
        virtual void beginDraw() = 0;
        virtual void draw2(IModel2 *model) = 0;
        virtual void endDraw() = 0;

        virtual void beginMode3(ICamera *camera) = 0;
        virtual void draw3(IModel3 *model) = 0;
        virtual void endMode3() = 0;
        //event
        virtual bool isPoll() = 0;
        virtual bool pollEvent() = 0;
        virtual void eventClose() = 0;

    private:
        //your variables here
};

#endif /* !IWINDOW_HPP_ */