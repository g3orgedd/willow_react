// Source: CLCiffConversion_Data.dll @ 4501dfb7; FUN_4501dfb7

void __fastcall FUN_4501dfb7(double *param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  DOUBLE local_28;
  DOUBLE local_20;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  uVar3 = FUN_4501dc99(param_1);
  if (((char)uVar3 != '\0') && (bVar1 = FUN_4501dd59(&local_18,*param_1), bVar1)) {
    cVar2 = FUN_4501dcf2(&local_28,local_18.wYear,1,1,0,0,0);
    if (cVar2 == '\0') {
      local_28 = DAT_4503d998;
    }
    iVar4 = FUN_4501d4fe(&local_28);
    iVar5 = iVar4 + -2;
    if (iVar4 < 5) {
      iVar5 = iVar4 + 5;
    }
    iVar4 = FUN_4501d54f(param_1,'\x01');
    iVar5 = (iVar4 + iVar5) / 7;
    if (iVar5 == 0) {
      cVar2 = FUN_4501dcf2(&local_20,local_18.wYear - 1,0xc,0x1f,0,0,0);
      if (cVar2 == '\0') {
        local_20 = DAT_4503d998;
      }
      FUN_4501dfb7(&local_20);
    }
    else if (iVar5 == 0x35) {
      cVar2 = FUN_4501dcf2(&local_20,local_18.wYear + 1,1,1,0,0,0);
      if (cVar2 == '\0') {
        local_20 = DAT_4503d998;
      }
      FUN_4501d4fe(&local_20);
    }
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


