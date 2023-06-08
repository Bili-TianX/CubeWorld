#pragma once

#include "Block.hpp"

class Registry {
 public:
  Registry();

  void registerBlocks();

 private:
  std::shared_ptr<std::map<unsigned int, std::shared_ptr<Block*>>> blocks;
};
