# Reflection

This C++ Reflection Library provides an easy-to-use framework for introspection and manipulation of class objects, fields, and methods at runtime. Using this library, you can dynamically create objects, access or modify fields, and invoke member functions of a class without knowing their details at compile time.

## Features

1. **Object Introspection and Manipulation**
   - Dynamically create objects of registered classes.
   - Access and modify class member variables by name.
   - Invoke class methods by name.
2. **Automatic Registration**
   - Macros simplify the process of registering classes, fields, and methods with the reflection system.
3. **Comprehensive API**
   - Access class metadata, such as fields and methods.
   - Use templates for generic and type-safe manipulation.

## Getting Started

1. Prerequisites

   - C++ 11 or later

2. Clone the Repository

```bash
git clone https://github.com/jiafie7/reflection.git
cd reflection
```

3. Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

1. Example code

```c
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
```

2. Run the Example

```bash
./main
```

3. Output

```bash
A
name = Michael, age = 21
Hello, A!
Info: name = Jenny, age = 17
```

## API Reference

### Object Class

The base class for all reflectable objects:

- `void set_class_name(const std::string& class_name)`: Sets the object’s class name.
- `const std::string& get_class_name() const`: Gets the object’s class name.
- `int get_field_count()`: Returns the number of fields in the class.
- `ClassField* get_field(int index)`: Retrieves field metadata by index.
- `ClassField* get_field(const std::string& field_name)`: Retrieves field metadata by name.
- `template <typename T> void get_field_value(const std::string& field_name, T& value)`: Gets the value of a field.
- `template <typename T> void set_field_value(const std::string& field_name, const T& value)`: Sets the value of a field.
- `template <typename R = void, typename... Args> R call(const std::string& method_name, Args&&... args)`: Invokes a method by name.

### ClassFactory Singleton

Manages registration, object creation, and metadata:

- `void register_class(const std::string& class_name, create_object func)`: Registers a class with its factory method.
- `Object* create_class(const std::string& class_name)`: Creates an object of the given class.
- `void register_class_field(...)`: Registers a class field with its metadata.
- `void register_class_method(...)`: Registers a class method.
- `ClassField* get_class_field(...)`: Retrieves metadata of a class field.
- `ClassMethod* get_class_method(...)`: Retrieves metadata of a class method.

### Macros

- `#define REGISTER_CLASS(className)`: Registers a class with the reflection system.
- `#define REGISTER_CLASS_FIELD(className, fieldName, fieldType)`: Registers a field of a class.
- `#define REGISTER_CLASS_METHOD(className, methodName, returnType, ...)`: Registers a method of a class.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

## Contributions

Contributions, bug reports, and feature requests are welcome! Fork the repository and create a pull request.
