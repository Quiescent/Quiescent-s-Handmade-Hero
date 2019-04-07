#include <time.h>
#include <iostream>
#include <SDL.h>
#include <functional>

typedef std::function<void(void)> Thunk;

void handleWindowEvent(const SDL_Event* event) {
    switch (event->window.event) {
    case SDL_WINDOWEVENT_RESIZED:
        // TODO !!!
        break;
    case SDL_WINDOWEVENT_SIZE_CHANGED:
        // TODO !!!
        break;
    default:
        // TODO !!!
        break;
    }
}

void handleEvent(const Thunk exitProgram) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exitProgram();
            break;

        case SDL_WINDOWEVENT:
            handleWindowEvent(&event);
            break;

        default:
            // TODO !!!
            break;
        }
    }
}

static const Thunk exitProgram = []() { exit(0); };

int main(int argc, char** argv) {
    const auto window = SDL_CreateWindow("Hello world!",
                                         0,
                                         0,
                                         200,
                                         300,
                                         0);
    while (true) {
        const auto duration = new timespec();
        duration->tv_sec  = 0;
        duration->tv_nsec = 5000;
        nanosleep(duration, NULL);
        handleEvent(exitProgram);
    };
}
