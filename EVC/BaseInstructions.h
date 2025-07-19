#ifndef EVC_BASE_INSTRUCTIONS_H
#define EVC_BASE_INSTRUCTIONS_H

#include "Instruction.h"

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
