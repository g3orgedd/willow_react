// Source: CiffMgr.dll @ 6810fb17; FUN_6810fb17

int FUN_6810fb17(int param_1,VARIANTARG *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  BSTR pOVar4;
  _union_2683 local_58;
  _union_2683 local_48;
  VARIANTARG local_38;
  LPCRITICAL_SECTION local_28;
  undefined4 local_24;
  BSTR local_20;
  undefined4 local_1c;
  OLECHAR *local_18;
  int *local_14;
  int *local_10;
  BSTR local_c;
  int *local_8;
  
  if (param_2 == (VARIANTARG *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    local_10 = (int *)0x0;
    iVar2 = FUN_6810f59c(&local_10);
    if (-1 < iVar2) {
      puVar3 = FUN_6810210e(&local_20,L"Temp");
      piVar1 = local_10;
      FUN_6810fec0(local_10,(OLECHAR *)*puVar3);
      SysFreeString(local_20);
      local_58._8_4_ = piVar1;
      local_58.n2.vt = 9;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      local_28 = (LPCRITICAL_SECTION)(param_1 + 0x30);
      EnterCriticalSection(local_28);
      for (pOVar4 = *(BSTR *)(param_1 + 4); local_20 = pOVar4, pOVar4 < *(BSTR *)(param_1 + 8);
          pOVar4 = pOVar4 + 8) {
        CComQIPtr<>(&local_8,*(undefined4 **)(pOVar4 + 4));
        if (local_8 != (int *)0x0) {
          local_c = (BSTR)0x0;
          iVar2 = FUN_6810fd12(&local_c);
          if (-1 < iVar2) {
            local_18 = (OLECHAR *)0x0;
            (**(code **)(*local_8 + 0x1c))(local_8,&local_18);
            (**(code **)(*local_8 + 0x24))(local_8,&local_24);
            FUN_68132710((uint *)&local_38,0,0x10);
            VariantInit(&local_38);
            iVar2 = (**(code **)(*local_8 + 0x2c))(local_8,&local_38);
            pOVar4 = local_c;
            FUN_6810f09d(local_c,local_18,local_24);
            CComQIPtr<>(&local_14,local_8);
            if (local_14 != (int *)0x0) {
              local_c = (BSTR)0x0;
              iVar2 = (**(code **)(*local_14 + 0x3c))(local_14,&local_c);
              if (-1 < iVar2) {
                (**(code **)(*(int *)pOVar4 + 0x40))(pOVar4,local_c);
              }
              local_1c = 0;
              iVar2 = (**(code **)(*local_14 + 0x34))(local_14,&local_1c);
              if (-1 < iVar2) {
                iVar2 = (**(code **)(*(int *)pOVar4 + 0x38))(pOVar4,local_1c);
              }
              SysFreeString(local_c);
            }
            local_48._8_4_ = pOVar4;
            local_48.n2.vt = 9;
            if (pOVar4 != (BSTR)0x0) {
              (**(code **)(*(int *)pOVar4 + 4))(pOVar4);
            }
            FUN_68104866(local_10 + 1,(VARIANTARG *)&local_48.n2);
            VariantClear((VARIANTARG *)&local_48.n2);
            if (local_14 != (int *)0x0) {
              (**(code **)(*local_14 + 8))(local_14);
            }
            VariantClear(&local_38);
            SysFreeString(local_18);
            pOVar4 = local_20;
          }
          if (local_8 != (int *)0x0) {
            (**(code **)(*local_8 + 8))(local_8);
          }
        }
      }
      LeaveCriticalSection(local_28);
      FUN_6810408a(&local_58,param_2);
      VariantClear((VARIANTARG *)&local_58.n2);
    }
  }
  return iVar2;
}


