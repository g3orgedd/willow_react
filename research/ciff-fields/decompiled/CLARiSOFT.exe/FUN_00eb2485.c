// Source: CLARiSOFT.exe @ 00eb2485; FUN_00eb2485

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_00eb2485(void *this,int *param_1,int *param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  char cVar3;
  undefined1 *this_00;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  _union_2683 local_84;
  _union_2683 local_74;
  _union_2683 local_64;
  void *local_54;
  int local_50;
  BSTR local_4c;
  undefined1 *local_48;
  int *local_44;
  int *local_40;
  int local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  BSTR local_28;
  BSTR local_24;
  int *local_20;
  BSTR local_1c;
  int *local_18;
  char local_11;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 1;
  local_54 = this;
  this_00 = (undefined1 *)FUN_00eca369(8);
  if (this_00 == (undefined1 *)0x0) {
    this_00 = (undefined1 *)0x0;
    local_48 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(this_00 + 4) = 0;
    local_48 = this_00;
    FUN_00e11de5(this_00 + 4,(int *)&param_2);
    *this_00 = 1;
  }
  FUN_00e03b21(&local_1c,L"File");
  local_8 = CONCAT31(local_8._1_3_,2);
  (**(code **)(*param_1 + 0x1c))();
  (**(code **)(**(int **)(this_00 + 4) + 0x4c))();
  if ((int)local_4c < local_3c) {
    piVar4 = FUN_00e4cac1(*(void **)((int)this + 0xc),0x8003);
    FUN_00eafbc7(*(void **)((int)this + 0x10),(CComBSTR *)&local_1c,piVar4);
  }
  local_40 = (int *)0x0;
  local_44 = (int *)0x0;
  local_38 = 0;
  if (0 < local_3c) {
    do {
      FUN_00e03b51((uint *)&local_84);
      local_38 = local_38 + 1;
      local_8._0_1_ = 3;
      (**(code **)(*param_1 + 0x24))(param_1,local_38);
      if (local_84.n2.vt != 0) {
        CComQIPtr<>(&local_18,(undefined4 *)local_84._8_4_);
        local_4c = (BSTR)0x0;
        local_8._0_1_ = 5;
        (**(code **)(*local_18 + 0x34))(local_18);
        puVar1 = (undefined4 *)((int)this + 0x20);
        SysFreeString((BSTR)*puVar1);
        *puVar1 = 0;
        (**(code **)(*local_18 + 0x4c))(local_18,puVar1);
        local_30 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,6);
        piVar4 = param_2;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 4))(param_2);
        }
        local_34 = FUN_00eb5f25(piVar4);
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 4))(local_34);
        }
        local_8._0_1_ = 7;
        piVar4 = (int *)0x0;
        if (local_34 != (int *)0x0) {
          FUN_00e2f762((int *)&local_34,(undefined4 *)((int)this + 0x20),&local_30);
          piVar4 = local_30;
        }
        local_11 = '\0';
        if (piVar4 != (int *)0x0) {
          local_24 = (BSTR)0x0;
          local_8 = CONCAT31(local_8._1_3_,8);
          (**(code **)(*piVar4 + 0x44))(piVar4,&local_24);
          bVar2 = FUN_00e03edc(&local_24,L"Line");
          if (bVar2) {
            (**(code **)(*piVar4 + 0x54))(piVar4,&local_50);
            local_11 = local_50 == 0;
          }
          local_8._0_1_ = 7;
          SysFreeString(local_24);
        }
        (**(code **)(*local_18 + 0x1c))(local_18,&local_2c);
        local_40 = (int *)((int)local_40 + local_2c);
        local_24 = (BSTR)0x0;
        if (0 < local_2c) {
          iVar5 = 0;
          do {
            FUN_00e03b51((uint *)&local_64);
            iVar5 = iVar5 + 1;
            local_8._0_1_ = 9;
            (**(code **)(*local_18 + 0x24))(local_18,iVar5);
            if (local_64.n2.vt != 0) {
              CComQIPtr<>(&local_20,(undefined4 *)local_64._8_4_);
              local_28 = (BSTR)0x0;
              local_8 = CONCAT31(local_8._1_3_,0xb);
              (**(code **)(*local_20 + 0x68))(local_20);
              bVar2 = FUN_00e03edc(&local_28,L"CounterText");
              if (bVar2) {
                local_44 = (int *)((int)local_44 + 1);
              }
              if (local_11 != '\0') {
                piVar4 = local_20;
                if (local_20 != (int *)0x0) {
                  (**(code **)(*local_20 + 4))(local_20);
                }
                piVar7 = local_18;
                if (local_18 != (int *)0x0) {
                  (**(code **)(*local_18 + 4))(local_18);
                }
                FUN_00eb17cc(this,piVar7,piVar4);
              }
              SysFreeString(local_28);
              local_8._0_1_ = 9;
              if (local_20 != (int *)0x0) {
                (**(code **)(*local_20 + 8))();
              }
            }
            VariantClear((VARIANTARG *)&local_64.n2);
            piVar4 = local_30;
          } while (iVar5 < local_2c);
        }
        local_8._0_1_ = 6;
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 8))();
        }
        local_8._0_1_ = 5;
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 8))();
        }
        SysFreeString(local_4c);
        local_8._0_1_ = 3;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))();
        }
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      VariantClear((VARIANTARG *)&local_84.n2);
      this_00 = local_48;
    } while (local_38 < local_3c);
  }
  (**(code **)(**(int **)(this_00 + 4) + 0x6c))(*(int **)(this_00 + 4));
  if ((0 < (int)local_4c) && ((int)local_4c < (int)local_40)) {
    piVar4 = FUN_00e4cac1(*(void **)((int)this + 0xc),0x8001);
    FUN_00eafbc7(*(void **)((int)this + 0x10),(CComBSTR *)&local_1c,piVar4);
    *(undefined4 *)((int)this + 8) = 1;
  }
  cVar3 = FUN_00eb73f4((int)this_00);
  if ((((cVar3 != '\x01') || (iVar5 = FUN_00e56780(), iVar5 < 1)) &&
      (iVar5 = FUN_00eb6585((int)this_00), -1 < iVar5)) && (iVar5 < (int)local_44)) {
    piVar4 = FUN_00e4cac1(*(void **)((int)this + 0xc),0x8002);
    FUN_00eafbc7(*(void **)((int)this + 0x10),(CComBSTR *)&local_1c,piVar4);
    *(undefined4 *)((int)this + 4) = 1;
  }
  FUN_00e03b51((uint *)&local_74);
  local_8._0_1_ = 0xc;
  (**(code **)(*param_1 + 100))(param_1,&local_74);
  if (local_74.n2.vt != 0) {
    CComQIPtr<>(&local_40,(undefined4 *)local_74._8_4_);
    local_8 = CONCAT31(local_8._1_3_,0xd);
    local_38 = 0;
    (**(code **)(*local_40 + 0x1c))(local_40,&local_4c);
    iVar5 = local_38;
    if (0 < (int)local_4c) {
      iVar6 = 0;
      iVar5 = 0;
      do {
        FUN_00e03b51((uint *)&local_64);
        iVar6 = iVar6 + 1;
        local_8._0_1_ = 0xe;
        (**(code **)(*local_40 + 0x30))(local_40,iVar6,&local_64);
        if (local_64.n2.vt != 0) {
          CComQIPtr<>(&local_44,(undefined4 *)local_64._8_4_);
          local_8._0_1_ = 0xf;
          (**(code **)(*local_44 + 0x4c))(local_44,&local_50);
          (**(code **)(*local_44 + 0xc4))(local_44,&local_34);
          if ((local_50 == 0) && (local_34 == (int *)0x1)) {
            iVar5 = iVar5 + 1;
          }
          (**(code **)(*(int *)local_64._8_4_ + 8))(local_64._8_4_);
          local_64._8_4_ = (int *)0x0;
          local_64.n2.vt = 0;
          local_8._0_1_ = 0xe;
          if (local_44 != (int *)0x0) {
            (**(code **)(*local_44 + 8))(local_44);
          }
        }
        local_8 = CONCAT31(local_8._1_3_,0xd);
        VariantClear((VARIANTARG *)&local_64.n2);
        this_00 = local_48;
        this = local_54;
      } while (iVar6 < (int)local_4c);
    }
    local_38 = iVar5;
    iVar5 = FUN_00eb65a0((int)this_00);
    if ((iVar5 != -1) && (iVar5 < local_38)) {
      piVar4 = FUN_00e4cac1(*(void **)((int)this + 0xc),0x8004);
      FUN_00eafbc7(*(void **)((int)this + 0x10),(CComBSTR *)&local_1c,piVar4);
    }
    (**(code **)(*(int *)local_74._8_4_ + 8))(local_74._8_4_);
    local_74._8_4_ = (int *)0x0;
    local_74.n2.vt = 0;
    local_8._0_1_ = 0xc;
    if (local_40 != (int *)0x0) {
      (**(code **)(*local_40 + 8))(local_40);
    }
  }
  if (this_00 != (undefined1 *)0x0) {
    FUN_00e63686(this_00,1);
  }
  VariantClear((VARIANTARG *)&local_74.n2);
  SysFreeString(local_1c);
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return 0;
}


