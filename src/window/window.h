#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>

#include "utils/logger/logger.h"

inline Logger logger("window.txt");

class Window {
    int width_;
    int height_;
    SDL_Window *window_;

public:
    Window(const std::string &title, const int width, const int height)
        : width_(width), height_(height), window_(nullptr) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            logger.critical(std::format("SDL could not be initialised! SDL_Error: {}", SDL_GetError()));
            throw std::runtime_error("SDL could not be initialised!");
        }

        window_ = SDL_CreateWindow(title.c_str(), width_, height_, SDL_WINDOW_VULKAN);
        if (window_ == nullptr) {
            logger.critical(std::format("Window could not be created! SDL_Error: {}", SDL_GetError()));
            throw std::runtime_error("Window could not be created!");
        }
    }

    ~Window() {
        if (window_ != nullptr) {
            SDL_DestroyWindow(window_);
        }
        SDL_Quit();
    };

    void start_event_loop() {
        SDL_Event event;
        bool quit = false;

        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_EVENT_QUIT) {
                    quit = true;
                }
            }
        }
    }

    [[nodiscard]] SDL_Window *get_window() const {
        return window_;
    }
};


#endif //WINDOW_H
