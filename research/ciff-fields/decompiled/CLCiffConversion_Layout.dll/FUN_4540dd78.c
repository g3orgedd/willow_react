// Source: CLCiffConversion_Layout.dll @ 4540dd78; FUN_4540dd78

int FUN_4540dd78(int param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = param_2;
  if ((*(ushort *)(param_1 + 0x80) == param_2) && (param_2 != 0)) {
    iVar3 = *(int *)(param_1 + 0x84) * 0x14 + *(int *)(param_1 + 0x74);
  }
  else {
    iVar3 = *(ushort *)(param_1 + 0x4c) - 1;
    _param_2 = 0;
    if (-1 < iVar3) {
      do {
        iVar4 = (_param_2 + iVar3) / 2;
        uVar1 = *(ushort *)(iVar4 * 0x14 + *(int *)(param_1 + 0x74));
        if (uVar1 == uVar2) {
          *(int *)(param_1 + 0x84) = iVar4;
          *(ushort *)(param_1 + 0x80) = uVar2;
          return iVar4 * 0x14 + *(int *)(param_1 + 0x74);
        }
        if (uVar2 < uVar1) {
          iVar3 = iVar4 + -1;
        }
        else {
          _param_2 = iVar4 + 1;
        }
      } while (_param_2 <= iVar3);
    }
    iVar3 = 0;
  }
  return iVar3;
}


