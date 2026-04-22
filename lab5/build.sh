echo ""
echo "Deleting build repository"
rm -rf build
echo "Deleted"
echo ""
echo "Building project"
mkdir build && cd build
cmake -DCMAKE_CXX_COMPILER=clang++ ..
make
echo "Build Successfully"
cd ..