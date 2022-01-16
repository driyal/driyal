DRiyal Core integration/staging tree
=====================================

https://bitcointalk.org/index.php?topic=5377330.0

Building on Linux:
```
git clone https://github.com/driyal/driyal
cd driyal/depends/
make
cd ..
./autogen.sh
CONFIG_SITE=$PWD/depends/x86_64-pc-linux-gnu/share/config.site ./configure --with-incompatible-bdb
make
```
