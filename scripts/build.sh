if [ x"$1" = x"--debug" ];then
    mode='Debug'
    echo '>>> In Debug Mode...'
else
    mode='Release'
fi

TRADE_TYPE=1 # 0 for Spot, 1 for UM, 2 for CM
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=${mode} -DTRADE_TYPE=${TRADE_TYPE} .. && make -j
