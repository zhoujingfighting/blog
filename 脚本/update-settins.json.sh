#!/usr/bin/bash

# THis is for updating settings.json file for VScode project
ROOT_FOLDER="${1}"
# if specified VScode root folder,use this folder
if [ -f  ${ROOT_FOLDER}/.vscode/settings.json ]; then
    rm ${ROOT_FOLDER}/.vscode/settings.json
fi
# More further TODO: diff two different settings.json file and merge them into one file
wget -P "${ROOT_FOLDER}/.vscode"  https://raw.githubusercontent.com/zhoujingfighting/blog/d2bb6f52942f296b815e0345a314823a3581a12c/%E5%B7%A5%E5%85%B7%E7%9B%B8%E5%85%B3/settings.json 