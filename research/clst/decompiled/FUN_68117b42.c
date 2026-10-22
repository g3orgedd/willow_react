// CiffMgr.dll entry=68117b42

ushort FUN_68117b42(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == (ushort *)0x0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_68117f20((uint)param_1[1]);
    iVar3 = FUN_68117f20((uint)*param_1);
    iVar4 = FUN_68117f20((uint)param_1[2]);
    uVar1 = (ushort)iVar4 | ((ushort)iVar2 | (short)iVar3 << 6) << 5;
  }
  return uVar1;
}


