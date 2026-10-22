// Source: CLCiffConversion_Layout.dll @ 454228de; FUN_454228de

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_454228de(int *param_1,undefined4 *param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  _union_2683 local_24;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x14;
  local_8 = 0x454228ea;
  FUN_45404ce5(param_3,param_1);
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)*param_2 + 0x4c))((int *)*param_2,local_14);
  if ((-1 < iVar2) && (*piVar1 != 0)) {
    FUN_45429f70((uint *)&local_24,0,0x10);
    VariantInit((VARIANTARG *)&local_24.n2);
    piVar1 = (int *)*piVar1;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar3 = (**(code **)(*piVar1 + 0x4c0))(piVar1,local_14[0],&local_24);
    if ((-1 < iVar3) &&
       ((local_24.n2.vt == 9 && ((undefined4 *)local_24._8_4_ != (undefined4 *)0x0)))) {
      CComQIPtr<>(&param_1,(undefined4 *)local_24._8_4_);
      if (param_1 != (int *)0x0) {
        FUN_45404ce5(param_3,(int *)&param_1);
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
    }
    VariantClear((VARIANTARG *)&local_24.n2);
  }
  SysFreeString(local_14[0]);
  return iVar2;
}


