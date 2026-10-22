// Source: CLCiffConversion_Data.dll @ 45032439; FUN_45032439

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __cdecl
FUN_45032439(int *param_1,DWORD param_2,LPCSTR param_3,int param_4,LPWORD param_5,UINT param_6,
            int param_7)

{
  uint _Size;
  uint uVar1;
  uint cchWideChar;
  undefined4 *puVar2;
  int cchSrc;
  LPCWSTR lpWideCharStr;
  
  uVar1 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if (param_6 == 0) {
    param_6 = *(UINT *)(*param_1 + 4);
  }
  cchWideChar = MultiByteToWideChar(param_6,(uint)(param_7 != 0) * 8 + 1,param_3,param_4,(LPWSTR)0x0
                                    ,0);
  if (cchWideChar == 0) goto LAB_4503251d;
  if ((((int)cchWideChar < 1) || (0x7ffffff0 < cchWideChar)) ||
     (cchWideChar * 2 + 8 <= cchWideChar * 2)) {
    lpWideCharStr = (LPCWSTR)0x0;
  }
  else {
    _Size = cchWideChar * 2 + 8;
    if (_Size < 0x401) {
      puVar2 = (undefined4 *)&stack0xffffffec;
      if (&stack0x00000000 == (undefined1 *)0x14) goto LAB_4503251d;
    }
    else {
      puVar2 = _malloc(_Size);
      if (puVar2 == (undefined4 *)0x0) goto LAB_4503251d;
      *puVar2 = 0xdddd;
    }
    lpWideCharStr = (LPCWSTR)(puVar2 + 2);
  }
  if (lpWideCharStr != (LPCWSTR)0x0) {
    FUN_45021c10((uint *)lpWideCharStr,0,cchWideChar * 2);
    cchSrc = MultiByteToWideChar(param_6,1,param_3,param_4,lpWideCharStr,cchWideChar);
    if (cchSrc != 0) {
      GetStringTypeW(param_2,lpWideCharStr,cchSrc,param_5);
    }
    FUN_45023e0f((int)lpWideCharStr);
  }
LAB_4503251d:
  FUN_45022e32(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}


