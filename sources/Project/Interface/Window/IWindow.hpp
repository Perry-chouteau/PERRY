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

#ifndef IWindow_HPP_
#define IWindow_HPP_

class IWindow {

    public:
        ~IWindow() = default;
        //global
        virtual bool isOpen() = 0;
        virtual void close() = 0;
        //draw
        virtual void beginDraw() = 0;
        virtual void endDraw() = 0;
        //event
        virtual bool isPoll() = 0;
        virtual bool pollEvent() = 0;
        virtual void eventClose() = 0;

    private:
        //your variables here
};

#endif /* !IWindow_HPP_ */