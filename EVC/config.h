#ifndef EVC_CONFIG_H
#define EVC_CONFIG_H

#ifndef EVC_MAX_ARCH
#define EVC_MAX_ARCH 64
#endif

#include <stdint.h>

#if !defined(EVC_ARCH) || (EVC_ARCH > EVC_MAX_ARCH && EVC_ARCH < 32)
#warning "Unsupported architecture. Reset to default: EVC_ARCH=32"
#undef EVC_ARCH
#define EVC_ARCH 32
#endif

#if EVC_ARCH == 32
typedef uint32_t EvcSize;
#elif EVC_ARCH == 64
typedef uint64_t EvcSize;
#endif

#endif // !EVC_CONFIG_H
