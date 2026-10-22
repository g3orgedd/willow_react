// Source: CLARiSOFT.exe @ 00e28e4d; FUN_00e28e4d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_00e28e4d(void *this,int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  void *this_00;
  undefined4 extraout_ECX;
  undefined1 *extraout_ECX_00;
  undefined1 *puVar5;
  wchar_t *bstrString;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  int local_20;
  wchar_t *local_1c;
  OLECHAR *local_18;
  undefined *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_18 = (OLECHAR *)PTR_DAT_00f35014;
  bstrString = (BSTR)0x0;
  local_1c = (wchar_t *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar2 = FUN_00e34129(this,-1);
  cVar1 = FUN_00e2e31a(this,iVar2);
  if (cVar1 != '\0') {
    do {
      local_14[0] = PTR_DAT_00f35014;
      local_8._0_1_ = 3;
      FUN_00e052f9(local_14,L"%02d");
      piVar3 = FUN_00eb928f(&local_20,0x600e);
      local_8._0_1_ = 4;
      FUN_00e06f61(&local_18,piVar3);
      local_8._0_1_ = 3;
      FUN_00e01f81(&local_20);
      FUN_00e03e2c(&local_1c,local_18);
      bstrString = local_1c;
      uVar4 = FUN_00e2e24e(this,local_1c);
      local_8._0_1_ = 2;
      FUN_00e01f81((int *)local_14);
    } while ((char)uVar4 != '\0');
    piVar3 = (int *)FUN_00e77808((void *)((int)this + 4),0);
    if (*piVar3 == 0) {
      local_14[0] = (undefined *)0x0;
    }
    else {
      local_14[0] = (undefined *)(*piVar3 + -100);
    }
    this_00 = (void *)FUN_00eca369(0x60);
    if (this_00 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar9 = (int *)0x0;
      local_8._0_1_ = 6;
      iVar2 = FUN_00e3e85d((int)local_14[0]);
      uVar4 = extraout_ECX;
      FUN_00e66eee(*(void **)(*(int *)((int)this + 400) + iVar2 * 4),(undefined4 *)&stack0xffffffb0)
      ;
      piVar3 = *(int **)((int)this + 0x19c);
      local_8._0_1_ = 7;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))();
      }
      piVar8 = *(int **)((int)this + 0x160);
      local_8._0_1_ = 8;
      if (piVar8 != (int *)0x0) {
        (**(code **)(*piVar8 + 4))();
      }
      local_8._0_1_ = 9;
      puVar5 = &stack0xffffffa4;
      piVar7 = param_2;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 4))();
        puVar5 = extraout_ECX_00;
      }
      local_8._0_1_ = 10;
      piVar6 = *(int **)((int)this + 0x20c);
      FUN_00e03ab8(&stack0xffffff98,(int *)((int)this + 0x208));
      local_8._0_1_ = 5;
      piVar3 = (int *)FUN_00e60535(this_00,(int *)bstrString,puVar5,piVar6,param_1,piVar7,piVar8,
                                   piVar3,uVar4,piVar9);
    }
    local_8._0_1_ = 2;
    if (piVar3[1] != 0) {
      piVar9 = *(int **)((int)this + 0x160);
      uVar10 = 0xffffffff;
      uVar4 = 0xffffffff;
      if (piVar9 != (int *)0x0) {
        (**(code **)(*piVar9 + 4))();
      }
      local_8._0_1_ = 0xb;
      iVar2 = FUN_00e3e85d((int)local_14[0]);
      local_8._0_1_ = 2;
      FUN_00e65d98(*(void **)(*(int *)((int)this + 400) + iVar2 * 4),1,(int)piVar3,piVar9,uVar4,
                   uVar10);
      FUN_00e62bca(piVar3,*(undefined4 *)((int)this + 0x180));
      (**(code **)(*(int *)this + 4))();
      FUN_00e2b99e((int)this);
      goto LAB_00e28ff7;
    }
    (**(code **)(*piVar3 + 0xc))();
  }
  piVar3 = (int *)0x0;
LAB_00e28ff7:
  SysFreeString(bstrString);
  FUN_00e01f81((int *)&local_18);
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))();
  }
  return piVar3;
}


