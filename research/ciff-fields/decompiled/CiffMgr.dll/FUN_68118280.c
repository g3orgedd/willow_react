// Source: CiffMgr.dll @ 68118280; FUN_68118280

int FUN_68118280(int *param_1,int *param_2)

{
  UINT UVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  UVar1 = SysStringLen((BSTR)*param_1);
  if (UVar1 == 8) {
    iVar4 = 0;
    do {
      if (iVar5 < 0) {
        return iVar5;
      }
      *param_2 = *param_2 << 4;
      uVar2 = (uint)*(ushort *)(iVar4 + *param_1);
      if ((uVar2 < 0x30) || (0x39 < uVar2)) {
        if ((0x40 < uVar2) && (uVar2 < 0x47)) {
          iVar3 = uVar2 - 0x37;
          goto LAB_681182d7;
        }
        if ((0x60 < uVar2) && (uVar2 < 0x67)) {
          iVar3 = uVar2 - 0x57;
          goto LAB_681182d7;
        }
        iVar5 = -0x7ffbfdbf;
      }
      else {
        iVar3 = uVar2 - 0x30;
LAB_681182d7:
        *param_2 = iVar3 + *param_2;
      }
      iVar4 = iVar4 + 2;
    } while (iVar4 < 0x10);
  }
  else {
    iVar5 = -0x7ffbfdbf;
  }
  return iVar5;
}


