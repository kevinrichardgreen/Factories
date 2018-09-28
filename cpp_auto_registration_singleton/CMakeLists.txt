PROJECT(FactoryTest CXX)

# Note the global registry can be optimized away if a library is
# linked that does not use it.

add_executable(registered_factory_test
  main.cpp
  Base.cpp
  Derived1.cpp
  Derived2.cpp
  OneArg1.cpp
)
