sudo apt remove ctags -y
sudo apt remove exuberant-ctags -y
sudo apt install autoconf -y
sudo apt install pkg-config -y
wget https://www.dropbox.com/s/zhjp8078n5dp9lq/ctags-openmpinfo.tar.gz?dl=1 -O ctags-openmpinfo.tar.gz
tar -xzf ctags-openmpinfo.tar.gz
cd ctags-openmpinfo/
./autogen.sh
./configure
make
sudo make install -B
