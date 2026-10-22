// Source: CLCSSmallBarcode.dll @ 420450b4; FUN_420450b4

int FUN_420450b4(void *self,void *position,VARIANTARG ciffFile,VARIANTARG coderCapabilities,
                VARIANTARG field)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_stack_00000040;
  undefined4 local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  void *local_18;
  undefined4 uStack_14;
  ULONG UStack_10;
  undefined4 uStack_c;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  local_18 = position;
  uStack_14 = ciffFile.n1._0_4_;
  UStack_10 = ciffFile.n1.decVal.Hi32;
  uStack_c = ciffFile.n1._8_4_;
  CComQIPtr<>(&local_24,(undefined4 *)coderCapabilities.n1.decVal.Hi32);
  CComQIPtr<>(&local_20,(undefined4 *)field.n1.decVal.Hi32);
  CComQIPtr<>(&local_1c,in_stack_00000040);
  (**(code **)(*local_1c + 0xa8))(local_1c,&local_28);
  piVar1 = (int *)FUN_42044d95(self,local_28);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(&local_18,&local_24,&local_20,&local_1c);
  }
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  iVar2 = FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return iVar2;
}


