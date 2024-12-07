#pragma once

#include "reflect/class_factory.h"

using namespace melon::reflect;

namespace melon
{
  namespace reflect
  {
    class ClassRegister
    {
      public:
        ClassRegister(const std::string& class_name, create_object func)
        {
          Singleton<ClassFactory>::get_instance()->register_class(class_name, func);
        }

    };

#define REGISTER_CLASS(className)                                               \
    Object* createObject##className()                                           \
    {                                                                           \
      Object* obj = new className();                                            \
      obj->set_class_name(#className);                                          \
      return obj;                                                               \
    }                                                                           \
    ClassRegister ClassRegister##className(#className, createObject##className)
  }
}
