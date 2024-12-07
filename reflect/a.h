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

        int get_info(const std::string& name, int age)
        {
          std::cout << "Info: name = " << name << ", age = " << age << '\n';
          return 0;
        }

      public:
        std::string m_name;
        int m_age;
    };

    REGISTER_CLASS(A);

    REGISTER_CLASS_FIELD(A, m_name, std::string);
    REGISTER_CLASS_FIELD(A, m_age, int);

    REGISTER_CLASS_METHOD(A, hello, void);
    REGISTER_CLASS_METHOD(A, get_info, int, const std::string&, int);
  }
}
