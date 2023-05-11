# libprom
cd /home/ayrdim/Documents/workspace/c/prometheus-client-c/prom
cmake .
make
sudo mv libprom.so /usr/lib

# libpromhttp
cd /home/ayrdim/Documents/workspace/c/prometheus-client-c/promhttp
cmake .
make
sudo mv libpromhttp.so /usr/lib