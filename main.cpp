#include <cstdlib>
#include <iostream>

#include "window/window.h"

int main(int argc, char *argv[]) {
    try {
        Window window("Vortex Engine", 800, 600);
        window.start_event_loop();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return EXIT_SUCCESS;
}
