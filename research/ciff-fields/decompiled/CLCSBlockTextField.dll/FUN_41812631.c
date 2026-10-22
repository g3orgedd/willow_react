// Source: CLCSBlockTextField.dll @ 41812631; FUN_41812631

int FUN_41812631(void *self,void *position,VARIANTARG ciffFile,VARIANTARG coderCapabilities,
                VARIANTARG field)

{
  int *piVar1;
  undefined4 *in_stack_00000040;
  int *local_10;
  int *local_c;
  int *local_8;
  
  CComQIPtr<>(&local_8,in_stack_00000040);
  CComQIPtr<>(&local_10,(undefined4 *)field.n1.decVal.Hi32);
  local_c = (int *)0x0;
  FUN_41807b54(&local_10,(int *)&local_c);
  (**(code **)(*local_8 + 0x84))(local_8,ciffFile.n1._8_4_ - ciffFile.n1._0_4_);
  (**(code **)(*local_8 + 0x7c))(local_8,ciffFile.n1.decVal.Hi32 - (int)position);
  FUN_41801928(0x41836d58);
  (**(code **)(*local_8 + 0xd8))(local_8,ciffFile.n1.decVal.Hi32 - (int)position);
  (**(code **)(*local_8 + 0xe0))(local_8,ciffFile.n1._8_4_ - ciffFile.n1._0_4_);
  piVar1 = local_8;
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 4))(local_8);
  }
  (**(code **)(*local_8 + 0xe8))(local_8,*(undefined4 *)((int)self + 0x88));
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return 0;
}


