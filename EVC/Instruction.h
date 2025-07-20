#ifndef EVC_INSTRUCTION_H
#define EVC_INSTRUCTION_H

#include "config.h"

// use (uint32_t or uint64_t)instruction & EVC_INSTRUCTION_FIELD
#define EVC_OPCODE (0b000000000000000000001111111)
#define EVC_TYPE   (0b000000000000000000110000000)

#if EVC_ARCH == 32
#define EVC_DT_ITYPE3 (0b000000000011111111000000000)
#define EVC_DT_ITYPE2 (0b000001111111111111000000000)
#define EVC_DT_ITYPE1 (0b111111111111111111000000000)
#elif EVC_ARCH == 64
#define EVC_DT_ITYPE3                                                          \
  (0b00000000001111111111111111111111111111111111111111000000000)
#define EVC_DT_ITYPE2                                                          \
  (0b00000111111111111111111111111111111111111111111111000000000)
#define EVC_DT_ITYPE1                                                          \
  (0b11111111111111111111111111111111111111111111111111000000000)
#endif // EVC_ARCH == *

#define EVC_R3    (0b11111 << (EVC_ARCH - 15))
#define EVC_R2    (0b11111 << (EVC_ARCH - 10))
#define EVC_R1    (0b11111 << (EVC_ARCH - 5))
#define EVC_DT(n) (((1 << n) - 1) << 9)

#define GET_FUNC memory[0] & 0b00000011

#if EVC_ARCH == 32
#define EVC_TYPE_TYPE(opname)                                                  \
  switch (func) {                                                              \
  case 0: opname(uint8_t) break;                                               \
  case 1: opname(uint16_t) break;                                              \
  case 2: opname(uint32_t) break;                                              \
  default: opname(uint32_t) break;                                             \
  }
#elif EVC_ARCH == 64
#define EVC_INSTRUCTION(opname)                                                \
  switch (func) {                                                              \
  case 0: opname(uint8_t) break;                                               \
  case 1: opname(uint16_t) break;                                              \
  case 2: opname(uint32_t) break;                                              \
  case 3: opname(uint64_t) break;                                              \
  }
#endif // EVC_ARCH == 32

#define _APPL      memory[appl]
#define _APPL2     memory[appl2]
#define _APPL3     memory[appl3]
#define _CONDITION memory[1]
#define _IVALUE    memory[2]

#endif // !EVC_INSTRUCTION_H
