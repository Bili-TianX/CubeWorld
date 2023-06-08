#include "Registry.hpp"

#define REGISTER_BLOCK(x, ...) \
  blocks[x] = std::make_shared<Block>(x, __VA_ARGS__)

Registry::Registry() {
  blocks = std::make_shared<std::map<unsigned int, std::shared_ptr<Block*>>>();
}

void Registry::registerBlocks() {
  REGISTER_BLOCK(0, "Air");
  REGISTER_BLOCK(1, "Bedrock");
  REGISTER_BLOCK(2, "GrassBlock");
}
