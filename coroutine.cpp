#include <vector>
#include "coroutine.hpp"

static constexpr std::size_t STACK_CAPACITY = 8 * 1024 * 1024;

typedef struct {
    void *rsp;
    void *stack_base;
} Context;

std::vector<Context> contexts;
size_t current = 0;

void coroutine_yield(void) __attribute__((naked))
{
    asm("    stp x29, x30, [sp, #-16]!");
    asm("    stp x27, x28, [sp, #-16]!");
    asm("    stp x25, x26, [sp, #-16]!");
    asm("    stp x23, x24, [sp, #-16]!");
    asm("    stp x21, x22, [sp, #-16]!");
    asm("    stp x19, x20, [sp, #-16]!");
    asm("    stp x0,  x1,  [sp, #-16]!");
    asm("    mov x0, sp");
    asm("    b _coroutine_switch_context");

}

void coroutine_restore_context(void *rsp) __attribute__((naked))
{
    asm("    mov sp, x0");
    asm("    ldp x0,  x1,  [sp], #16");
    asm("    ldp x19, x20, [sp], #16");
    asm("    ldp x21, x22, [sp], #16");
    asm("    ldp x23, x24, [sp], #16");
    asm("    ldp x25, x26, [sp], #16");
    asm("    ldp x27, x28, [sp], #16");
    asm("    ldp x29, x30, [sp], #16");
    asm("    blr x30");
    asm("    br x19");
}

extern "C" void coroutine_switch_context(void *rsp)
{
    contexts[current].rsp = rsp;
    current = (current + 1) % contexts.size();
    coroutine_restore_context(contexts[current].rsp);
}

void coroutine_init(void)
{
    contexts.push_back({nullptr, nullptr});
}

void coroutine_finish(void)
{
    if (current == 0) {
        for (size_t i = 1; i < contexts.size(); ++i)
            free(contexts[i].stack_base);
        contexts.clear();
        return;
    }

    delete[] contexts[current].stack_base;

    Context t = contexts[current];
    contexts[current] = contexts.back();
    contexts.back() = t;
    contexts.pop_back();

    current %= contexts.size();
    coroutine_restore_context(contexts[current].rsp);
}

void coroutine_go(void (*coroutine_entry)(void*), void *arg)
{
    void* stack_base = static_cast<void*>(new char[STACK_CAPACITY]);
    void** rsp = reinterpret_cast<void**>(static_cast<char*>(stack_base) + STACK_CAPACITY);

    *(--rsp) = (void*)coroutine_entry;          // x30 (callee return address, aka function to enter)
    *(--rsp) = nullptr;                         // x29 (frame pointer)
    *(--rsp) = nullptr;                         // x28
    *(--rsp) = nullptr;                         // x27
    *(--rsp) = nullptr;                         // x26
    *(--rsp) = nullptr;                         // x25
    *(--rsp) = nullptr;                         // x24
    *(--rsp) = nullptr;                         // x23
    *(--rsp) = nullptr;                         // x22
    *(--rsp) = nullptr;                         // x21
    *(--rsp) = nullptr;                         // x20
    *(--rsp) = (void*)coroutine_finish;         // x19 (return address after coroutine)
    *(--rsp) = nullptr;                         // x1
    *(--rsp) = arg;                             // x0

    contexts.push_back({rsp, stack_base});
}

size_t coroutine_id(void)
{
    return current;
}

size_t coroutine_alive(void)
{
    return contexts.size();
}