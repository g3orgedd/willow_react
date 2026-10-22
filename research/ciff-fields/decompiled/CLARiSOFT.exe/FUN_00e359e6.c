// Source: CLARiSOFT.exe @ 00e359e6; FUN_00e359e6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e359e6(void *this,int *param_1)

{
  undefined1 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  VARIANTARG local_44;
  undefined1 *local_34;
  undefined4 local_30;
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0xe359f2;
  *(int **)((int)this + 0x22c) = param_1;
  uVar3 = (uint)(param_1 == (int *)0x0);
  iVar4 = 0;
  if (*(int *)((int)this + 0x19c) != 0) {
    (**(code **)(**(int **)((int)this + 0x19c) + 0x54))();
    (**(code **)(**(int **)((int)this + 0x19c) + 0x58))(*(int **)((int)this + 0x19c),uVar3);
    if (local_2c != uVar3) {
      FUN_00eae6d1(&local_30);
      local_8 = 0;
      (**(code **)(**(int **)((int)this + 0x19c) + 0x1c))();
      local_24 = 0;
      if (0 < local_28) {
        do {
          FUN_00e03b51((uint *)&local_44);
          local_24 = local_24 + 1;
          local_8._0_1_ = 1;
          (**(code **)(**(int **)((int)this + 0x19c) + 0x24))(*(int **)((int)this + 0x19c));
          CComQIPtr<>(&param_1,(undefined4 *)local_44.n1._8_4_);
          local_8 = CONCAT31(local_8._1_3_,2);
          (**(code **)(*param_1 + 0x3c))(param_1,local_14);
          (**(code **)(*param_1 + 0x44))(param_1,&local_18);
          (**(code **)(*param_1 + 0x5c))(param_1,&local_1c);
          (**(code **)(*param_1 + 100))(param_1,&local_20);
          piVar2 = *(int **)((int)this + 0x160);
          if (uVar3 == 1) {
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 4))(piVar2);
            }
            local_14[0] = FUN_00eaeae0(local_14[0],1.4013e-45,piVar2);
            piVar2 = *(int **)((int)this + 0x160);
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 4))(piVar2);
            }
            local_18 = FUN_00eaeae0(local_18,0.0,piVar2);
            piVar2 = *(int **)((int)this + 0x160);
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 4))(piVar2);
            }
            local_1c = FUN_00eaeae0(local_1c,1.4013e-45,piVar2);
            piVar2 = *(int **)((int)this + 0x160);
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 4))(piVar2);
            }
            local_20 = FUN_00eaeae0(local_20,0.0,piVar2);
          }
          else {
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 4))(piVar2);
            }
            local_14[0] = FUN_00eae95c(local_14[0],1.4013e-45,piVar2);
            piVar2 = *(int **)((int)this + 0x160);
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 4))(piVar2);
            }
            local_18 = FUN_00eae95c(local_18,0.0,piVar2);
            piVar2 = *(int **)((int)this + 0x160);
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 4))(piVar2);
            }
            local_1c = FUN_00eae95c(local_1c,1.4013e-45,piVar2);
            piVar2 = *(int **)((int)this + 0x160);
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 4))(piVar2);
            }
            local_20 = FUN_00eae95c(local_20,0.0,piVar2);
          }
          (**(code **)(*param_1 + 0x40))(param_1,local_14[0]);
          (**(code **)(*param_1 + 0x48))(param_1,local_18);
          (**(code **)(*param_1 + 0x60))(param_1,local_1c);
          (**(code **)(*param_1 + 0x68))(param_1,local_20);
          local_8 = CONCAT31(local_8._1_3_,1);
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))();
          }
          VariantClear(&local_44);
        } while (local_24 < local_28);
      }
      local_8 = 0xffffffff;
      FUN_00eae7b2(&local_30);
    }
    if ((*(int *)((int)this + 0x194) - *(int *)((int)this + 400) & 0xfffffffcU) != 0) {
      piVar2 = (int *)FUN_00e77808((void *)((int)this + 4),0);
      if (*piVar2 != 0) {
        iVar4 = *piVar2 + -100;
      }
      local_34 = &stack0xffffffa4;
      piVar2 = *(int **)((int)this + 0x160);
      iVar5 = iVar4;
      puVar1 = &stack0xffffffa4;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
        puVar1 = local_34;
      }
      local_34 = puVar1;
      local_8 = 3;
      iVar4 = FUN_00e3e85d(iVar4);
      local_8 = 0xffffffff;
      FUN_00e67cfe(*(void **)(*(int *)((int)this + 400) + iVar4 * 4),uVar3,piVar2,iVar5);
    }
  }
  return;
}


