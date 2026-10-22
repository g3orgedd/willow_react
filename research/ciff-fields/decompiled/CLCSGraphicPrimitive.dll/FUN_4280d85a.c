// Source: CLCSGraphicPrimitive.dll @ 4280d85a; FUN_4280d85a

int FUN_4280d85a(void *self,void *outSize,VARIANTARG field,VARIANTARG coderCapabilities,
                VARIANTARG ciffFile)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  CComQIPtr<>(&local_20,(undefined4 *)field.n1._8_4_);
  local_10 = (int *)0x0;
  FUN_4280d99d(&local_20,(int *)&local_10);
  piVar1 = local_10;
  (**(code **)(*local_10 + 0x78))(local_10,&local_8);
  (**(code **)(*piVar1 + 0x80))(piVar1,&local_c);
  (**(code **)(*piVar1 + 0xd4))(piVar1,&local_14);
  CComQIPtr<>(&local_1c,(undefined4 *)ciffFile.n1._8_4_);
  (**(code **)(*local_1c + 0x54))(local_1c,&local_24);
  if (local_24 == 0) {
    CComQIPtr<>(&local_18,(undefined4 *)coderCapabilities.n1._8_4_);
    local_10 = (int *)0x0;
    FUN_4280d99d(&local_18,(int *)&local_10);
    FUN_4280fd96(&local_28);
    piVar2 = local_10;
    piVar3 = local_10;
    if (local_10 != (int *)0x0) {
      (**(code **)(*local_10 + 4))(local_10);
    }
    local_8 = FUN_4280fe46(local_8,1.4013e-45,piVar3);
    piVar3 = piVar2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    local_c = FUN_4280fe46(local_c,0.0,piVar3);
    piVar3 = piVar2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    local_14 = FUN_4280fe46(local_14,0.0,piVar3);
    FUN_4280fd9f(&local_28);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  *(int *)outSize = local_8;
  *(int *)((int)outSize + 4) = local_c;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  (**(code **)(*piVar1 + 8))(piVar1);
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  return 0;
}


