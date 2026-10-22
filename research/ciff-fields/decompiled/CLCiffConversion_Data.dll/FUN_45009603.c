// Source: CLCiffConversion_Data.dll @ 45009603; FUN_45009603

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_45009603(int *param_1,undefined4 *param_2,VARIANTARG *param_3)

{
  int iVar1;
  _union_2683 local_2c;
  uint local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_18 = (int *)0x0;
  local_8 = 0;
  iVar1 = FUN_450096e0(param_1,&DAT_4505386c,&local_18,'\0');
  if ((iVar1 < 0) || (local_18 == (int *)0x0)) {
    iVar1 = -0x7fffbffb;
  }
  else {
    FUN_45001f8d((uint *)&local_2c);
    local_8._0_1_ = 1;
    iVar1 = (**(code **)(*local_18 + 0x30))(local_18,*param_2,&local_2c);
    if ((-1 < iVar1) && (local_2c.n2.vt == 9)) {
      CComQIPtr<>(local_14,(undefined4 *)local_2c._8_4_);
      local_8._0_1_ = 2;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 0x24))(local_14[0],&local_1c);
        if (local_1c < 4) {
          (**(code **)(*local_14[0] + 0x2c))(local_14[0]);
        }
        else {
          VariantClear(param_3);
        }
      }
      local_8._0_1_ = 1;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    VariantClear((VARIANTARG *)&local_2c.n2);
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return iVar1;
}


