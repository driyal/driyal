// Copyright (c) 2020 The DRiyal Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DRIYAL_WALLET_DUMP_H
#define DRIYAL_WALLET_DUMP_H

#include <fs.h>

struct bilingual_str;

namespace wallet {
class CWallet;
bool DumpWallet(CWallet& wallet, bilingual_str& error);
bool CreateFromDump(const std::string& name, const fs::path& wallet_path, bilingual_str& error, std::vector<bilingual_str>& warnings);
} // namespace wallet

#endif // DRIYAL_WALLET_DUMP_H
