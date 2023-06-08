#include "Game.hpp"

std::weak_ptr<Game> Game::getInstance() {
  static auto game = std::shared_ptr<Game>(new Game);

  return game;
}

Game::Game() { window = std::make_shared<Window>(); }

void Game::start() {
  SPDLOG_INFO("Start game");
  running = true;

  run();
}

void Game::run() {
  auto renderer = window->getRenderer().lock();

  while (running) {
    renderer->clear();
    renderer->display();

    glfwPollEvents();
  }
}

void Game::stop() {
  SPDLOG_INFO("Stop game");

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
  running = false;
#pragma clang diagnostic pop
}

void Game::registerBlocks() {

}
