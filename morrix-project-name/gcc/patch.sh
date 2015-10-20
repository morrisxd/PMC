sudo apt-get update
sudo apt-get install -y autoconf
sudo apt-get install -y libc6_dev
sudo apt-get install -y g++-multilib
sudo apt-get install -y libc6-dev-i386
sudo cp /usr/include/i386-linux-gnu/gnu/* /usr/include/gnu
# http://stackoverflow.com/questions/7412548/error-gnu-stubs-32-h-no-such-file-or-directory-while-compiling-nachos-source
# uname -m -p -i
ls /usr/include/gnu
