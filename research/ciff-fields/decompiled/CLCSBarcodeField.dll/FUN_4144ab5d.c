// Source: CLCSBarcodeField.dll @ 4144ab5d; FUN_4144ab5d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_4144ab5d(void *this,int param_1,undefined4 param_2,BSTR param_3,BSTR param_4,float param_5,
            HDC param_6,int param_7,BSTR param_8,LONG *param_9)

{
  LONG LVar1;
  int *piVar2;
  int iVar3;
  BSTR pOVar4;
  OLECHAR *pOVar5;
  LPSIZE ptVar6;
  tagSIZE local_1a8;
  int local_1a0 [3];
  LONG *local_194;
  int *local_190;
  undefined4 local_18c;
  int *local_188;
  float local_184;
  BSTR local_180;
  undefined4 local_17c [84];
  undefined4 local_2c;
  undefined4 local_1c;
  uint local_18;
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x198;
  local_184 = param_5;
  local_1a8.cy = (LONG)param_6;
  local_180 = param_3;
  local_194 = param_9;
  local_8 = 0;
  uStack_7 = 0;
  local_18c = 0xffffffff;
  if (param_1 == 0x13) {
    local_180 = (BSTR)FUN_41460343(0xc70);
    local_8 = 1;
    if (local_180 == (BSTR)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_41448049(local_180,param_2,(int)param_3,0x16,(uint)(local_184._0_1_ != '\0'));
    }
    local_8 = 0;
  }
  else {
    if (param_1 != 0x14) goto LAB_4144ae83;
    CComQIPtr<>(&local_190,*(undefined4 **)((int)this + 0xf4));
    local_8 = 2;
    if (local_190 != (int *)0x0) {
      piVar2 = (int *)((int)this + 0x9c);
      (**(code **)(*local_190 + 0x174))(local_190,piVar2);
      iVar3 = *piVar2;
      if (*piVar2 < 2) {
        iVar3 = 2;
      }
      if (0x16 < iVar3) {
        iVar3 = 0x16;
      }
      *piVar2 = iVar3;
      param_3 = local_180;
    }
    local_180 = (BSTR)FUN_41460343(0xc70);
    local_8 = 3;
    if (local_180 == (BSTR)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_41448049(local_180,param_2,(int)param_3,*(undefined4 *)((int)this + 0x9c),
                            (uint)(local_184._0_1_ != '\0'));
    }
    local_8 = 0;
    if (local_190 != (int *)0x0) {
      (**(code **)(*local_190 + 8))(local_190);
    }
  }
  if (piVar2 != (int *)0x0) {
    local_1a0[0] = 0;
    local_1a0[1] = 0;
    local_1a0[2] = 0;
    local_8 = 4;
    iVar3 = (**(code **)(*piVar2 + 4))(&param_4,local_1a0,(int)this + 0x74);
    if (-1 < iVar3) {
      local_18c = (**(code **)(*piVar2 + 8))();
      pOVar4 = param_8;
      if (param_7 < 1000) {
        pOVar4 = (BSTR)((param_7 * (int)param_8) / 1000);
      }
      if ((int)pOVar4 < 3) {
        pOVar4 = (BSTR)0x3;
      }
      (**(code **)(**(int **)((int)this + 0xfc) + 0x2c))(*(int **)((int)this + 0xfc),&local_184);
      *(int *)((int)this + 0xa4) = (int)((double)(local_184 * _DAT_41481060) + _DAT_41481058);
      (**(code **)(**(int **)((int)this + 0xfc) + 0x34))(*(int **)((int)this + 0xfc),&local_184);
      local_188 = (int *)0x0;
      *(int *)((int)this + 0xa8) = (int)((double)(local_184 * _DAT_41481060) + _DAT_41481058);
      local_8 = 5;
      (**(code **)**(undefined4 **)((int)this + 0xf4))
                (*(undefined4 **)((int)this + 0xf4),&DAT_4148097c,&local_188);
      if (local_188 != (int *)0x0) {
        FUN_41423a67(local_17c);
        local_8 = 6;
        FUN_414095de(local_17c,*(undefined4 *)((int)this + 0x68));
        local_1c = 0;
        local_18 = 7;
        local_2c = (OLECHAR *)((uint)local_2c._2_2_ << 0x10);
        local_8 = 7;
        FUN_41408df8((undefined4 *)((int)this + 0xf8),&local_188,&local_2c);
        pOVar5 = (OLECHAR *)&local_2c;
        if (7 < local_18) {
          pOVar5 = local_2c;
        }
        FUN_41402f15(&local_180,pOVar5);
        local_8 = 8;
        FUN_41403290(piVar2 + 0x20f,(int *)&local_180);
        SysFreeString(local_180);
        FUN_414062a0(&local_2c,'\x01',0);
        local_8 = 5;
        FUN_41423b78(local_17c);
      }
      ptVar6 = FUN_4144a9c2(this,&local_1a8,(int)piVar2,(HDC)local_1a8.cy,pOVar4);
      local_8 = 4;
      LVar1 = ptVar6->cx;
      local_194[1] = ptVar6->cy;
      *local_194 = LVar1;
      if (local_188 != (int *)0x0) {
        (**(code **)(*local_188 + 8))(local_188);
      }
    }
    (**(code **)*piVar2)(1);
    FUN_41449652(local_1a0);
  }
LAB_4144ae83:
  SysFreeString(param_4);
  FUN_41461ee2();
  return;
}


