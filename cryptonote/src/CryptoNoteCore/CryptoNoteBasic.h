// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2017-2018 The Circle Foundation & Conceal Devs
// Copyright (c) 2018-2019 Conceal Network & Conceal Devs
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <boost/utility/value_init.hpp>
#include <CryptoNote.h>

namespace CryptoNote {
  const Crypto::Hash NULL_HASH = boost::value_initialized<Crypto::Hash>();
  const Crypto::PublicKey NULL_PUBLIC_KEY = boost::value_initialized<Crypto::PublicKey>();
  const Crypto::SecretKey NULL_SECRET_KEY = boost::value_initialized<Crypto::SecretKey>();

  KeyPair generateKeyPair();

  struct ParentBlockSerializer {
    ParentBlockSerializer(ParentBlock& parentBlock, uint64_t& timestamp, uint32_t& nonce, bool hashingSerialization, bool headerOnly) :
      m_parentBlock(parentBlock), m_timestamp(timestamp), m_nonce(nonce), m_hashingSerialization(hashingSerialization), m_headerOnly(headerOnly) {
    }

    ParentBlock& m_parentBlock;
    uint64_t& m_timestamp;
    uint32_t& m_nonce;
    bool m_hashingSerialization;
    bool m_headerOnly;
  };

  inline ParentBlockSerializer makeParentBlockSerializer(const Block& b, bool hashingSerialization, bool headerOnly) {
    Block& blockRef = const_cast<Block&>(b);
    return ParentBlockSerializer(blockRef.parentBlock, blockRef.timestamp, blockRef.nonce, hashingSerialization, headerOnly);
  }

}
