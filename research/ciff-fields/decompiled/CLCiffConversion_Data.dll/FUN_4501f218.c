// Source: CLCiffConversion_Data.dll @ 4501f218; FUN_4501f218

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_4501f218(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auVar3 [10];
  wchar_t local_30 [20];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  auVar3 = FUN_450261d0(param_1,(int)DAT_450416e0,(int)((ulonglong)DAT_450416e0 >> 0x20),
                        SUB84((double)*(int *)((int)param_1 + 0x158),0),
                        (uint)((ulonglong)(double)*(int *)((int)param_1 + 0x158) >> 0x20));
  iVar2 = *(int *)((int)param_1 + 0x154);
  if ((int)((double)(float)(float10)auVar3 + _DAT_450416d8) != 0) {
    iVar2 = iVar2 % (int)((double)(float)(float10)auVar3 + _DAT_450416d8);
  }
  iVar1 = *(int *)((int)param_1 + 0xf8);
  if (iVar1 == 1) {
LAB_4501f2c3:
    _swprintf_s(local_30,0x14,L"%lu");
  }
  else if (iVar1 == 2) {
LAB_4501f2a6:
    _swprintf_s(local_30,0x14,L"%0*lu",*(undefined4 *)((int)param_1 + 0x158));
  }
  else {
    if (iVar1 == 3) goto LAB_4501f2c3;
    if (iVar1 == 4) {
      if (iVar2 == 0) {
        FUN_45020907((int)param_1);
        goto LAB_4501f2e1;
      }
      goto LAB_4501f2a6;
    }
  }
  FUN_4501f984(param_1,local_30);
LAB_4501f2e1:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


