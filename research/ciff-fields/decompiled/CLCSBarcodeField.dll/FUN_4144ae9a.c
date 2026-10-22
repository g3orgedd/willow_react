// Source: CLCSBarcodeField.dll @ 4144ae9a; FUN_4144ae9a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_4144ae9a(void *this,HDC param_1,undefined4 *param_2,int *param_3,int param_4)

{
  int iVar1;
  UINT UVar2;
  VARIANTARG local_2c;
  int *local_1c;
  int *local_18;
  float local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x4144aea6;
  if ((param_2 == (undefined4 *)0x0) || (param_3 == (int *)0x0)) {
    iVar1 = -0x7fffbffd;
  }
  else {
    CComQIPtr<>(&param_3,param_3);
    local_8 = 0;
    if (param_3 == (int *)0x0) {
      iVar1 = -0x7ff8ffa9;
    }
    else {
      CComQIPtr<>(&local_1c,param_2);
      FUN_41460bf0((uint *)&local_2c,0,0x10);
      VariantInit(&local_2c);
      local_8._0_1_ = 2;
      (**(code **)(*local_1c + 0x24))(local_1c,1,&local_2c);
      CComQIPtr<>(&local_18,(undefined4 *)local_2c.n1._8_4_);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (local_18 == (int *)0x0) {
        FUN_41407deb(0x41484758);
        iVar1 = -0x7fffbffb;
      }
      else {
        (**(code **)(*local_18 + 100))(local_18,(int)this + 0xdc);
        (**(code **)(*local_18 + 0x5c))(local_18,(int)this + 0xd8);
        (**(code **)(**(int **)((int)this + 0xfc) + 0x2c))(*(int **)((int)this + 0xfc),local_14);
        *(int *)((int)this + 0xa4) = (int)((double)(local_14[0] * _DAT_41481060) + _DAT_41481058);
        (**(code **)(**(int **)((int)this + 0xfc) + 0x34))(*(int **)((int)this + 0xfc),local_14);
        *(int *)((int)this + 0xa8) = (int)((double)(local_14[0] * _DAT_41481060) + _DAT_41481058);
        FUN_41407deb(0x41484790);
        iVar1 = FUN_4144a25e(this,param_3,param_4);
        if (iVar1 == 0) {
          iVar1 = FUN_4144b0a9(this,param_1);
          if ((-1 < iVar1) && (UVar2 = SysStringLen(*(BSTR *)((int)this + 0x74)), UVar2 != 0)) {
            iVar1 = 0x4022a;
          }
          FUN_41423c25(0x414847d0);
        }
      }
      local_8._0_1_ = 2;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      VariantClear(&local_2c);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
    local_8 = 0xffffffff;
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 8))(param_3);
    }
  }
  return iVar1;
}


