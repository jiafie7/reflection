#include "reflect/class_factory.h"

        
void Object::set_class_name(const std::string& class_name)
{
  m_class_name = class_name;
}

const std::string& Object::get_class_name() const
{
  return m_class_name;
}

       
void ClassFactory::register_class(const std::string& class_name, create_object func)
{
  m_class[class_name] = func;
}

Object* ClassFactory::create_class(const std::string& class_name)
{
  auto it = m_class.find(class_name);
  if (it == m_class.end())
    return nullptr;
  return it->second();
}


