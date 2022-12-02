cmake_minimum_required(VERSION 3.12.0)

set(SOURCE
    inorder-tree.cpp    
    preorder-tree.cpp 
    bianry-search-tree.cpp
)

add_executable(
    testTree
    ${SOURCE}
)