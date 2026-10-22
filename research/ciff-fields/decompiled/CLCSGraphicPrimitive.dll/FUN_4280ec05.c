// Source: CLCSGraphicPrimitive.dll @ 4280ec05; FUN_4280ec05

/* WARNING: Type propagation algorithm not settling */

int FUN_4280ec05(void *self,void *position,VARIANTARG ciffFile,VARIANTARG coderCapabilities,
                VARIANTARG field)

{
  int iVar1;
  undefined4 *in_stack_00000040;
  int *local_20;
  undefined4 local_1c;
  int local_18 [2];
  int *local_10;
  int *local_c;
  int *local_8;
  
  CComQIPtr<>(&local_20,(undefined4 *)coderCapabilities.n1.decVal.Hi32);
  CComQIPtr<>(&local_10,(undefined4 *)field.n1.decVal.Hi32);
  local_c = (int *)0x0;
  FUN_4280d99d(&local_10,(int *)&local_c);
  CComQIPtr<>(&local_8,in_stack_00000040);
  FUN_4280fd96(&local_1c);
  iVar1 = ciffFile.n1._8_4_ - ciffFile.n1._0_4_;
  FUN_428071a4(0x4282d350);
  FUN_428071a4(0x4282d3a0);
  local_18[1] = 0;
  (**(code **)(*local_8 + 0xd4))(local_8,local_18 + 1);
  (**(code **)(*local_8 + 0xcc))(local_8,local_18);
  (**(code **)(*local_8 + 0x84))(local_8,iVar1);
  (**(code **)(*local_8 + 0x7c))(local_8,ciffFile.n1.decVal.Hi32 - (int)position);
  (**(code **)(*local_8 + 0xb4))(local_8,iVar1);
  (**(code **)(*local_8 + 0xac))(local_8,ciffFile.n1.decVal.Hi32 - (int)position);
  if (local_18[0] == 0) {
    (**(code **)(*local_8 + 0xd8))(local_8,iVar1);
  }
  FUN_4280fd9f(&local_1c);
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  return 0;
}


