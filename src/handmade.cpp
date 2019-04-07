#include <time.h>
#include <SDL.h>

int main (int argc, char** argv) {
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
    };
}
