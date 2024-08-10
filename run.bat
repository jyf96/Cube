cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build
cmake --install build --config Debug
cd bin
cube.exe