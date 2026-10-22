// Source: CLCiffConversion_Layout.dll @ 4540f6a1; FUN_4540f6a1

void __fastcall FUN_4540f6a1(double *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  double local_28;
  double local_20;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_4540f3bd(param_1);
  if (((char)uVar2 != '\0') && (bVar1 = FUN_4540f44f(&local_18,*param_1), bVar1)) {
    FUN_4540f664(&local_28,local_18.wYear,1,1,0,0,0);
    iVar3 = FUN_4540f1a7(&local_28);
    iVar4 = iVar3 + -2;
    if (iVar3 < 5) {
      iVar4 = iVar3 + 5;
    }
    iVar3 = FUN_4540f1f8(param_1,'\x01');
    iVar4 = (iVar3 + iVar4) / 7;
    if (iVar4 == 0) {
      FUN_4540f664(&local_20,local_18.wYear - 1,0xc,0x1f,0,0,0);
      FUN_4540f6a1(&local_20);
    }
    else if (iVar4 == 0x35) {
      FUN_4540f664(&local_20,local_18.wYear + 1,1,1,0,0,0);
      FUN_4540f1a7(&local_20);
    }
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


