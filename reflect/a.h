#pragma once

#include <iostream>
#include <string>
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

      public:
        std::string m_name;
        int m_age;
    };

    REGISTER_CLASS(A);
    REGISTER_CLASS_FIELD(A, m_name, std::string);
    REGISTER_CLASS_FIELD(A, m_age, int);
  }
}
