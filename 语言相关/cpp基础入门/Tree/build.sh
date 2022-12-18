#!/usr/bin/bash

clang++ inorder-tree.cpp \
    preorder-tree.cpp \
    binary-search-tree.cpp \
    postorder-tree.cpp \
    findMinandMax.cpp \
    check-valid-BST.cpp \
    delete-node-from-BST.cpp \
    -g \
    -o testTree \
    -std=c++17