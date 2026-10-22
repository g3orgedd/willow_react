// Source: CLCiffConversion_Data.dll @ 45008d2c; FUN_45008d2c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x45008e7d) */

void __fastcall FUN_45008d2c(void *param_1)

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
  local_8 = 0x45008d38;
  local_18 = param_1;
  piVar1 = (int *)FUN_45008c07(&local_28);
  local_8 = 0;
  puVar4 = (undefined4 *)((int)param_1 + 8);
  FUN_45008a06(puVar4,piVar1);
  local_8 = 0xffffffff;
  FUN_45002256((int *)&local_28);
  local_28 = (void *)((int)param_1 + 0x10);
  FUN_45009355(local_28,(int *)&local_24,puVar4);
  piVar1 = local_24;
  if (local_24 != *(int **)((int)param_1 + 0x10)) goto LAB_45008eac;
  local_24 = (int *)0x0;
  FUN_45001f5d(&local_1c,(OLECHAR *)*puVar4);
  bstrString = local_1c;
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar2 = (**(code **)(**(int **)((int)param_1 + 0xc) + 0x1c))
                    (*(int **)((int)param_1 + 0xc),local_1c,3,local_14);
  if (iVar2 < 0) {
    piVar3 = FUN_45008beb(&local_2c);
    local_8._0_1_ = 3;
    FUN_45008a06(puVar4,piVar3);
    local_8._0_1_ = 2;
    FUN_45002256(&local_2c);
    FUN_45002326(&local_1c,(OLECHAR *)*puVar4);
    iVar2 = (**(code **)(**(int **)((int)local_18 + 0xc) + 0x1c))
                      (*(int **)((int)local_18 + 0xc),local_1c,3,local_14);
    bstrString = local_1c;
    if (-1 < iVar2) {
      FUN_45008ec3(puVar4);
      goto LAB_45008e14;
    }
  }
  else {
LAB_45008e14:
    if (local_14[0] != (int *)0x0) {
      iVar2 = (**(code **)*local_14[0])(local_14[0],&DAT_4503ddcc,&local_24);
      piVar3 = local_24;
      if (-1 < iVar2) {
        piVar1 = (int *)((int)local_18 + 8);
        local_8 = CONCAT31(local_8._1_3_,4);
        local_20 = local_24;
        this = (int **)FUN_45008ab7(local_28,piVar1);
        if (this != &local_20) {
          FUN_450022ba(this,(int *)&local_20);
        }
        puVar4 = (undefined4 *)FUN_45009355(local_28,&local_2c,piVar1);
        piVar1 = (int *)*puVar4;
        if (piVar3 != (int *)0x0) {
          local_20 = (int *)0x0;
          (**(code **)(*piVar3 + 8))(piVar3);
        }
        local_8._0_1_ = 2;
      }
      FUN_45002365(local_18,(LPCWSTR)PTR_u_No_Translation_Found_45051024);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  SysFreeString(bstrString);
  param_1 = local_18;
LAB_45008eac:
  if (piVar1 != *(int **)((int)param_1 + 0x10)) {
    FUN_450022ba((void *)((int)param_1 + 0x18),piVar1 + 5);
  }
  return;
}


