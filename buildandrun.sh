rm -rf build/$1/$2/$3
mkdir -p build/$1/$2
gcc $1/$2/$3.c -o build/$1/$2/$3
./build/$1/$2/$3