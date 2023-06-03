#include <iostream>
#pragma once

namespace util {
  template <class T> void print(T a){
    std::cout << a;
  }

  template <class T> void println(T a){
    std::cout << a << std::endl;
  }
}