#ifndef EVC_CONFIG_H
#define EVC_CONFIG_H

#ifndef EVC_MAX_ARCH
#define EVC_MAX_ARCH 0
#endif

#include <stdint.h>

#if !defined(EVC_ARCH) || (EVC_ARCH > EVC_MAX_ARCH && EVC_ARCH < 0)
#warning "Unsupported architecture. Reset to default: EVC_ARCH=0 [16]"
#undef EVC_ARCH
#define EVC_ARCH 0
#endif

#if EVC_ARCH == 0
typedef uint16_t EvcSize;
#elif EVC_ARCH == 1
typedef uint32_t EvcSize;
#elif EVC_ARCH == 2
typedef uint64_t EvcSize;
#endif

#endif // !EVC_CONFIG_H
