// Source: CLCiffConversion_Layout.dll @ 4542ac5b; FUN_4542ac5b

int __cdecl FUN_4542ac5b(int param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 0x10);
  uVar2 = uVar4;
  uVar3 = uVar4;
  while (-1 < param_2) {
    if (uVar4 == 0xffffffff) {
      _inconsistency();
    }
    uVar4 = uVar4 - 1;
    if (((*(int *)(uVar4 * 0x14 + 4 + iVar1) < param_3) &&
        (param_3 <= *(int *)(uVar4 * 0x14 + 8 + iVar1))) || (uVar4 == 0xffffffff)) {
      param_2 = param_2 + -1;
      uVar2 = uVar3;
      uVar3 = uVar4;
    }
  }
  uVar4 = uVar4 + 1;
  *param_4 = uVar4;
  *param_5 = uVar2;
  if ((*(uint *)(param_1 + 0xc) < uVar2) || (uVar2 < uVar4)) {
    _inconsistency();
  }
  return uVar4 * 0x14 + iVar1;
}


