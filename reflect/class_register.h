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

        ClassRegister(const std::string& class_name, const std::string& field_name, const std::string& field_type, size_t offset)
        {
          Singleton<ClassFactory>::get_instance()->register_class_field(class_name, field_name, field_type, offset);
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


#define REGISTER_CLASS_FIELD(className, fieldName, fieldType) \
    className className##fieldName;                           \
    ClassRegister ClassRegister##className##fieldName(#className, #fieldName, #fieldType, (size_t)(&(className##fieldName.fieldName)) - (size_t)(&(className##fieldName)))
  }
}
