#pragma once

#include <string>
#include <map>

#include "reflect/class_field.h"
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

        int get_field_count();
        ClassField* get_field(int index);
        ClassField* get_field(const std::string& field_name);

        template <typename T>
        void get_field_value(const std::string& field_name, T& value);

        template <typename T>
        void set_field_value(const std::string& field_name, const T& value);

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

        void register_class_field(const std::string& class_name, const std::string& field_name, const std::string& field_type, size_t offset);
        int get_class_field_count(const std::string& class_name);
        ClassField* get_class_field(const std::string& class_name, int index);
        ClassField* get_class_field(const std::string& class_name, const std::string& field_name);

      private:
        std::map<std::string, create_object> m_class;
        std::map<std::string, std::vector<ClassField*>> m_class_fields;
    };

    template <typename T>
    void Object::get_field_value(const std::string& field_name, T& value)
    {
      ClassField* field = Singleton<ClassFactory>::get_instance()->get_class_field(m_class_name, field_name);
      if (field == nullptr)
        return;

      size_t offset = field->get_offset();
      value = *((T*)((unsigned char*)(this) + offset));
    }

    template <typename T>
    void Object::set_field_value(const std::string& field_name, const T& value)
    {
      ClassField* field = Singleton<ClassFactory>::get_instance()->get_class_field(m_class_name, field_name);
      if (field == nullptr)
        return;

      size_t offset = field->get_offset();
      *((T*)((unsigned char*)(this) + offset)) = value;
    }
  }
}
