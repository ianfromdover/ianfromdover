#!/usr/bin/env bash
# Authors: Sharadh <github username>, Ian Hong <github.com/ianfromdover>
# Compiles a single openGL C++ file and creates an executable, for Mac

# How to Use
# in your terminal, type the following:
# ./opengl_compile.sh <simple.cpp>
# with the name of your script replacing 'simple.cpp'

# To make a shortcut to compile, you can create an alias like 'glc' GL Compiler and place this file in your home directory. Then the alias can expand to "~/opengl_compile.sh"

file=$1;

clang++ --std=c++17 -g -O3 -framework OpenGL -framework GLUT -DGL_SILENCE_DEPRECATION $file -o "${file%.*}" && ./"${file%.*}";
