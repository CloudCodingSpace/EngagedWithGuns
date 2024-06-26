#include <iostream>
#include <stdexcept>
#include <memory>

#include "Engine/EGEngine.h"

int main(int argc, const char** argv)
{
	try {
		std::shared_ptr<EG::EGEngine> game = std::make_shared<EG::EGEngine>(EG_STD_WIDTH, EG_STD_HEIGHT, "EnagagedWithGuns");
		game->Run();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cin.get();
		return EXIT_FAILURE;
	}

	std::cin.get();
	return EXIT_SUCCESS;
}