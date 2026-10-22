// Source: CiffHelper.dll @ 4080f4e9; FUN_4080f4e9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_4080f4e9(void *this,BSTR param_1,int param_2,undefined4 param_3,int param_4)

{
  UINT UVar1;
  int iVar2;
  BSTR pOVar3;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  BSTR extraout_ECX_02;
  BSTR extraout_ECX_03;
  BSTR extraout_ECX_04;
  BSTR extraout_ECX_05;
  BSTR extraout_ECX_06;
  BSTR extraout_ECX_07;
  BSTR bstrString;
  BSTR bstrString_00;
  BSTR bstrString_01;
  bool bVar4;
  BSTR local_2c;
  BSTR local_28;
  BSTR local_24;
  BSTR local_20;
  int local_1c;
  void *local_18;
  char local_11;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x4080f4f5;
  local_18 = this;
  if ((*(int *)param_1 == 0) || (UVar1 = SysStringLen(*(BSTR *)param_1), UVar1 == 0)) {
    FUN_40804125(0x4084c3b8);
    local_1c = -0x7ff8ffa9;
  }
  else if ((param_2 == 0) || (param_4 == 0)) {
    FUN_40804125(0x4084c3d4);
    local_1c = -0x7fffbffd;
  }
  else {
    local_1c = (**(code **)(**(int **)((int)this + 0x20) + 0x40))
                         (*(int **)((int)this + 0x20),*(undefined4 *)param_1,param_2,param_3);
    bstrString = (BSTR)0x0;
    pOVar3 = (BSTR)0x80040e07;
    local_11 = 0;
    bVar4 = local_1c == -0x7ffbf1f9;
    if (bVar4) {
      FUN_40804125(0x4084c3fc);
      local_1c = FUN_4080f780(this,param_1,param_2,param_3,param_4);
      pOVar3 = extraout_ECX;
    }
    local_24 = (BSTR)0x0;
    bstrString_01 = (BSTR)0x0;
    local_28 = (BSTR)0x0;
    local_20 = (BSTR)0x0;
    bstrString_00 = (BSTR)0x0;
    local_2c = (BSTR)0x0;
    local_8 = 3;
    local_11 = bVar4;
    if (local_1c < 0) {
      FUN_40803baf(&stack0xffffffc0,(int *)param_1);
      FUN_4080f904(local_18,pOVar3);
      iVar2 = FUN_4080f1a5((undefined4 *)param_1,&local_24);
      bstrString = local_24;
      pOVar3 = extraout_ECX_00;
      if ((iVar2 < 0) ||
         (local_1c = (**(code **)(**(int **)((int)local_18 + 0x20) + 0x40))
                               (*(int **)((int)local_18 + 0x20),local_24,param_2,param_3),
         pOVar3 = extraout_ECX_01, local_1c < 0)) {
        FUN_40803baf(&stack0xffffffc0,(int *)&local_24);
        FUN_4080f904(local_18,pOVar3);
        iVar2 = FUN_4080f2e3(local_18,(undefined4 *)param_1,&local_28);
        bstrString_01 = local_28;
        pOVar3 = extraout_ECX_02;
        if ((iVar2 < 0) ||
           (local_1c = (**(code **)(**(int **)((int)local_18 + 0x20) + 0x40))
                                 (*(int **)((int)local_18 + 0x20),local_28,param_2,param_3),
           pOVar3 = extraout_ECX_03, local_1c < 0)) {
          FUN_40803baf(&stack0xffffffc0,(int *)&local_28);
          FUN_4080f904(local_18,pOVar3);
          iVar2 = FUN_4080ee68(local_18,(undefined4 *)param_1,&local_20);
          pOVar3 = extraout_ECX_04;
          if ((iVar2 < 0) ||
             (local_1c = (**(code **)(**(int **)((int)local_18 + 0x20) + 0x40))
                                   (*(int **)((int)local_18 + 0x20),local_20,param_2,param_3),
             pOVar3 = extraout_ECX_05, local_1c < 0)) {
            FUN_40803baf(&stack0xffffffc0,(int *)&local_20);
            FUN_4080f904(local_18,pOVar3);
            local_1c = FUN_4080f108(local_18,(undefined4 *)param_1,&local_2c);
            bstrString_00 = local_2c;
            pOVar3 = extraout_ECX_06;
            if ((local_1c < 0) ||
               (local_1c = (**(code **)(**(int **)((int)local_18 + 0x20) + 0x40))
                                     (*(int **)((int)local_18 + 0x20),local_2c,param_2,param_3),
               pOVar3 = extraout_ECX_07, local_1c < 0)) {
              FUN_40803baf(&stack0xffffffc0,(int *)&local_2c);
              FUN_4080f904(local_18,pOVar3);
            }
          }
        }
      }
    }
    if ((local_11 != '\0') && (local_1c < 0)) {
      local_1c = -0x7ffbf1f9;
    }
    SysFreeString(bstrString_00);
    SysFreeString(local_20);
    SysFreeString(bstrString_01);
    SysFreeString(bstrString);
  }
  return local_1c;
}


