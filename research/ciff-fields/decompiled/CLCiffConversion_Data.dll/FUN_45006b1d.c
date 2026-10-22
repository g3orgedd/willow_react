// Source: CLCiffConversion_Data.dll @ 45006b1d; FUN_45006b1d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_45006b1d(void *this,BSTR param_1)

{
  int *this_00;
  BSTR this_01;
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  this_01 = param_1;
  uStack_4 = 0x10;
  local_8 = 0x45006b29;
  puVar2 = FUN_450072f3(param_1,&local_18);
  local_8 = 0;
  this_00 = (int *)((int)this + -0x10);
  FUN_45002365((void *)((int)this + *(int *)(*this_00 + 4) + 0x58),(LPCWSTR)*puVar2);
  local_8 = 0xffffffff;
  SysFreeString(local_18);
  FUN_45007442(this_01,local_14);
  local_8 = 1;
  bVar1 = FUN_450023b0(local_14,L"##DEMO_FIELD##");
  if (bVar1) goto LAB_45006c72;
  FUN_4500732a(this_01,&param_1);
  local_8 = CONCAT31(local_8._1_3_,2);
  (**(code **)(**(int **)(this_01 + 2) + 100))(*(int **)(this_01 + 2),&local_18);
  if (local_18 == (BSTR)0x0) {
    bVar1 = FUN_450023b0(&param_1,L"FixedText");
    if (!bVar1) {
      bVar1 = FUN_450023b0(&param_1,L"MergeField");
      if (!bVar1) {
        bVar1 = FUN_450023b0(&param_1,L"EquipRef");
        if (!bVar1) goto LAB_45006c65;
      }
    }
    local_18 = (BSTR)0x0;
    local_1c = (undefined4 *)FUN_45013f7b((int *)0x0,(int *)0x0);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_4500735e((int *)this_01,&local_1c);
    puVar3 = local_1c;
    for (puVar2 = (undefined4 *)*local_1c; puVar2 != puVar3; puVar2 = (undefined4 *)*puVar2) {
      if (puVar2[2] != 0) {
        FUN_45006ca4((undefined4 *)puVar2[2],(int)this_01);
        puVar3 = local_1c;
      }
    }
    FUN_45004f8d((int *)&local_1c);
    FUN_4501423d((int *)&local_1c);
    FID_conflict__free(local_1c);
  }
  else if (local_18 == (BSTR)0x1) {
    FUN_4500761c(this_00,this_01);
  }
LAB_45006c65:
  local_8 = CONCAT31(local_8._1_3_,1);
  SysFreeString(param_1);
LAB_45006c72:
  FUN_45007216((int *)(*(int *)(*this_00 + 4) + 0x58 + (int)this));
  SysFreeString(local_14[0]);
  return 0;
}


