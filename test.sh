#!/bin/bash
set -euo pipefail

. .venv/bin/activate
python -m cpplint --filter=-legal/copyright wecker.cpp {pc,src}/**/*pp

echo "Compiling for PC..."
make clean
make pc
echo "Success"

echo "Compiling for Arduino"
make clean
make ino
echo "Success"
