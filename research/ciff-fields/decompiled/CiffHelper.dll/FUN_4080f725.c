// Source: CiffHelper.dll @ 4080f725; FUN_4080f725

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4080f725(void *this,BSTR param_1,int param_2)

{
  VARIANTARG local_28;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_18 = 0;
  if (*(int *)((int)this + 0x20) != 0) {
    local_8 = 0;
    FUN_40802e76((uint *)&local_28);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_4080f4e9(this,param_1,(int)&local_28,1,param_2);
    VariantClear(&local_28);
    FUN_4080f776();
    return;
  }
  return;
}


