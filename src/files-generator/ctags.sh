# remove previous ctags or exuberant-ctags
sudo apt remove ctags -y
sudo apt remove exuberant-ctags -y
# install requirements
sudo apt install autoconf -y
sudo apt install pkg-config -y
# download, extract and install the specify version of ctags
wget https://www.dropbox.com/s/zhjp8078n5dp9lq/ctags-openmpinfo.tar.gz?dl=1 -O ctags-openmpinfo.tar.gz
tar -xzf ctags-openmpinfo.tar.gz
cd ctags-openmpinfo/
./autogen.sh
./configure
make
sudo make install -B
# delete files downloadeds
cd ..
rm -rf ctags-openmpinfo/ ctags-openmpinfo.tar.gz