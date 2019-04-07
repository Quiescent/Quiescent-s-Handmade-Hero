#include <time.h>
#include <SDL.h>
#include <functional>

typedef std::function<void(void)> Thunk;

void handleWindowEvent(const SDL_Event* event, const Thunk exitProgram) {
    switch (event->window.event) {
    case SDL_WINDOWEVENT_RESIZED:
        break;
    case SDL_WINDOWEVENT_SIZE_CHANGED:
        break;
    case SDL_WINDOWEVENT_CLOSE:
        exitProgram();
        break;
    default:
        break;
    }
}

void handleWindowEvent(const Thunk exitProgram) {
    SDL_Event event;
    if (SDL_PollEvent(&event) && event.window.event) {
        handleWindowEvent(exitProgram);
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
        duration->tv_sec  = 1;
        duration->tv_nsec = 0;
        nanosleep(duration, NULL);
        handleWindowEvent(exitProgram);
    };
}
