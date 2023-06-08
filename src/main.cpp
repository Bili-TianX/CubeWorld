#include "Game.hpp"

#ifdef NDEBUG

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
                   _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
#else

int main()
#endif
{
  try {
    Game::getInstance().lock()->start();
    return EXIT_SUCCESS;
  } catch (const std::exception &e) {
    SPDLOG_ERROR("Exception caught: {}", e.what());
    return EXIT_FAILURE;
  }
}