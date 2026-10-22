// Source: CiffHelper.dll @ 4081d0dc; FUN_4081d0dc

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_4081d0dc(undefined4 *param_1,wchar_t *param_2)

{
  int iVar1;
  VARIANTARG local_58;
  int local_48;
  wchar_t *local_44;
  int local_40;
  int local_3c;
  wchar_t *local_38;
  int *local_34;
  int *local_30;
  undefined1 local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_34 = (int *)0x0;
  local_44 = param_2;
  local_8 = 0;
  (**(code **)(*(int *)*param_1 + 0x5c))((int *)*param_1,&local_34);
  local_3c = 0;
  (**(code **)(*local_34 + 0x1c))(local_34,&local_3c);
  local_40 = 0;
  if (0 < local_3c) {
    do {
      FUN_40802e76((uint *)&local_58);
      local_40 = local_40 + 1;
      local_8._0_1_ = 1;
      (**(code **)(*local_34 + 0x24))(local_34,local_40,&local_58);
      CComQIPtr<>(&local_30,(undefined4 *)local_58.n1._8_4_);
      local_8._0_1_ = 2;
      (**(code **)(*local_30 + 0x28))(local_30,&local_48);
      if (local_48 == 1) {
        local_38 = (wchar_t *)0x0;
        local_8._0_1_ = 3;
        (**(code **)(*local_30 + 0xe4))(local_30,&local_38);
        basic_string<>(local_2c,local_38);
        iVar1 = FUN_40808f0b(local_2c,local_44);
        if (iVar1 == 0) {
          FUN_4080653d(local_2c,'\x01',0);
          SysFreeString(local_38);
          local_8 = CONCAT31(local_8._1_3_,1);
          if (local_30 != (int *)0x0) {
            (**(code **)(*local_30 + 8))(local_30);
          }
          VariantClear(&local_58);
          break;
        }
        FUN_4080653d(local_2c,'\x01',0);
        SysFreeString(local_38);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))(local_30);
      }
      VariantClear(&local_58);
    } while (local_40 < local_3c);
  }
  local_8 = 0xffffffff;
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
  FUN_4082d4c6();
  return;
}


