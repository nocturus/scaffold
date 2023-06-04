#include "./files.hpp"

namespace gui {
    void setup_cpp(std::string f){
        file::create_folder(f);
        file::create_folder(f + "/include/");
        file::create_folder(f + "/src/");

        file::create_file(f + "/Makefile");
        file::create_file(f + "/src/main.cpp");

        file::create_folder(f + "/target/");

        file::add_text_to_file(f + "/src/main.cpp", R"(
#include <iostream>

int main(){
  std::cout << "Hello, World!" << std::endl;
})");

        file::add_text_to_file(f + "/Makefile", R"(
all:
  g++ src/main.cpp -o ./target/out
  ./target/out
        )");

        file::add_text_to_file(f + "/include/main.hpp","#pragma once");

        file::setup_git(f);
    }
}
