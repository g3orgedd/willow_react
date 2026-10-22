// Source: CLCiffConversion_Layout.dll @ 45407a52; FUN_45407a52

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x45407ba3) */

void __fastcall FUN_45407a52(void *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int **this;
  undefined4 *puVar4;
  BSTR bstrString;
  int local_2c;
  void *local_28;
  int *local_24;
  int *local_20;
  BSTR local_1c;
  void *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x45407a5e;
  local_18 = param_1;
  piVar1 = (int *)FUN_45407964(&local_28);
  local_8 = 0;
  puVar4 = (undefined4 *)((int)param_1 + 8);
  FUN_454077ad(puVar4,piVar1);
  local_8 = 0xffffffff;
  FUN_45402c5d((int *)&local_28);
  local_28 = (void *)((int)param_1 + 0x10);
  FUN_454083a8(local_28,(int *)&local_24,puVar4);
  piVar1 = local_24;
  if (local_24 != *(int **)((int)param_1 + 0x10)) goto LAB_45407bd2;
  local_24 = (int *)0x0;
  FUN_454028b9(&local_1c,(char *)*puVar4);
  bstrString = local_1c;
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar2 = (**(code **)(**(int **)((int)param_1 + 0xc) + 0x1c))
                    (*(int **)((int)param_1 + 0xc),local_1c,3,local_14);
  if (iVar2 < 0) {
    piVar3 = FUN_4540791f(&local_2c);
    local_8._0_1_ = 3;
    FUN_454077ad(puVar4,piVar3);
    local_8._0_1_ = 2;
    FUN_45402c5d(&local_2c);
    FUN_45402c99(&local_1c,(char *)*puVar4);
    iVar2 = (**(code **)(**(int **)((int)local_18 + 0xc) + 0x1c))
                      (*(int **)((int)local_18 + 0xc),local_1c,3,local_14);
    bstrString = local_1c;
    if (-1 < iVar2) {
      FUN_45407be9(puVar4);
      goto LAB_45407b3a;
    }
  }
  else {
LAB_45407b3a:
    if (local_14[0] != (int *)0x0) {
      iVar2 = (**(code **)*local_14[0])(local_14[0],&DAT_45448014,&local_24);
      piVar3 = local_24;
      if (-1 < iVar2) {
        piVar1 = (int *)((int)local_18 + 8);
        local_8 = CONCAT31(local_8._1_3_,4);
        local_20 = local_24;
        this = (int **)FUN_4540784b(local_28,piVar1);
        if (this != &local_20) {
          FUN_45404ce5(this,(int *)&local_20);
        }
        puVar4 = (undefined4 *)FUN_454083a8(local_28,&local_2c,piVar1);
        piVar1 = (int *)*puVar4;
        if (piVar3 != (int *)0x0) {
          local_20 = (int *)0x0;
          (**(code **)(*piVar3 + 8))(piVar3);
        }
        local_8._0_1_ = 2;
      }
      FUN_45402cd0(local_18,PTR_s_No_Translation_Found_4545d124);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  SysFreeString(bstrString);
  param_1 = local_18;
LAB_45407bd2:
  if (piVar1 != *(int **)((int)param_1 + 0x10)) {
    FUN_45404ce5((void *)((int)param_1 + 0x18),piVar1 + 5);
  }
  return;
}


