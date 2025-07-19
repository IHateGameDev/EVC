#ifndef EVC_INSTRUCTION_H
#define EVC_INSTRUCTION_H

#include "config.h"

#define GET_OPCODE memory[0] & 0b11111100

#define GET_FUNC memory[0] & 0b00000011

#define READ_APPL(n)                                                           \
  EvcSize appl##n = memory[memory[0]];                                         \
  memory[0] += 2

#undef READ_APPL

#if EVC_ARCH == 32
#define EVC_INSTRUCTION(opname)                                                \
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
