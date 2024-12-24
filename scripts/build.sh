if [ x"$#" == x"--debug" ];then
    mode='Debug'
    echo '>>> In Debug Mode...'
else
    mode='Release'
fi

mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=${mode} .. && make -j
