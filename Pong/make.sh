# !/bin/bash

#remove old files
echo "Log: Removing old files"
if [[ -f "bin/main" ]]; then
    rm bin/main
fi

#compile main
echo "Log: Compiling main file"
if [[ -f "src/main.cpp" ]]; then
    g++ -c src/main.cpp
else
    echo "Error: main.cpp not found"
    exit 1
fi

#link files
echo "Log: Linking sfml to output file"
if [[ -f "main.o" ]]; then
    g++ main.o -o bin/main -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
else
    echo "Error: Output file doesn't exist"
    exit 1
fi

#run
if [[ -f "bin/main" ]]; then
    echo "Log: Running"
    ./bin/main
else
    echo "Error: Binary file doesn't exist"
    exit 1
fi

echo "Finished"
exit 0
