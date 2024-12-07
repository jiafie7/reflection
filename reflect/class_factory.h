#pragma once

#include <string>
#include <map>

#include "utility/singleton.h"

using namespace melon::utility;

namespace melon
{
  namespace reflect
  {
    class Object
    {
      public:
        Object() = default;
        virtual ~Object() = default;

        void set_class_name(const std::string& class_name);
        const std::string& get_class_name() const;

      private:
        std::string m_class_name;
    };

    typedef Object* (*create_object)();

    class ClassFactory
    {
      SINGLETON(ClassFactory);
      public:
        void register_class(const std::string& class_name, create_object func);
        Object* create_class(const std::string& class_name);

      private:
        std::map<std::string, create_object> m_class;
    };
  }
}
