// Source: CLCiffConversion_Layout.dll @ 454121e1; FUN_454121e1

void FUN_454121e1(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_45421efd(param_1,param_2);
  if ((undefined4 *)(iVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)(iVar1 + 8) = *param_3;
    *(undefined4 *)(iVar1 + 0xc) = param_3[1];
    *(undefined4 *)(iVar1 + 0x10) = param_3[2];
  }
  return;
}


