#ifndef EVC_BASE_INSTRUCTIONS_H
#define EVC_BASE_INSTRUCTIONS_H

#include "config.h"

#define READ_APPL(n)                                                           \
  EvcSize appl##n = memory[memory[0]];                                         \
  memory[0] += sizeof(EvcSize)

#define EVC_PREPARE()                                                          \
  READ_APPL();                                                                 \
  READ_APPL(2);                                                                \
  READ_APPL(3);

#undef READ_APPL

#define EVC_INSTRUCTION(opname)                                                \
  switch (func) {                                                              \
  case 0: opname(uint8_t) break;                                               \
  case 1: opname(uint16_t) break;                                              \
  case 2: opname(uint32_t) break;                                              \
  }

#define _APPL      memory[appl]
#define _APPL2     memory[appl2]
#define _APPL3     memory[appl3]
#define _CONDITION memory[1]
#define _IVALUE    memory[2]

#define BASE_NONE(type)

#define BASE_COPY(type) (type) _APPL2 = (type)_APPL
#define BASE_COPY_IF(type)         if ((_CONDITION) (type)_APPL2 = (type)_APPL
#define BASE_COPY_TO_DEREF(type)   memory[(EvcSize)_APPL2] = (type)_APPL
#define BASE_COPY_FROM_DEREF(type) (type) _APPL2 = memory[(EvcSize)_APPL]

#define BASE_ADD(type)       (type) _APPL3 = (type)_APPL + (type)_APPL2
#define BASE_SUBSTRUCT(type) (type) _APPL3 = (type)_APPL - (type)_APPL2

#define BASE_EQUAL(type)   _CONDITION = (type)_APPL == (type)_APPL2
#define BASE_GREATER(type) _CONDITION = (type)_APPL > (type)_APPL2
#define BASE_LESS(type)    _CONDITION = (type)_APPL < (type)_APPL2

#define BASE_NOT(type) (type) _APPL2 = ~(type)_APPL
#define BASE_OR(type)  (type) _APPL3 = (type)_APPL | (type)_APPL2
#define BASE_AND(type) (type) _APPL3 = (type)_APPL & (type)_APPL2
#define BASE_XOR(type) (type) _APPL3 = (type)_APPL ^ (type)_APPL2

#define BASE_INVOKE _IVALUE = memoty[appl]
#define BASE_HALT   _IVALUE = EVC_SIZE_MAX

#endif // !EVC_BASE_INSTRUCTIONS_H
