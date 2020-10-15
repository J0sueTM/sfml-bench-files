# !/bin/sh
# by J0sueTM

# clear cli
clear

# removing
if [[ -f "main.o" ]] && [[ -f "bin/main" ]]; then
    echo "[LOG]: Removing deprecated files"
    rm main.o
    rm bin/main
fi

# compiling
if [[ -f "src/main.cpp" ]]; then
    echo "[LOG]: Compiling"
    g++ -c src/main.cpp
else
    echo "[ERROR]: src/main.cpp file was not found."
    exit 1
fi

# linking
if [[ -f "main.o" ]]; then
    echo "[LOG]: Linking"
    g++ main.o -o bin/main src/Engine/*/*.cpp -lsfml-graphics -lsfml-window -lsfml-system
else
    echo "[ERROR]: main.o or header files were not found."
    exit 1
fi

# running
if [[ -f "bin/main" ]]; then
    echo "[LOG]: Running"
    ./bin/main
else
    echo "[ERROR]: bin/main binary file was not found."
    exit 1
fi

echo "[LOG]: Finished"
exit 0
