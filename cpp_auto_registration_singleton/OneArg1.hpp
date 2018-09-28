
#pragma once

#include "Factory.hpp"
#include "Base.hpp"

class OneArg1 : public Base
{
REGISTER_BASE_1double_HPP(OneArg1);
public:
  OneArg1(double in);
};
