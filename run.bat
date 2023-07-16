cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
cmake --install build
cd bin
cube.exe