// Source: CLCiffConversion_Layout.dll @ 4540db7d; FUN_4540db7d

uint FUN_4540db7d(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = *param_1;
  do {
    if (uVar1 == 0xa007) {
      return iVar2 + 5U & 0xfffffffc;
    }
    if (uVar1 == 0xa001) {
LAB_4540dbe0:
      iVar2 = iVar2 + 4;
      param_1 = param_1 + 2;
    }
    else {
      if (uVar1 == 0xa002) {
        iVar2 = iVar2 + 2;
        param_1 = param_1 + 1;
        goto LAB_4540dbe6;
      }
      if (uVar1 == 0xa003) goto LAB_4540dbe0;
      if (uVar1 < 0xa004) {
LAB_4540dbd0:
        param_1 = param_1 + 1;
        iVar2 = iVar2 + 2;
      }
      else if (uVar1 < 0xa006) {
        iVar2 = iVar2 + 6;
        param_1 = param_1 + 3;
      }
      else {
        if (uVar1 != 0xa006) goto LAB_4540dbd0;
        iVar2 = iVar2 + 8;
        param_1 = param_1 + 4;
      }
    }
LAB_4540dbe6:
    uVar1 = *param_1;
  } while( true );
}


