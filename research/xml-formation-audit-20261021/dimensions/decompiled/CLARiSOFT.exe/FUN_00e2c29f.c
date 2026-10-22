// Source: CLARiSOFT.exe @ 00e2c29f; FUN_00e2c29f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_00e2c29f(void *this,int *param_1,uint param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  BSTR pOVar4;
  float10 fVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  BSTR pOVar10;
  VARIANTARG local_50;
  undefined4 local_40;
  undefined4 local_3c;
  BSTR local_38;
  int *local_34;
  BSTR local_30;
  undefined4 *local_2c;
  OLECHAR local_28 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0xe2c2ab;
  if ((*(int *)((int)this + 0x158) != 0) && (*(int *)((int)this + 0x15c) != 0)) {
    (**(code **)(**(int **)((int)this + 0x15c) + 0x2c))(*(int **)((int)this + 0x15c));
    *(undefined4 *)((int)this + 0x214) = local_40;
    (**(code **)(**(int **)((int)this + 0x15c) + 0x34))(*(int **)((int)this + 0x15c),&local_3c);
    *(undefined4 *)((int)this + 0x218) = local_3c;
    FUN_00ecd4ad(param_2,local_28,10,10);
    if (param_1 == (int *)0x0) {
      local_34 = (int *)0x0;
      local_8 = 0;
      FUN_00e03b51((uint *)&local_50);
      local_38 = (BSTR)0x0;
      local_8._0_1_ = 2;
      (**(code **)(**(int **)((int)this + 0x15c) + 0x1c))(*(int **)((int)this + 0x15c));
      piVar9 = *(int **)((int)this + 0x19c);
      puVar3 = FUN_00e03b21(&local_30,local_28);
      local_8._0_1_ = 3;
      (**(code **)(*piVar9 + 0x28))(piVar9,*puVar3,local_38,1,1,0,&local_50);
      local_8._0_1_ = 2;
      SysFreeString(local_30);
      FUN_00e42e0a(&local_34,(int *)local_50.n1._8_4_);
      pOVar10 = (BSTR)0x40;
      pOVar4 = (BSTR)FUN_00eca369(0x40);
      piVar9 = local_34;
      local_8._0_1_ = 4;
      local_30 = pOVar4;
      if (pOVar4 == (BSTR)0x0) {
        local_2c = (undefined4 *)0x0;
      }
      else {
        FUN_00e03ab8(&stack0xffffff9c,(int *)(*(int *)((int)this + 0x158) + 8));
        piVar8 = *(int **)((int)this + 0x230);
        if (piVar8 != (int *)0x0) {
          (**(code **)(*piVar8 + 4))(piVar8);
        }
        uVar7 = *(undefined4 *)((int)this + 0x180);
        piVar6 = piVar9;
        if (piVar9 != (int *)0x0) {
          (**(code **)(*piVar9 + 4))(piVar9);
        }
        local_2c = FUN_00e65afe(pOVar4,*(uint *)((int)this + 0x214),
                                *(undefined4 *)((int)this + 0x218),piVar6,uVar7,piVar8,pOVar10);
      }
      local_8._0_1_ = 2;
      uVar2 = (undefined1)local_8;
      local_8._0_1_ = 2;
      if (piVar9 != (int *)0x0) {
        iVar1 = *piVar9;
        FUN_00e2f535((int)this,'\x01');
        (**(code **)(iVar1 + 0x78))(piVar9);
        iVar1 = *piVar9;
        fVar5 = FUN_00e2f535((int)this,'\0');
        (**(code **)(iVar1 + 0x70))(piVar9,(float)fVar5);
        CComQIPtr<>(&local_30,piVar9);
        local_8._0_1_ = 5;
        if (local_30 != (BSTR)0x0) {
          (**(code **)(*(int *)local_30 + 0xd8))(local_30);
        }
        local_8._0_1_ = 2;
        uVar2 = (undefined1)local_8;
        if (local_30 != (BSTR)0x0) {
          (**(code **)(*(int *)local_30 + 8))();
          uVar2 = (undefined1)local_8;
        }
      }
      local_8._0_1_ = uVar2;
      SysFreeString(local_38);
      VariantClear(&local_50);
      local_8 = 0xffffffff;
      if (piVar9 != (int *)0x0) {
        (**(code **)(*piVar9 + 8))();
      }
    }
    else {
      pOVar10 = (BSTR)0x40;
      pOVar4 = (BSTR)FUN_00eca369(0x40);
      local_8 = 6;
      local_30 = pOVar4;
      if (pOVar4 == (BSTR)0x0) {
        local_2c = (undefined4 *)0x0;
      }
      else {
        FUN_00e03ab8(&stack0xffffff9c,(int *)(*(int *)((int)this + 0x158) + 8));
        piVar9 = *(int **)((int)this + 0x230);
        if (piVar9 != (int *)0x0) {
          (**(code **)(*piVar9 + 4))(piVar9);
        }
        uVar7 = *(undefined4 *)((int)this + 0x180);
        (**(code **)(*param_1 + 4))(param_1);
        local_2c = FUN_00e65afe(pOVar4,*(uint *)((int)this + 0x214),
                                *(undefined4 *)((int)this + 0x218),param_1,uVar7,piVar9,pOVar10);
      }
    }
  }
  FUN_00ec9e3c();
  return;
}


