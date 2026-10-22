// Source: CLCiffConversion_Data.dll @ 45020d86; FUN_45020d86

LSTATUS __thiscall FUN_45020d86(void *this,LPCWSTR param_1,LPBYTE param_2,uint *param_3)

{
  uint *puVar1;
  LSTATUS LVar2;
  uint local_8;
  
  puVar1 = param_3;
  local_8 = *param_3 * 2;
  *param_3 = 0;
  LVar2 = RegQueryValueExW(*(HKEY *)this,param_1,(LPDWORD)0x0,(LPDWORD)&param_3,param_2,&local_8);
  if (LVar2 != 0) {
    return LVar2;
  }
  if ((param_3 == (uint *)0x1) || (param_3 == (uint *)0x2)) {
    if (param_2 != (LPBYTE)0x0) {
      if (local_8 == 0) {
        param_2[0] = '\0';
        param_2[1] = '\0';
      }
      else if (((local_8 & 1) != 0) || (*(short *)(param_2 + ((local_8 & 0xfffffffe) - 2)) != 0))
      goto LAB_45020dc3;
    }
    LVar2 = 0;
    *puVar1 = local_8 >> 1;
  }
  else {
LAB_45020dc3:
    LVar2 = 0xd;
  }
  return LVar2;
}


