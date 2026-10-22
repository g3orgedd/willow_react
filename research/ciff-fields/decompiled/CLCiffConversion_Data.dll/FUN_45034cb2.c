// Source: CLCiffConversion_Data.dll @ 45034cb2; __87except

/* Library Function - Single Match
    __87except
   
   Library: Visual Studio 2019 Release */

void __cdecl __87except(int param_1,int *param_2,ushort *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  uint local_94;
  uint local_90 [12];
  undefined8 local_60;
  uint local_50;
  uint local_14;
  
  local_14 = DAT_450518d0 ^ (uint)&stack0xfffffff0;
  local_94 = (uint)*param_3;
  iVar2 = *param_2;
  if (iVar2 == 1) {
LAB_45034d18:
    uVar3 = 8;
  }
  else if (iVar2 == 2) {
    uVar3 = 4;
  }
  else if (iVar2 == 3) {
    uVar3 = 0x11;
  }
  else if (iVar2 == 4) {
    uVar3 = 0x12;
  }
  else {
    if (iVar2 == 5) goto LAB_45034d18;
    if (iVar2 == 7) {
      *param_2 = 1;
      goto LAB_45034d7a;
    }
    if (iVar2 != 8) goto LAB_45034d7a;
    uVar3 = 0x10;
  }
  bVar1 = __handle_exc(uVar3,(double *)(param_2 + 6),local_94);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
      local_60 = *(undefined8 *)(param_2 + 4);
      local_50 = local_50 & 0xffffffe3 | 3;
    }
    else {
      local_50 = local_50 & 0xfffffffe;
    }
    __raise_exc(local_90,&local_94,uVar3,param_1,(uint *)(param_2 + 2),(uint *)(param_2 + 6));
  }
LAB_45034d7a:
  __ctrlfp();
  if (((*param_2 == 8) || (DAT_45052880 != 0)) || (iVar2 = FUN_4500ffc2(), iVar2 == 0)) {
    __set_errno_from_matherr(*param_2);
  }
  FUN_45022e32(local_14 ^ (uint)&stack0xfffffff0);
  return;
}


