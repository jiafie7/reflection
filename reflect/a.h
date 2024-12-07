#pragma once

#include <iostream>
#include "reflect/class_register.h"

using namespace melon::reflect;

namespace melon
{
  namespace reflect
  {
    class A : public Object
    {
      public:
        A() = default;
        ~A() = default;

        void hello()
        {
          std::cout << "Hello, A!" << '\n';
        }
    };

    REGISTER_CLASS(A);
  }
}
