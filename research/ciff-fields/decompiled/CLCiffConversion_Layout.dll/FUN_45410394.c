// Source: CLCiffConversion_Layout.dll @ 45410394; FUN_45410394

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_45410394(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auVar3 [10];
  wchar_t local_30 [20];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  auVar3 = FUN_4542e330(param_1,(int)DAT_45449248,(int)((ulonglong)DAT_45449248 >> 0x20),
                        SUB84((double)*(int *)((int)param_1 + 0x158),0),
                        (uint)((ulonglong)(double)*(int *)((int)param_1 + 0x158) >> 0x20));
  iVar2 = *(int *)((int)param_1 + 0x154);
  if ((int)((double)(float)(float10)auVar3 + _DAT_45447a28) != 0) {
    iVar2 = iVar2 % (int)((double)(float)(float10)auVar3 + _DAT_45447a28);
  }
  iVar1 = *(int *)((int)param_1 + 0xf8);
  if (iVar1 == 1) {
LAB_4541043f:
    _swprintf_s(local_30,0x14,L"%lu");
  }
  else if (iVar1 == 2) {
LAB_45410422:
    _swprintf_s(local_30,0x14,L"%0*lu",*(undefined4 *)((int)param_1 + 0x158));
  }
  else {
    if (iVar1 == 3) goto LAB_4541043f;
    if (iVar1 == 4) {
      if (iVar2 == 0) {
        FUN_45411e95((int)param_1);
        goto LAB_4541045d;
      }
      goto LAB_45410422;
    }
  }
  FUN_45410ae6(param_1,local_30);
LAB_4541045d:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


