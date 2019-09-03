cmake_minimum_required(VERSION 3.14)
project(BST_draft C)

set(CMAKE_C_STANDARD 11)

add_executable(BST_draft main.c BST_header.h BST_source.c)