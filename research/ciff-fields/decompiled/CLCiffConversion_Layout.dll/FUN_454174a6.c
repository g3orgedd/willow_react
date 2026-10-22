// Source: CLCiffConversion_Layout.dll @ 454174a6; FUN_454174a6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_454174a6(void *this,int *param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  undefined4 uVar4;
  HRESULT HVar5;
  int iVar6;
  int extraout_EAX;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  void *local_38;
  undefined4 local_34;
  BSTR local_30;
  BSTR local_2c;
  int local_28;
  int local_24;
  BSTR local_20;
  BSTR local_1c;
  BSTR local_18;
  undefined4 *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x454174b2;
  piVar1 = (int *)((int)this + 0x6c);
  if (*piVar1 == 0) {
    uVar4 = 0x80070057;
  }
  else {
    cVar2 = FUN_4540678d((int)this);
    piVar8 = param_1;
    if (cVar2 != '\0') {
      local_20 = (BSTR)0x0;
      local_8 = 0;
      (**(code **)(*(int *)*param_1 + 0x4c))();
      local_1c = (BSTR)0x0;
      local_8._0_1_ = 1;
      (**(code **)(*(int *)*piVar1 + 0x1c))((int *)*piVar1);
      local_34 = 0;
      local_38 = (void *)FUN_454043b0((int *)0x0,(int *)0x0);
      local_8._0_1_ = 2;
      FUN_45406d62(piVar8,&local_38);
      param_1 = (int *)0x0;
      FUN_45404ce5(&param_1,piVar1);
      local_8._0_1_ = 3;
      FUN_45404ce5((void *)((int)this + 0x5c),piVar8);
      FUN_4541da01(&param_1,&local_18);
      local_8._0_1_ = 4;
      FUN_454028ee(&local_30,L"Line");
      local_8._0_1_ = 5;
      FUN_454028ee(&local_2c,L"Free");
      local_8 = CONCAT31(local_8._1_3_,6);
      HVar5 = VarBstrCmp(local_30,local_18,0x400,0);
      piVar1 = param_1;
      if (HVar5 == 1) {
        local_14 = (undefined4 *)0x0;
        HVar5 = VarBstrCmp(local_1c,local_20,0x400,0);
        if (HVar5 == 1) {
          (**(code **)(*(int *)*piVar8 + 100))();
        }
        else {
          local_14 = FUN_4541f150((undefined4 *)((int)this + 0x5c));
        }
        local_24 = 0;
        (**(code **)(*piVar1 + 0x2c))();
        iVar6 = (int)local_14 / local_24;
        piVar7 = extraout_ECX;
        piVar9 = extraout_ECX;
        FUN_4541269e(&stack0xffffffac,&local_38);
        FUN_45419f54(this,piVar7,piVar9,iVar6);
        bVar3 = FUN_4541c6c2(&param_1);
        if (bVar3) {
          piVar7 = extraout_ECX_00;
          FUN_4541269e(&stack0xffffffb0,&local_38);
          FUN_454145f3(this,piVar7);
        }
        local_28 = 0;
        if (*(int **)((int)this + 0x38) != (int *)0x0) {
          (**(code **)(**(int **)((int)this + 0x38) + 0x1dc))();
          if (local_28 != 0) {
            FUN_4541919e(this,piVar8);
            FUN_454065f3((int *)&local_38);
            FUN_45406d62(piVar8,&local_38);
          }
        }
      }
      else {
        HVar5 = VarBstrCmp(local_2c,local_18,0x400,0);
        if (HVar5 == 1) {
          local_28 = 0;
          (**(code **)(*piVar1 + 0x34))();
          FUN_45421dd2(this,local_28,'\0',(void *)0x1);
          piVar8 = extraout_ECX_01;
          piVar7 = extraout_ECX_01;
          iVar6 = extraout_EAX;
          FUN_4541269e(&stack0xffffffac,&local_38);
          FUN_45419c08(this,piVar8,piVar7,iVar6);
        }
      }
      FUN_454065f3((int *)&local_38);
      piVar8 = *(int **)((int)this + 0x5c);
      if ((piVar8 != (int *)0x0) && (*(undefined4 *)((int)this + 0x5c) = 0, piVar8 != (int *)0x0)) {
        (**(code **)(*piVar8 + 8))();
      }
      SysFreeString(local_2c);
      SysFreeString(local_30);
      SysFreeString(local_18);
      local_8 = CONCAT31(local_8._1_3_,2);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))();
      }
      FUN_454224ff((int *)&local_38);
      FID_conflict__free(local_38);
      SysFreeString(local_1c);
      SysFreeString(local_20);
    }
    uVar4 = 0;
  }
  return uVar4;
}


