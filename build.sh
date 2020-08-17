
#1. install deps
# gn
# binutils
# pkg-config
# clang10, llvm10
# lld
# python27


#2. get depth tools
git submodule update --init


#3. add soft link
root=$(git rev-parse --show-toplevel)
cd $root/src/third_party/llvm-build/Release+Asserts/bin
sudo ln -s  $(which llvm-ar) llvm-ar
sudo ln -s  $(which clang++) clang++
sudo ln -s  $(which clang) clang

#4. build
cd $root/src
gn gen out/Default --args="is_component_build=true is_debug=true target_cpu=\"x64\""
ninja -C out/Default
