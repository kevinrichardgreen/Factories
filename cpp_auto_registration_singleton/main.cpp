
#include <iostream>

#include "Base.hpp"
#include "Derived1.hpp"
#include "OneArg1.hpp"

int main(int argc, char* argv[])
{

  std::cout << "###\n# Registered Base implementations: \n#  ";
  for (auto it : NoArgBaseFactory::registered_keys() ) {
    std::cout << it << "\n#  ";
  }
  std::cout << "\n";

  try {
    std::unique_ptr<Base> test = NoArgBaseFactory::Create("Derived1");
    std::cout << "Initialized var: " << test->variable << "\n";
  } catch (char const * s) {
    std::cout << "Exception thrown in NoArg behaviour!\n";
  }

  std::cout << "###\n# Registered Base classes with double ctor: \n#  ";
  for (auto it : OneDoubleArgBaseFactory::registered_keys() ) {
    std::cout << it << "\n#  ";
  }
  std::cout << "\n";

  try {
    std::unique_ptr<Base> test = OneDoubleArgBaseFactory::Create("OneArg1",5.3);
    std::cout << "Initialized var: " << test->variable << "\n";
  } catch (char const * s) {
    std::cout << "Exception thrown in OneArg behaviour!\n";
  }


  return 0;
}
