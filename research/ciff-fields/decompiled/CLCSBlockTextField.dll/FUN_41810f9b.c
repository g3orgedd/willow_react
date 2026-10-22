// Source: CLCSBlockTextField.dll @ 41810f9b; FUN_41810f9b

int FUN_41810f9b(void *self,void *outSize,VARIANTARG field,VARIANTARG coderCapabilities,
                VARIANTARG ciffFile)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  iVar3 = -0x7fffbffd;
  CComQIPtr<>(&local_10,(undefined4 *)ciffFile.n1._8_4_);
  pvVar1 = outSize;
  if (local_10 != (int *)0x0) {
    if (outSize != (void *)0x0) {
      (**(code **)(*local_10 + 0x54))(local_10,&local_24);
      CComQIPtr<>(&local_20,(undefined4 *)coderCapabilities.n1._8_4_);
      local_c = (int *)0x0;
      FUN_41807b54(&local_20,(int *)&local_c);
      CComQIPtr<>(&outSize,(undefined4 *)field.n1._8_4_);
      piVar2 = local_c;
      if (outSize != (void *)0x0) {
        (**(code **)(*(int *)outSize + 0x78))(outSize,&local_8);
        (**(code **)(*(int *)outSize + 0x80))(outSize,&local_c);
        if (local_24 == 0) {
          FUN_41801366(&local_28);
          piVar4 = piVar2;
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 4))(piVar2);
          }
          local_8 = FUN_41801e6e(local_8,1.4013e-45,piVar4);
          piVar4 = piVar2;
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 4))(piVar2);
          }
          local_c = (int *)FUN_41801e6e((int)local_c,0.0,piVar4);
          FUN_418015e5(&local_28);
        }
        local_14 = 0;
        *(int *)pvVar1 = local_8;
        *(int **)((int)pvVar1 + 4) = local_c;
        (**(code **)(*(int *)outSize + 0xb0))(outSize,&local_14);
        local_18 = 1;
        CComQIPtr<>(&local_1c,outSize);
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 0x168))(local_1c,&local_18);
        }
        iVar3 = local_14 / local_18;
        if (3 < iVar3) {
          iVar3 = 4;
        }
        iVar3 = (**(code **)(*(int *)outSize + 0xf0))(outSize,iVar3);
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        if (outSize != (void *)0x0) {
          (**(code **)(*(int *)outSize + 8))(outSize);
        }
      }
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
    }
    if (local_10 != (int *)0x0) {
      (**(code **)(*local_10 + 8))(local_10);
    }
  }
  return iVar3;
}


