# Requires

+ `vcpkg` package from [VS 2022](https://visualstudio.microsoft.com/insiders/).
+ `LLVM`, `ninja`. Can be installed from [chocolatey](https://chocolatey.org/)

# Installation

1. Setup your `VCPKG_ROOT` to env. Also add `vcpkg` to your `path`.
2. Run `install.bat` to install dependencies lib.

# Notice

- If your Clang version is higher than `11`, then goto `SDL_endian.h` file inside your `build/xx-version-installed-xx/include/SDL2/` folder, remove the `_m_prefetchw` define
```SDL_endian.h
    /* As of Clang 11, '_m_prefetchw' is conflicting with the winnt.h's version,
       so we define the needed '_m_prefetch' here as a pseudo-header, until the issue is fixed. */
    #ifdef __clang__
    #ifndef __PRFCHWINTRIN_H
    #define __PRFCHWINTRIN_H
    //static __inline__ void __attribute__((__always_inline__, __nodebug__))
    //_m_prefetch(void *__P)
    //{
    //  __builtin_prefetch(__P, 0, 3 /* _MM_HINT_T0 */);
    //}
    #endif /* __PRFCHWINTRIN_H */
    #endif /* __clang__ */
```
