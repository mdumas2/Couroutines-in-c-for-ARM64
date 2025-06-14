#pragma once

void coroutine_init(void);
void coroutine_finish(void);
void coroutine_yield(void);
void coroutine_go(void (*f)(void*), void *arg);
size_t coroutine_id(void);
size_t coroutine_alive(void);