#!/usr/bin/env bash
# Authors: Sharadh <github username>
# For MacOS.

# Compiles all openGL C++ files in the directory and creates an executables for them.

# How to Use
# in your terminal, type the following:
# ./opengl_compile_all.sh

# To make a shortcut to compile, you can create an alias like 'glca' and place this file in your home directory. Then the alias can expand to "~/opengl_compile_all.sh"

for file in *.cpp; do clang++ --std=c++17 -g -O3 -framework OpenGL -framework GLUT -DGL_SILENCE_DEPRECATION $file -o "${file%.*}" && ./"${file%.*}"; done
