// Source: CiffHelper.dll @ 4082ed0c; FUN_4082ed0c

int __cdecl FUN_4082ed0c(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  ushort uVar4;
  
  if (DAT_40866a64 != 0) {
    iVar3 = FUN_4082ed9f(param_1,param_2,(int *)0x0);
    return iVar3;
  }
  if ((param_1 != (ushort *)0x0) && (param_2 != (ushort *)0x0)) {
    iVar3 = (int)param_1 - (int)param_2;
    do {
      uVar4 = *(ushort *)(iVar3 + (int)param_2);
      if ((0x40 < uVar4) && (uVar4 < 0x5b)) {
        uVar4 = uVar4 + 0x20;
      }
      uVar1 = *param_2;
      if ((0x40 < uVar1) && (uVar1 < 0x5b)) {
        uVar1 = uVar1 + 0x20;
      }
      param_2 = param_2 + 1;
    } while ((uVar4 != 0) && (uVar4 == uVar1));
    return (uint)uVar4 - (uint)uVar1;
  }
  piVar2 = __errno();
  *piVar2 = 0x16;
  FUN_40832c27();
  return 0x7fffffff;
}


