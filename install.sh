cd $(dirname "$0")
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

sudo cp -r $root/prom/include /usr/include/prom
sudo cp $root/promhttp/include/promhttp.h /usr/include/prom