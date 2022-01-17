package=bdb
$(package)_version=6.2.32
$(package)_download_path=https://download.oracle.com/berkeley-db
$(package)_file_name=db-$($(package)_version).tar.gz
$(package)_sha256_hash=a9c5e2b004a5777aa03510cfe5cd766a4a3b777713406b02809c17c8e0e7a8fb
$(package)_build_subdir=build_unix

define $(package)_set_vars
$(package)_config_opts=--disable-shared --enable-cxx --disable-replication --enable-option-checking
$(package)_config_opts_mingw32=--enable-mingw
$(package)_config_opts_linux=--with-pic
$(package)_config_opts_android=--with-pic
$(package)_cflags+=-Wno-error=implicit-function-declaration
$(package)_cxxflags+=-std=c++17
$(package)_cppflags_mingw32=-DUNICODE -D_UNICODE
endef

define $(package)_preprocess_cmds
  cp -f $(BASEDIR)/config.guess $(BASEDIR)/config.sub dist && \
  sed -i.old 's/WinIoCtl.h/winioctl.h/' src/dbinc/win_db.h
endef

define $(package)_config_cmds
  ../dist/$($(package)_autoconf)
endef

define $(package)_build_cmds
  $(MAKE) libdb_cxx-6.2.a libdb-6.2.a
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install_lib install_include
endef
