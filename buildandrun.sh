rm -rd build/$1/$2
mkdir -p build/$1
gcc $1/$2.c -o build/$1/$2
./build/$1/$2