// Source: CLCiffConversion_Data.dll @ 4502e09d; FUN_4502e09d

uint __cdecl FUN_4502e09d(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint extraout_EAX;
  bool in_ZF;
  ushort in_FPUControlWord;
  undefined4 unaff_retaddr;
  
  if (in_ZF) {
    if (((param_2 & 0xfffff) != 0) || (param_1 != 0)) {
      uVar2 = FUN_4503118c();
      goto LAB_4502e11b;
    }
    uVar2 = 0;
    uVar1 = param_2 & 0x80000000;
joined_r0x4502e10c:
    if (uVar1 == 0) {
LAB_4502e0be:
      if (DAT_4505502c != 0) {
        return uVar2;
      }
      uVar2 = __math_exit(&DAT_45052220,5,unaff_retaddr,param_1,param_2);
      return uVar2;
    }
  }
  else {
    uVar2 = param_2;
    if (in_FPUControlWord != 0x27f) {
      uVar2 = FUN_45031175();
    }
    if ((uVar2 & 0x80000000) == 0) goto LAB_4502e0be;
    if (((uVar2 & 0x7ff00000) == 0) && (uVar1 = param_1, (uVar2 & 0xfffff) == 0))
    goto joined_r0x4502e10c;
  }
  uVar2 = 1;
LAB_4502e11b:
  if (DAT_4505502c != 0) {
    return uVar2;
  }
  __startOneArgErrorHandling(&DAT_45052220,5,in_FPUControlWord,unaff_retaddr,param_1,param_2);
  return extraout_EAX;
}


