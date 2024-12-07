#include <iostream>

#include "reflect/a.h"
#include "reflect/class_register.h"

using namespace melon::reflect;
using namespace melon::utility;

int main()
{
  ClassFactory* factory = Singleton<ClassFactory>::get_instance();
  Object* a = factory->create_class("A");

  a->set_field_value<std::string>("m_name", "Michael");
  a->set_field_value<int>("m_age", 21);
  std::string name;
  int age;
  a->get_field_value<std::string>("m_name", name);
  a->get_field_value<int>("m_age", age);
  std::cout << "name = " << name << ", age = " << age << '\n';

  a->call("hello");
  const std::string& Name = "Jenny";
  int Age = 17;
  a->call("get_info", Name, Age);

  return 0;
}
