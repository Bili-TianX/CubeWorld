#pragma once

#include "Client/Window.hpp"

class Game final {
 public:
  static std::weak_ptr<Game> getInstance();

  void start();

  void stop();

 private:
  Game();

  void registerBlocks();

  void run();

  std::shared_ptr<Window> window;

  bool running = false;
};
