// Source: CLCSGraphicPrimitive.dll @ 4280efdb; FUN_4280efdb

int FUN_4280efdb(void *self,VARIANTARG field,VARIANTARG ciffFile)

{
  int *local_10;
  int *local_c;
  BSTR local_8;
  
  if (field.n1.decVal.Hi32 != 0) {
    (**(code **)(*(int *)field.n1.decVal.Hi32 + 4))(field.n1.decVal.Hi32);
  }
  local_c = (int *)0x0;
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x5c))(field.n1.decVal.Hi32,&local_c);
  CComQIPtr<>(&local_10,(undefined4 *)ciffFile.n1.decVal.Hi32);
  local_8 = (BSTR)0x0;
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x68))(field.n1.decVal.Hi32,&local_8);
  SysFreeString(local_8);
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 8))(field.n1.decVal.Hi32);
  return 0;
}


