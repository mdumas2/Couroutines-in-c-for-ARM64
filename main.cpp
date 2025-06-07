#include <print>
#include "coroutine.hpp"

int main()
{
    coroutine_init();

    coroutine_go([](void *arg) {
        long int n = (long int)arg;
        for (int i = 0; i < n; ++i) {
            std::println("counter[{}]: {}", coroutine_id(), i+1);
            coroutine_yield();
        }
    }, (void*)5);

    coroutine_go([](void *arg) {
        long int n = (long int)arg;
        for (int i = 0; i < n; ++i) {
            std::println("counter[{}]: {}", coroutine_id(), i+1);
            coroutine_yield();
        }
    }, (void*)10);

    while (coroutine_alive() > 1) coroutine_yield();
    coroutine_finish();
    return 0;
}