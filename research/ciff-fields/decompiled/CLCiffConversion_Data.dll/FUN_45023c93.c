// Source: CLCiffConversion_Data.dll @ 45023c93; FUN_45023c93

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __cdecl FUN_45023c93(wchar_t *param_1,uint param_2,int *param_3)

{
  uint _Size;
  wchar_t wVar1;
  uint uVar2;
  int *piVar3;
  size_t sVar4;
  uint _CchDest;
  undefined4 *puVar5;
  wchar_t *_LpDestStr;
  int iVar6;
  
  uVar2 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if (param_1 == (wchar_t *)0x0) {
LAB_45023cab:
    piVar3 = __errno();
    iVar6 = 0x16;
  }
  else {
    sVar4 = _wcsnlen(param_1,param_2);
    if (param_2 <= sVar4) {
      *param_1 = L'\0';
      goto LAB_45023cab;
    }
    _LpDestStr = (wchar_t *)0x0;
    if (*(LPCWSTR *)(*param_3 + 0xa8) == (LPCWSTR)0x0) {
      for (; *param_1 != L'\0'; param_1 = param_1 + 1) {
        wVar1 = *param_1;
        if ((0x60 < (ushort)wVar1) && ((ushort)wVar1 < 0x7b)) {
          *param_1 = wVar1 + L'￠';
        }
      }
      goto LAB_45023dfb;
    }
    _CchDest = ___crtLCMapStringW(*(LPCWSTR *)(*param_3 + 0xa8),0x200,param_1,-1,(LPWSTR)0x0,0);
    if (_CchDest == 0) {
      piVar3 = __errno();
      *piVar3 = 0x2a;
LAB_45023d0d:
      __errno();
      goto LAB_45023dfb;
    }
    if (_CchDest <= param_2) {
      if ((((int)_CchDest < 1) || (0xffffffe0 / _CchDest < 2)) || (_CchDest * 2 + 8 <= _CchDest * 2)
         ) {
LAB_45023da2:
        if (_LpDestStr != (wchar_t *)0x0) {
          iVar6 = ___crtLCMapStringW(*(LPCWSTR *)(*param_3 + 0xa8),0x200,param_1,-1,_LpDestStr,
                                     _CchDest);
          if (iVar6 == 0) {
            piVar3 = __errno();
            *piVar3 = 0x2a;
          }
          else {
            _wcscpy_s(param_1,param_2,_LpDestStr);
          }
          FUN_45023e0f((int)_LpDestStr);
          goto LAB_45023dfb;
        }
      }
      else {
        _Size = _CchDest * 2 + 8;
        if (_Size < 0x401) {
          puVar5 = (undefined4 *)&stack0xffffffec;
          if (&stack0x00000000 != (undefined1 *)0x14) {
LAB_45023d9f:
            _LpDestStr = (wchar_t *)(puVar5 + 2);
            goto LAB_45023da2;
          }
        }
        else {
          puVar5 = _malloc(_Size);
          if (puVar5 != (undefined4 *)0x0) {
            *puVar5 = 0xdddd;
            goto LAB_45023d9f;
          }
        }
      }
      piVar3 = __errno();
      *piVar3 = 0xc;
      goto LAB_45023d0d;
    }
    *param_1 = L'\0';
    piVar3 = __errno();
    iVar6 = 0x22;
  }
  *piVar3 = iVar6;
  FUN_45027e29();
LAB_45023dfb:
  FUN_45022e32(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}


