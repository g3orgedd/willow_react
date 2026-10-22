// Source: CLCSGraphicBasedField.dll @ 41c0c4ed; FUN_41c0c4ed

int FUN_41c0c4ed(void *self,void *position,VARIANTARG ciffFile,VARIANTARG coderCapabilities,
                VARIANTARG field)

{
  undefined4 *in_stack_00000040;
  int *local_14;
  int *local_10;
  undefined4 local_c;
  int *local_8;
  
  CComQIPtr<>(&local_14,(undefined4 *)coderCapabilities.n1.decVal.Hi32);
  CComQIPtr<>(&local_10,(undefined4 *)field.n1.decVal.Hi32);
  CComQIPtr<>(&local_8,in_stack_00000040);
  FUN_41c11a03(&local_c);
  (**(code **)(*local_8 + 0x84))(local_8,ciffFile.n1._8_4_ - ciffFile.n1._0_4_);
  (**(code **)(*local_8 + 0x7c))(local_8,ciffFile.n1.decVal.Hi32 - (int)position);
  (**(code **)(**(int **)((int)self + 0x54) + 0x40))
            (*(int **)((int)self + 0x54),(undefined1 *)((int)&field.n1 + 0xc),1);
  FUN_41c11a0c(&local_c);
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  return 0;
}


