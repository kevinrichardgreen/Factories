
#pragma once

#include "Factory.hpp"


class Base
{
public:
  double variable;
  Base(double in = 0.0) : variable(in) {}
};



typedef Factory<Base> NoArgBaseFactory;
// Macros for easier registration of Implementations of Base
// No argument ctor Factory
#define REGISTER_BASE_HPP(Implementation) \
private: \
   static const Registrar<Base,Implementation> registrar;
#define STR_EXPAND(x) #x     // ensure x gets evaluated as a string,
#define STR(x) STR_EXPAND(x) // two-stage macro
#define REGISTER_BASE_CPP(Implementation) \
   const Registrar<Base,Implementation> Implementation::registrar(STR(Implementation));


typedef Factory<Base,double> OneDoubleArgBaseFactory;
// IMPLs with different ctor args (number and/or type) do require
// different factories, unfortunately
#define REGISTER_BASE_1double_HPP(Implementation) \
private: \
   static const Registrar<Base,Implementation,double> registrar;
#define REGISTER_BASE_1double_CPP(Implementation) \
   const Registrar<Base,Implementation,double> Implementation::registrar(STR(Implementation));
