
#include "Base.hpp"
#include <iostream>

void _lame(void)
{
  std::cout << "###\n# Registered Base implementations: \n#  ";
  for (auto it : NoArgBaseFactory::registered_keys() ) {
    std::cout << it << "\n#  ";
  }
  std::cout << "\n";
}


int  _base_dummy_noarg(std::string implName)
{
  std::unique_ptr<Base> _tmp = NoArgBaseFactory::Create(implName);
  if (_tmp == nullptr)
    return -1;
  return 0;
}

int  _base_dummy_1arg(std::string implName)
{
  std::unique_ptr<Base> _tmp = OneDoubleArgBaseFactory::Create(implName,0.0);
  if (_tmp == nullptr)
    return -1;
  return 0;
}
