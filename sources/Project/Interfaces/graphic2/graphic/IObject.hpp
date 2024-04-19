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


#ifndef IOBJECT_HPP_
    #define IOBJECT_HPP_

    #include "../../system/Type.hpp"
    #include "../Window/IWindow.hpp"

namespace graphic2 {

    class IObject {

        public:
            //constructor
            virtual ~IObject() = default;
            //p
            virtual __v3f_t getPosition() const = 0;
            virtual void setPosition(__v3f_t position) = 0;

        private:
            //your variables here
    };

} // namespace graphic2

#endif /* !IMODEL2_HPP_ */