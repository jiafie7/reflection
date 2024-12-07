#include <iostream>

#include "reflect/a.h"
#include "reflect/class_register.h"

using namespace melon::reflect;
using namespace melon::utility;

int main()
{
  ClassFactory* factory = Singleton<ClassFactory>::get_instance();
  Object* a = factory->create_class("A");

  return 0;
}
