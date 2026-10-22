// Source: CLCiffConversion_Data.dll @ 4502d7e2; FUN_4502d7e2

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __cdecl
FUN_4502d7e2(int *param_1,wchar_t *param_2,uint param_3,LPCSTR param_4,int param_5,LPWSTR param_6,
            int param_7,UINT param_8,int param_9)

{
  uint _Size;
  uint uVar1;
  char *pcVar2;
  int iVar3;
  uint cchWideChar;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  LPCWSTR lpWideCharStr;
  LPCWSTR lpWideCharStr_00;
  
  uVar1 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  pcVar2 = param_4;
  iVar6 = param_5;
  if (0 < param_5) {
    do {
      iVar6 = iVar6 + -1;
      if (*pcVar2 == '\0') goto LAB_4502d80e;
      pcVar2 = pcVar2 + 1;
    } while (iVar6 != 0);
    iVar6 = -1;
LAB_4502d80e:
    iVar3 = (param_5 - iVar6) + -1;
    iVar6 = param_5 - iVar6;
    if (param_5 <= iVar3) {
      iVar6 = iVar3;
    }
  }
  if (param_8 == 0) {
    param_8 = *(UINT *)(*param_1 + 4);
  }
  cchWideChar = MultiByteToWideChar(param_8,(uint)(param_9 != 0) * 8 + 1,param_4,iVar6,(LPWSTR)0x0,0
                                   );
  if (cchWideChar == 0) goto LAB_4502d9d2;
  if ((((int)cchWideChar < 1) || (0xffffffe0 / cchWideChar < 2)) ||
     (cchWideChar * 2 + 8 <= cchWideChar * 2)) {
    lpWideCharStr = (LPCWSTR)0x0;
  }
  else {
    uVar4 = cchWideChar * 2 + 8;
    if (uVar4 < 0x401) {
      puVar5 = (undefined4 *)&stack0xffffffe8;
      lpWideCharStr = (LPCWSTR)&stack0xffffffe8;
      if (&stack0x00000000 != (undefined1 *)0x18) {
LAB_4502d8af:
        lpWideCharStr = (LPCWSTR)(puVar5 + 2);
      }
    }
    else {
      puVar5 = _malloc(uVar4);
      lpWideCharStr = (LPCWSTR)0x0;
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = 0xdddd;
        goto LAB_4502d8af;
      }
    }
  }
  if (lpWideCharStr == (LPCWSTR)0x0) goto LAB_4502d9d2;
  iVar6 = MultiByteToWideChar(param_8,1,param_4,iVar6,lpWideCharStr,cchWideChar);
  if ((iVar6 != 0) &&
     (uVar4 = FUN_45032635(param_2,param_3,lpWideCharStr,cchWideChar,(LPWSTR)0x0,0), uVar4 != 0)) {
    if ((param_3 & 0x400) == 0) {
      if ((((int)uVar4 < 1) || (0xffffffe0 / uVar4 < 2)) || (uVar4 * 2 + 8 <= uVar4 * 2)) {
        lpWideCharStr_00 = (LPCWSTR)0x0;
LAB_4502d984:
        if (lpWideCharStr_00 != (LPCWSTR)0x0) {
          iVar6 = FUN_45032635(param_2,param_3,lpWideCharStr,cchWideChar,lpWideCharStr_00,uVar4);
          if (iVar6 != 0) {
            if (param_7 == 0) {
              param_7 = 0;
              param_6 = (LPWSTR)0x0;
            }
            WideCharToMultiByte(param_8,0,lpWideCharStr_00,uVar4,(LPSTR)param_6,param_7,(LPCSTR)0x0,
                                (LPBOOL)0x0);
          }
          FUN_45023e0f((int)lpWideCharStr_00);
        }
      }
      else {
        _Size = uVar4 * 2 + 8;
        if (_Size < 0x401) {
          puVar5 = (undefined4 *)&stack0xffffffe8;
          if (&stack0x00000000 != (undefined1 *)0x18) {
LAB_4502d97d:
            lpWideCharStr_00 = (LPCWSTR)(puVar5 + 2);
            goto LAB_4502d984;
          }
        }
        else {
          puVar5 = _malloc(_Size);
          if (puVar5 != (undefined4 *)0x0) {
            *puVar5 = 0xdddd;
            goto LAB_4502d97d;
          }
        }
      }
    }
    else if ((param_7 != 0) && ((int)uVar4 <= param_7)) {
      FUN_45032635(param_2,param_3,lpWideCharStr,cchWideChar,param_6,param_7);
    }
  }
  FUN_45023e0f((int)lpWideCharStr);
LAB_4502d9d2:
  FUN_45022e32(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}


