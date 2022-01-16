# Copyright (c) 2013-2016 The DRiyal Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

# Pattern rule to print variables, e.g. make print-top_srcdir
print-%: FORCE
	@echo '$*'='$($*)'

DIST_SUBDIRS = secp256k1

AM_LDFLAGS = $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS) $(GPROF_LDFLAGS) $(SANITIZER_LDFLAGS) $(LTO_LDFLAGS)
AM_CXXFLAGS = $(DEBUG_CXXFLAGS) $(HARDENED_CXXFLAGS) $(WARN_CXXFLAGS) $(NOWARN_CXXFLAGS) $(ERROR_CXXFLAGS) $(GPROF_CXXFLAGS) $(SANITIZER_CXXFLAGS) $(LTO_CXXFLAGS)
AM_CPPFLAGS = $(DEBUG_CPPFLAGS) $(HARDENED_CPPFLAGS)
AM_LIBTOOLFLAGS = --preserve-dup-deps
PTHREAD_FLAGS = $(PTHREAD_CFLAGS) $(PTHREAD_LIBS)
EXTRA_LIBRARIES =

DRIYAL_INCLUDES=-I$(builddir) -I$(srcdir)/$(MINISKETCH_INCLUDE_DIR_INT) -I$(srcdir)/secp256k1/include -I$(srcdir)/$(UNIVALUE_INCLUDE_DIR_INT) $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS)

LIBDRIYAL_NODE=libdriyal_node.a
LIBDRIYAL_COMMON=libdriyal_common.a
LIBDRIYAL_CONSENSUS=libdriyal_consensus.a
LIBDRIYAL_CLI=libdriyal_cli.a
LIBDRIYAL_UTIL=libdriyal_util.a
LIBDRIYAL_CRYPTO_BASE=crypto/libdriyal_crypto_base.a
LIBDRIYALQT=qt/libdriyalqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

if ENABLE_ZMQ
LIBDRIYAL_ZMQ=libdriyal_zmq.a
endif
if BUILD_DRIYAL_LIBS
LIBDRIYALCONSENSUS=libdriyalconsensus.la
endif
if ENABLE_WALLET
LIBDRIYAL_WALLET=libdriyal_wallet.a
LIBDRIYAL_WALLET_TOOL=libdriyal_wallet_tool.a
endif

LIBDRIYAL_CRYPTO= $(LIBDRIYAL_CRYPTO_BASE)
if ENABLE_SSE41
LIBDRIYAL_CRYPTO_SSE41 = crypto/libdriyal_crypto_sse41.a
LIBDRIYAL_CRYPTO += $(LIBDRIYAL_CRYPTO_SSE41)
endif
if ENABLE_AVX2
LIBDRIYAL_CRYPTO_AVX2 = crypto/libdriyal_crypto_avx2.a
LIBDRIYAL_CRYPTO += $(LIBDRIYAL_CRYPTO_AVX2)
endif
if ENABLE_SHANI
LIBDRIYAL_CRYPTO_SHANI = crypto/libdriyal_crypto_shani.a
LIBDRIYAL_CRYPTO += $(LIBDRIYAL_CRYPTO_SHANI)
endif

$(LIBSECP256K1): $(wildcard secp256k1/src/*.h) $(wildcard secp256k1/src/*.c) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES += \
  $(LIBDRIYAL_CRYPTO) \
  $(LIBDRIYAL_UTIL) \
  $(LIBDRIYAL_COMMON) \
  $(LIBDRIYAL_CONSENSUS) \
  $(LIBDRIYAL_NODE) \
  $(LIBDRIYAL_CLI) \
  $(LIBDRIYAL_IPC) \
  $(LIBDRIYAL_WALLET) \
  $(LIBDRIYAL_WALLET_TOOL) \
  $(LIBDRIYAL_ZMQ)

lib_LTLIBRARIES = $(LIBDRIYALCONSENSUS)
noinst_LTLIBRARIES =

bin_PROGRAMS =
noinst_PROGRAMS =
TESTS =
BENCHMARKS =

if BUILD_DRIYALD
  bin_PROGRAMS += driyald
endif

if BUILD_DRIYAL_NODE
  bin_PROGRAMS += driyal-node
endif

if BUILD_DRIYAL_CLI
  bin_PROGRAMS += driyal-cli
endif

if BUILD_DRIYAL_TX
  bin_PROGRAMS += driyal-tx
endif

if ENABLE_WALLET
if BUILD_DRIYAL_WALLET
  bin_PROGRAMS += driyal-wallet
endif
endif

if BUILD_DRIYAL_UTIL
  bin_PROGRAMS += driyal-util
endif

.PHONY: FORCE check-symbols check-security
# driyal core #
DRIYAL_CORE_H = \
  addrdb.h \
  addrman.h \
  addrman_impl.h \
  attributes.h \
  banman.h \
  base58.h \
  bech32.h \
  blockencodings.h \
  blockfilter.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkqueue.h \
  clientversion.h \
  coins.h \
  common/bloom.h \
  compat.h \
  compat/assumptions.h \
  compat/byteswap.h \
  compat/cpuid.h \
  compat/endian.h \
  compat/sanity.h \
  compressor.h \
  consensus/consensus.h \
  consensus/tx_check.h \
  consensus/tx_verify.h \
  core_io.h \
  core_memusage.h \
  cuckoocache.h \
  dbwrapper.h \
  deploymentinfo.h \
  deploymentstatus.h \
  external_signer.h \
  flatfile.h \
  fs.h \
  httprpc.h \
  httpserver.h \
  i2p.h \
  index/base.h \
  index/blockfilterindex.h \
  index/coinstatsindex.h \
  index/disktxpos.h \
  index/txindex.h \
  indirectmap.h \
  init.h \
  init/common.h \
  interfaces/chain.h \
  interfaces/echo.h \
  interfaces/handler.h \
  interfaces/init.h \
  interfaces/ipc.h \
  interfaces/node.h \
  interfaces/wallet.h \
  key.h \
  key_io.h \
  logging.h \
  logging/timer.h \
  mapport.h \
  memusage.h \
  merkleblock.h \
  net.h \
  net_permissions.h \
  net_processing.h \
  net_types.h \
  netaddress.h \
  netbase.h \
  netmessagemaker.h \
  node/blockstorage.h \
  node/caches.h \
  node/chainstate.h \
  node/coin.h \
  node/coinstats.h \
  node/context.h \
  node/miner.h \
  node/minisketchwrapper.h \
  node/psbt.h \
  node/transaction.h \
  node/ui_interface.h \
  node/utxo_snapshot.h \
  noui.h \
  outputtype.h \
  policy/feerate.h \
  policy/fees.h \
  policy/packages.h \
  policy/policy.h \
  policy/rbf.h \
  policy/settings.h \
  pow.h \
  protocol.h \
  psbt.h \
  random.h \
  randomenv.h \
  reverse_iterator.h \
  rpc/blockchain.h \
  rpc/client.h \
  rpc/mining.h \
  rpc/protocol.h \
  rpc/rawtransaction_util.h \
  rpc/register.h \
  rpc/request.h \
  rpc/server.h \
  rpc/server_util.h \
  rpc/util.h \
  scheduler.h \
  script/descriptor.h \
  script/keyorigin.h \
  script/sigcache.h \
  script/sign.h \
  script/signingprovider.h \
  script/standard.h \
  shutdown.h \
  signet.h \
  streams.h \
  support/allocators/secure.h \
  support/allocators/zeroafterfree.h \
  support/cleanse.h \
  support/events.h \
  support/lockedpool.h \
  sync.h \
  threadinterrupt.h \
  threadsafety.h \
  timedata.h \
  torcontrol.h \
  txdb.h \
  txmempool.h \
  txorphanage.h \
  txrequest.h \
  undo.h \
  util/asmap.h \
  util/bip32.h \
  util/bytevectorhash.h \
  util/check.h \
  util/epochguard.h \
  util/error.h \
  util/fastrange.h \
  util/fees.h \
  util/getuniquepath.h \
  util/golombrice.h \
  util/hash_type.h \
  util/hasher.h \
  util/macros.h \
  util/message.h \
  util/moneystr.h \
  util/overflow.h \
  util/overloaded.h \
  util/rbf.h \
  util/readwritefile.h \
  util/serfloat.h \
  util/settings.h \
  util/sock.h \
  util/spanparsing.h \
  util/string.h \
  util/syscall_sandbox.h \
  util/system.h \
  util/thread.h \
  util/threadnames.h \
  util/time.h \
  util/tokenpipe.h \
  util/trace.h \
  util/translation.h \
  util/types.h \
  util/ui_change_type.h \
  util/url.h \
  util/vector.h \
  validation.h \
  validationinterface.h \
  versionbits.h \
  wallet/bdb.h \
  wallet/coincontrol.h \
  wallet/coinselection.h \
  wallet/context.h \
  wallet/crypter.h \
  wallet/db.h \
  wallet/dump.h \
  wallet/external_signer_scriptpubkeyman.h \
  wallet/feebumper.h \
  wallet/fees.h \
  wallet/ismine.h \
  wallet/load.h \
  wallet/receive.h \
  wallet/rpc/util.h \
  wallet/rpc/wallet.h \
  wallet/salvage.h \
  wallet/scriptpubkeyman.h \
  wallet/spend.h \
  wallet/sqlite.h \
  wallet/transaction.h \
  wallet/wallet.h \
  wallet/walletdb.h \
  wallet/wallettool.h \
  wallet/walletutil.h \
  walletinitinterface.h \
  warnings.h \
  zmq/zmqabstractnotifier.h \
  zmq/zmqnotificationinterface.h \
  zmq/zmqpublishnotifier.h \
  zmq/zmqrpc.h \
  zmq/zmqutil.h


obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh "$(abs_top_builddir)/src/obj/build.h" \
	  "$(abs_top_srcdir)"
libdriyal_util_a-clientversion.$(OBJEXT): obj/build.h

ipc/capnp/libdriyal_ipc_a-ipc.$(OBJEXT): $(libdriyal_ipc_mpgen_input:=.h)

# server: shared between driyald and driyal-qt
# Contains code accessing mempool and chain state that is meant to be separated
# from wallet and gui code (see node/README.md). Shared code should go in
# libdriyal_common or libdriyal_util libraries, instead.
libdriyal_node_a_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(NATPMP_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
libdriyal_node_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libdriyal_node_a_SOURCES = \
  addrdb.cpp \
  addrman.cpp \
  banman.cpp \
  blockencodings.cpp \
  blockfilter.cpp \
  chain.cpp \
  consensus/tx_verify.cpp \
  dbwrapper.cpp \
  deploymentstatus.cpp \
  flatfile.cpp \
  httprpc.cpp \
  httpserver.cpp \
  i2p.cpp \
  index/base.cpp \
  index/blockfilterindex.cpp \
  index/coinstatsindex.cpp \
  index/txindex.cpp \
  init.cpp \
  mapport.cpp \
  net.cpp \
  net_processing.cpp \
  node/blockstorage.cpp \
  node/caches.cpp \
  node/chainstate.cpp \
  node/coin.cpp \
  node/coinstats.cpp \
  node/context.cpp \
  node/interfaces.cpp \
  node/miner.cpp \
  node/minisketchwrapper.cpp \
  node/psbt.cpp \
  node/transaction.cpp \
  node/ui_interface.cpp \
  noui.cpp \
  policy/fees.cpp \
  policy/packages.cpp \
  policy/rbf.cpp \
  policy/settings.cpp \
  pow.cpp \
  rest.cpp \
  rpc/blockchain.cpp \
  rpc/mining.cpp \
  rpc/misc.cpp \
  rpc/net.cpp \
  rpc/rawtransaction.cpp \
  rpc/server.cpp \
  rpc/server_util.cpp \
  script/sigcache.cpp \
  shutdown.cpp \
  signet.cpp \
  timedata.cpp \
  torcontrol.cpp \
  txdb.cpp \
  txmempool.cpp \
  txorphanage.cpp \
  txrequest.cpp \
  validation.cpp \
  validationinterface.cpp \
  versionbits.cpp \
  $(DRIYAL_CORE_H)

if ENABLE_WALLET
libdriyal_node_a_SOURCES += wallet/init.cpp
endif
if !ENABLE_WALLET
libdriyal_node_a_SOURCES += dummywallet.cpp
endif

if ENABLE_ZMQ
libdriyal_zmq_a_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES) $(ZMQ_CFLAGS)
libdriyal_zmq_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libdriyal_zmq_a_SOURCES = \
  zmq/zmqabstractnotifier.cpp \
  zmq/zmqnotificationinterface.cpp \
  zmq/zmqpublishnotifier.cpp \
  zmq/zmqrpc.cpp \
  zmq/zmqutil.cpp
endif


# wallet: shared between driyald and driyal-qt, but only linked
# when wallet enabled
libdriyal_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES) $(SQLITE_CFLAGS)
libdriyal_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libdriyal_wallet_a_SOURCES = \
  wallet/coincontrol.cpp \
  wallet/context.cpp \
  wallet/crypter.cpp \
  wallet/db.cpp \
  wallet/dump.cpp \
  wallet/external_signer_scriptpubkeyman.cpp \
  wallet/feebumper.cpp \
  wallet/fees.cpp \
  wallet/interfaces.cpp \
  wallet/load.cpp \
  wallet/receive.cpp \
  wallet/rpc/addresses.cpp \
  wallet/rpc/backup.cpp \
  wallet/rpc/coins.cpp \
  wallet/rpc/encrypt.cpp \
  wallet/rpc/spend.cpp \
  wallet/rpc/signmessage.cpp \
  wallet/rpc/transactions.cpp \
  wallet/rpc/util.cpp \
  wallet/rpc/wallet.cpp \
  wallet/scriptpubkeyman.cpp \
  wallet/spend.cpp \
  wallet/transaction.cpp \
  wallet/wallet.cpp \
  wallet/walletdb.cpp \
  wallet/walletutil.cpp \
  wallet/coinselection.cpp \
  $(DRIYAL_CORE_H)

if USE_SQLITE
libdriyal_wallet_a_SOURCES += wallet/sqlite.cpp
endif
if USE_BDB
libdriyal_wallet_a_SOURCES += wallet/bdb.cpp wallet/salvage.cpp
endif

libdriyal_wallet_tool_a_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES)
libdriyal_wallet_tool_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libdriyal_wallet_tool_a_SOURCES = \
  wallet/wallettool.cpp \
  $(DRIYAL_CORE_H)

# crypto primitives library
crypto_libdriyal_crypto_base_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libdriyal_crypto_base_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libdriyal_crypto_base_a_SOURCES = \
  crypto/aes.cpp \
  crypto/aes.h \
  crypto/chacha_poly_aead.h \
  crypto/chacha_poly_aead.cpp \
  crypto/chacha20.h \
  crypto/chacha20.cpp \
  crypto/common.h \
  crypto/hkdf_sha256_32.cpp \
  crypto/hkdf_sha256_32.h \
  crypto/hmac_sha256.cpp \
  crypto/hmac_sha256.h \
  crypto/hmac_sha512.cpp \
  crypto/hmac_sha512.h \
  crypto/poly1305.h \
  crypto/poly1305.cpp \
  crypto/muhash.h \
  crypto/muhash.cpp \
  crypto/ripemd160.cpp \
  crypto/ripemd160.h \
  crypto/sha1.cpp \
  crypto/sha1.h \
  crypto/sha256.cpp \
  crypto/sha256.h \
  crypto/sha3.cpp \
  crypto/sha3.h \
  crypto/sha512.cpp \
  crypto/sha512.h \
  crypto/siphash.cpp \
  crypto/siphash.h

if USE_ASM
crypto_libdriyal_crypto_base_a_SOURCES += crypto/sha256_sse4.cpp
endif

crypto_libdriyal_crypto_sse41_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libdriyal_crypto_sse41_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libdriyal_crypto_sse41_a_CXXFLAGS += $(SSE41_CXXFLAGS)
crypto_libdriyal_crypto_sse41_a_CPPFLAGS += -DENABLE_SSE41
crypto_libdriyal_crypto_sse41_a_SOURCES = crypto/sha256_sse41.cpp

crypto_libdriyal_crypto_avx2_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libdriyal_crypto_avx2_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libdriyal_crypto_avx2_a_CXXFLAGS += $(AVX2_CXXFLAGS)
crypto_libdriyal_crypto_avx2_a_CPPFLAGS += -DENABLE_AVX2
crypto_libdriyal_crypto_avx2_a_SOURCES = crypto/sha256_avx2.cpp

crypto_libdriyal_crypto_shani_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libdriyal_crypto_shani_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libdriyal_crypto_shani_a_CXXFLAGS += $(SHANI_CXXFLAGS)
crypto_libdriyal_crypto_shani_a_CPPFLAGS += -DENABLE_SHANI
crypto_libdriyal_crypto_shani_a_SOURCES = crypto/sha256_shani.cpp

# consensus: shared between all executables that validate any consensus rules.
libdriyal_consensus_a_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES)
libdriyal_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libdriyal_consensus_a_SOURCES = \
  arith_uint256.cpp \
  arith_uint256.h \
  consensus/amount.h \
  consensus/merkle.cpp \
  consensus/merkle.h \
  consensus/params.h \
  consensus/tx_check.cpp \
  consensus/validation.h \
  hash.cpp \
  hash.h \
  prevector.h \
  primitives/block.cpp \
  primitives/block.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  script/driyalconsensus.cpp \
  script/interpreter.cpp \
  script/interpreter.h \
  script/script.cpp \
  script/script.h \
  script/script_error.cpp \
  script/script_error.h \
  serialize.h \
  span.h \
  tinyformat.h \
  uint256.cpp \
  uint256.h \
  util/strencodings.cpp \
  util/strencodings.h \
  version.h

# common: shared between driyald, and driyal-qt and non-server tools
libdriyal_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES)
libdriyal_common_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libdriyal_common_a_SOURCES = \
  base58.cpp \
  bech32.cpp \
  chainparams.cpp \
  coins.cpp \
  common/bloom.cpp \
  compressor.cpp \
  core_read.cpp \
  core_write.cpp \
  deploymentinfo.cpp \
  external_signer.cpp \
  init/common.cpp \
  key.cpp \
  key_io.cpp \
  merkleblock.cpp \
  net_types.cpp \
  netaddress.cpp \
  netbase.cpp \
  net_permissions.cpp \
  outputtype.cpp \
  policy/feerate.cpp \
  policy/policy.cpp \
  protocol.cpp \
  psbt.cpp \
  rpc/rawtransaction_util.cpp \
  rpc/external_signer.cpp \
  rpc/util.cpp \
  scheduler.cpp \
  script/descriptor.cpp \
  script/sign.cpp \
  script/signingprovider.cpp \
  script/standard.cpp \
  warnings.cpp \
  $(DRIYAL_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# sanity checks are linked.
libdriyal_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES)
libdriyal_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libdriyal_util_a_SOURCES = \
  support/lockedpool.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  fs.cpp \
  interfaces/echo.cpp \
  interfaces/handler.cpp \
  interfaces/init.cpp \
  logging.cpp \
  random.cpp \
  randomenv.cpp \
  rpc/request.cpp \
  support/cleanse.cpp \
  sync.cpp \
  threadinterrupt.cpp \
  util/asmap.cpp \
  util/bip32.cpp \
  util/bytevectorhash.cpp \
  util/error.cpp \
  util/fees.cpp \
  util/getuniquepath.cpp \
  util/hasher.cpp \
  util/sock.cpp \
  util/system.cpp \
  util/message.cpp \
  util/moneystr.cpp \
  util/rbf.cpp \
  util/readwritefile.cpp \
  util/settings.cpp \
  util/thread.cpp \
  util/threadnames.cpp \
  util/serfloat.cpp \
  util/spanparsing.cpp \
  util/strencodings.cpp \
  util/string.cpp \
  util/syscall_sandbox.cpp \
  util/time.cpp \
  util/tokenpipe.cpp \
  $(DRIYAL_CORE_H)

if USE_LIBEVENT
libdriyal_util_a_SOURCES += util/url.cpp
endif

# cli: shared between driyal-cli and driyal-qt
libdriyal_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES)
libdriyal_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libdriyal_cli_a_SOURCES = \
  compat/stdin.h \
  compat/stdin.cpp \
  rpc/client.cpp \
  $(DRIYAL_CORE_H)

nodist_libdriyal_util_a_SOURCES = $(srcdir)/obj/build.h
#

# driyald & driyal-node binaries #
driyal_daemon_sources = driyald.cpp
driyal_bin_cppflags = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES)
driyal_bin_cxxflags = $(AM_CXXFLAGS) $(PIE_FLAGS)
driyal_bin_ldflags = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS) $(PTHREAD_FLAGS)

if TARGET_WINDOWS
driyal_daemon_sources += driyald-res.rc
endif

driyal_bin_ldadd = \
  $(LIBDRIYAL_WALLET) \
  $(LIBDRIYAL_COMMON) \
  $(LIBDRIYAL_UTIL) \
  $(LIBUNIVALUE) \
  $(LIBDRIYAL_ZMQ) \
  $(LIBDRIYAL_CONSENSUS) \
  $(LIBDRIYAL_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

driyal_bin_ldadd += $(BOOST_LIBS) $(BDB_LIBS) $(MINIUPNPC_LIBS) $(NATPMP_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(ZMQ_LIBS) $(SQLITE_LIBS)

driyald_SOURCES = $(driyal_daemon_sources) init/driyald.cpp
driyald_CPPFLAGS = $(driyal_bin_cppflags)
driyald_CXXFLAGS = $(driyal_bin_cxxflags)
driyald_LDFLAGS = $(driyal_bin_ldflags)
driyald_LDADD = $(LIBDRIYAL_NODE) $(driyal_bin_ldadd)

driyal_node_SOURCES = $(driyal_daemon_sources) init/driyal-node.cpp
driyal_node_CPPFLAGS = $(driyal_bin_cppflags)
driyal_node_CXXFLAGS = $(driyal_bin_cxxflags)
driyal_node_LDFLAGS = $(driyal_bin_ldflags)
driyal_node_LDADD = $(LIBDRIYAL_NODE) $(driyal_bin_ldadd) $(LIBDRIYAL_IPC) $(LIBMULTIPROCESS_LIBS)

# driyal-cli binary #
driyal_cli_SOURCES = driyal-cli.cpp
driyal_cli_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES) $(EVENT_CFLAGS)
driyal_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
driyal_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS) $(PTHREAD_FLAGS)

if TARGET_WINDOWS
driyal_cli_SOURCES += driyal-cli-res.rc
endif

driyal_cli_LDADD = \
  $(LIBDRIYAL_CLI) \
  $(LIBUNIVALUE) \
  $(LIBDRIYAL_UTIL) \
  $(LIBDRIYAL_CRYPTO)

driyal_cli_LDADD += $(BOOST_LIBS) $(EVENT_LIBS)
#

# driyal-tx binary #
driyal_tx_SOURCES = driyal-tx.cpp
driyal_tx_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES)
driyal_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
driyal_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS) $(PTHREAD_FLAGS)

if TARGET_WINDOWS
driyal_tx_SOURCES += driyal-tx-res.rc
endif

driyal_tx_LDADD = \
  $(LIBUNIVALUE) \
  $(LIBDRIYAL_COMMON) \
  $(LIBDRIYAL_UTIL) \
  $(LIBDRIYAL_CONSENSUS) \
  $(LIBDRIYAL_CRYPTO) \
  $(LIBSECP256K1)

driyal_tx_LDADD += $(BOOST_LIBS)
#

# driyal-wallet binary #
driyal_wallet_SOURCES = driyal-wallet.cpp
driyal_wallet_SOURCES += init/driyal-wallet.cpp
driyal_wallet_CPPFLAGS = $(driyal_bin_cppflags)
driyal_wallet_CXXFLAGS = $(driyal_bin_cxxflags)
driyal_wallet_LDFLAGS = $(driyal_bin_ldflags)
driyal_wallet_LDADD = \
  $(LIBDRIYAL_WALLET_TOOL) \
  $(LIBDRIYAL_WALLET) \
  $(LIBDRIYAL_COMMON) \
  $(LIBDRIYAL_UTIL) \
  $(LIBUNIVALUE) \
  $(LIBDRIYAL_CONSENSUS) \
  $(LIBDRIYAL_CRYPTO) \
  $(LIBSECP256K1) \
  $(BOOST_LIBS) \
  $(BDB_LIBS) \
  $(SQLITE_LIBS)

if TARGET_WINDOWS
driyal_wallet_SOURCES += driyal-wallet-res.rc
endif
#

# driyal-util binary #
driyal_util_SOURCES = driyal-util.cpp
driyal_util_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES)
driyal_util_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
driyal_util_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS) $(PTHREAD_FLAGS)

if TARGET_WINDOWS
driyal_util_SOURCES += driyal-util-res.rc
endif

driyal_util_LDADD = \
  $(LIBDRIYAL_COMMON) \
  $(LIBDRIYAL_UTIL) \
  $(LIBUNIVALUE) \
  $(LIBDRIYAL_CONSENSUS) \
  $(LIBDRIYAL_CRYPTO) \
  $(LIBSECP256K1)

driyal_util_LDADD += $(BOOST_LIBS)
#

# driyalconsensus library #
if BUILD_DRIYAL_LIBS
include_HEADERS = script/driyalconsensus.h
libdriyalconsensus_la_SOURCES = support/cleanse.cpp $(crypto_libdriyal_crypto_base_a_SOURCES) $(libdriyal_consensus_a_SOURCES)

libdriyalconsensus_la_LDFLAGS = $(AM_LDFLAGS) -no-undefined $(RELDFLAGS)
libdriyalconsensus_la_LIBADD = $(LIBSECP256K1)
libdriyalconsensus_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_DRIYAL_INTERNAL
libdriyalconsensus_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#

CTAES_DIST =  crypto/ctaes/bench.c
CTAES_DIST += crypto/ctaes/ctaes.c
CTAES_DIST += crypto/ctaes/ctaes.h
CTAES_DIST += crypto/ctaes/README.md
CTAES_DIST += crypto/ctaes/test.c

CLEANFILES = $(EXTRA_LIBRARIES)

CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crc32c/src/*.gcda crc32c/src/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += index/*.gcda index/*.gcno
CLEANFILES += interfaces/*.gcda interfaces/*.gcno
CLEANFILES += node/*.gcda node/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += rpc/*.gcda rpc/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += util/*.gcda util/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno
CLEANFILES += zmq/*.gcda zmq/*.gcno
CLEANFILES += obj/build.h

EXTRA_DIST = $(CTAES_DIST)


config/driyal-config.h: config/stamp-h1
	@$(MAKE) -C $(top_builddir) $(subdir)/$(@)
config/stamp-h1: $(top_srcdir)/$(subdir)/config/driyal-config.h.in $(top_builddir)/config.status
	$(AM_V_at)$(MAKE) -C $(top_builddir) $(subdir)/$(@)
$(top_srcdir)/$(subdir)/config/driyal-config.h.in:  $(am__configure_deps)
	$(AM_V_at)$(MAKE) -C $(top_srcdir) $(subdir)/config/driyal-config.h.in

clean-local:
	-$(MAKE) -C secp256k1 clean
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -f config.h
	-rm -rf test/__pycache__

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@

check-symbols: $(bin_PROGRAMS)
	@echo "Running symbol and dynamic library checks..."
	$(AM_V_at) $(PYTHON) $(top_srcdir)/contrib/devtools/symbol-check.py $(bin_PROGRAMS)

check-security: $(bin_PROGRAMS)
if HARDEN
	@echo "Checking binary security..."
	$(AM_V_at) $(PYTHON) $(top_srcdir)/contrib/devtools/security-check.py $(bin_PROGRAMS)
endif

libdriyal_ipc_mpgen_input = \
  ipc/capnp/echo.capnp \
  ipc/capnp/init.capnp
EXTRA_DIST += $(libdriyal_ipc_mpgen_input)
%.capnp:

if BUILD_MULTIPROCESS
LIBDRIYAL_IPC=libdriyal_ipc.a
libdriyal_ipc_a_SOURCES = \
  ipc/capnp/context.h \
  ipc/capnp/init-types.h \
  ipc/capnp/protocol.cpp \
  ipc/capnp/protocol.h \
  ipc/context.h \
  ipc/exception.h \
  ipc/interfaces.cpp \
  ipc/process.cpp \
  ipc/process.h \
  ipc/protocol.h
libdriyal_ipc_a_CPPFLAGS = $(AM_CPPFLAGS) $(DRIYAL_INCLUDES)
libdriyal_ipc_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS) $(LIBMULTIPROCESS_CFLAGS)

include $(MPGEN_PREFIX)/include/mpgen.mk
libdriyal_ipc_mpgen_output = \
  $(libdriyal_ipc_mpgen_input:=.c++) \
  $(libdriyal_ipc_mpgen_input:=.h) \
  $(libdriyal_ipc_mpgen_input:=.proxy-client.c++) \
  $(libdriyal_ipc_mpgen_input:=.proxy-server.c++) \
  $(libdriyal_ipc_mpgen_input:=.proxy-types.c++) \
  $(libdriyal_ipc_mpgen_input:=.proxy-types.h) \
  $(libdriyal_ipc_mpgen_input:=.proxy.h)
nodist_libdriyal_ipc_a_SOURCES = $(libdriyal_ipc_mpgen_output)
CLEANFILES += $(libdriyal_ipc_mpgen_output)
endif

include Makefile.minisketch.include

include Makefile.crc32c.include
include Makefile.leveldb.include

include Makefile.test_util.include
include Makefile.test_fuzz.include

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_BENCH
include Makefile.bench.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif

include Makefile.univalue.include
