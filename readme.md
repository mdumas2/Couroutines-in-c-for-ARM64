# Coroutines in C++ for ARM64 MACOS
This is a fork of:
- [Tsoding Coroutines Implementation](https://github.com/tsoding/coroutines)

Materials that help me in this implementation:
- [MAC OS SYSCALL](https://github.com/apple-oss-distributions/xnu/blob/e3723e1f17661b24996789d8afc084c0c3303b26/bsd/kern/syscalls.master#L2)
- [x86 Instruction Set Reference](https://c9x.me/x86/)
- [ARM 64 ABI Procedure Call Standard](https://c9x.me/compile/bib/abi-arm64.pdf)
- [Determining Instruction Set Characteristics](https://developer.apple.com/documentation/kernel/1387446-sysctlbyname/determining_instruction_set_characteristics)
- [Apple Instruction Set](https://developer.apple.com/fonts/TrueType-Reference-Manual/RM05/Chap5.html)
- [Arm Architecture Reference Manual for A-profile architecture](https://developer.apple.com/documentation/kernel/1387446-sysctlbyname/determining_instruction_set_characteristics#:~:text=Arm%20Architecture%20Reference%20Manual%20for%20A%2Dprofile%20architecture.)
- [Writing ARM64 code for Apple platforms](https://developer.apple.com/documentation/xcode/writing-arm64-code-for-apple-platforms)
- [A64 -- Base Instructions](https://developer.arm.com/documentation/ddi0602/2025-03/Base-Instructions)
- [Just enough assembly to blow your mind](https://www.youtube.com/watch?v=GU8MnZI0snA&ab_channel=KayLack)
- [Assembly follow-up: from ARM64 to x86-64](https://www.youtube.com/watch?v=feqD9k0Inds&ab_channel=KayLack)
- [Fast and Beautiful Assembly](https://www.youtube.com/watch?v=ON9vuzLiGuc&ab_channel=KayLack)
- [Tsoding Coroutines](https://www.youtube.com/playlist?list=PLpM-Dvs8t0VYkIVqDPCa63XiFA-ycqmOe)
- [ARM Cortex-M RTOS Context Switching](https://interrupt.memfault.com/blog/cortex-m-rtos-context-switching)
- [Context switch example](https://github.com/crystal-lang/crystal/blob/c911fb4862dcc3751bff169a8c733936a668ae7c/src/fiber/context/aarch64-generic.cr#L3-L126)
- [raspberry context switch](https://forums.raspberrypi.com/viewtopic.php?t=324182)
- [Context Switching and Performance: What Every Developer Should Know](https://blog.codingconfessions.com/p/context-switching-and-performance)
- [Procedure Call Standard](https://developer.arm.com/documentation/102374/0102/Procedure-Call-Standard)
- [__attribute__((naked)) function attribute](https://developer.arm.com/documentation/101754/0614/armclang-Reference/Compiler-specific-Function--Variable--and-Type-Attributes/--attribute----naked---function-attribute?lang=en)
- [C++ Weekly - Ep 469 - How to Print in C++23](https://www.youtube.com/watch?v=s6CZmNOCoQU)