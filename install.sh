root=$PWD

# libprom
cd $root/prom
cmake .
make
sudo cp libprom.so /usr/lib

# libpromhttp
cd $root/promhttp
cmake .
make
sudo cp libpromhttp.so /usr/lib