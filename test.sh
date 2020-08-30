#!/bin/bash
set -euo pipefail
shopt -s globstar

echo "Formatting"

diff -u <(cat **/*.{cpp,hpp,ino}) <(clang-format -style=Google **/*.{cpp,hpp,ino})

echo "Linting"
. .venv/bin/activate
python -m cpplint --filter=-legal/copyright wecker.cpp src/**/*pp

echo "Compiling for PC
make clean
make pc
echo "Success"

echo "Compiling for Arduino"
make clean
make ino
echo "Success"
