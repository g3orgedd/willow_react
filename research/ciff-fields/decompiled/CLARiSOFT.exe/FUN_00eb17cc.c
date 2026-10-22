// Source: CLARiSOFT.exe @ 00eb17cc; FUN_00eb17cc

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_00eb17cc(void *this,int *param_1,int *param_2)

{
  void *pvVar1;
  undefined4 *this_00;
  int iVar2;
  undefined4 *this_01;
  BOOL BVar3;
  int *piVar4;
  int iVar5;
  _union_2683 local_6c;
  void *local_5c;
  int local_58;
  int local_54;
  int local_50;
  BSTR local_4c;
  int *local_48;
  RECT local_44;
  RECT local_34;
  tagRECT local_24;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_5c = this;
  if ((param_2 != (int *)0x0) && (param_1 != (int *)0x0)) {
    this_00 = (undefined4 *)FUN_00eca369(8);
    if (this_00 == (undefined4 *)0x0) {
      this_00 = (undefined4 *)0x0;
    }
    else {
      *this_00 = TCIFFField<ICiffField>::vftable;
      this_00[1] = 0;
      FUN_00e11de5(this_00 + 1,(int *)&param_2);
    }
    local_8._0_1_ = 2;
    if (this_00 != (undefined4 *)0x0) {
      FUN_00e61ccc(this_00,&local_44.left,'\x01');
      iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_54);
      iVar5 = 0;
      if (0 < local_54) {
        do {
          if (iVar2 < 0) break;
          FUN_00e03b51((uint *)&local_6c);
          iVar5 = iVar5 + 1;
          local_8._0_1_ = 3;
          local_50 = iVar5;
          iVar2 = (**(code **)(*param_1 + 0x24))(param_1,iVar5,&local_6c);
          if (((-1 < iVar2) && (local_6c.n2.vt == 9)) &&
             ((undefined4 *)local_6c._8_4_ != (undefined4 *)0x0)) {
            CComQIPtr<>(&local_48,(undefined4 *)local_6c._8_4_);
            local_8._0_1_ = 4;
            if ((local_48 != (int *)0x0) && (local_48 != param_2)) {
              local_58 = 1;
              iVar2 = (**(code **)(*local_48 + 0x24))(local_48,&local_58);
              if ((-1 < iVar2) && (local_58 == 1)) {
                this_01 = (undefined4 *)FUN_00eca369(8);
                if (this_01 == (undefined4 *)0x0) {
                  this_01 = (undefined4 *)0x0;
                }
                else {
                  *this_01 = TCIFFField<ICiffField>::vftable;
                  this_01[1] = 0;
                  FUN_00e11de5(this_01 + 1,(int *)&local_48);
                }
                local_8._0_1_ = 5;
                if (this_01 != (undefined4 *)0x0) {
                  FUN_00e61ccc(this_01,&local_34.left,'\x01');
                  FUN_00e616d4(this_01,&local_4c);
                  local_8._0_1_ = 6;
                  local_24.left = 0;
                  local_24.top = 0;
                  local_24.right = 0;
                  local_24.bottom = 0;
                  BVar3 = IntersectRect(&local_24,&local_34,&local_44);
                  pvVar1 = local_5c;
                  if (BVar3 != 0) {
                    piVar4 = FUN_00e4cac1(*(void **)((int)local_5c + 0xc),0x97);
                    FUN_00eafbc7(*(void **)((int)pvVar1 + 0x10),(CComBSTR *)&local_4c,piVar4);
                    SysFreeString(local_4c);
                    FUN_00e63686(this_01,1);
                    local_8._0_1_ = 3;
                    if (local_48 != (int *)0x0) {
                      (**(code **)(*local_48 + 8))(local_48);
                    }
                    VariantClear((VARIANTARG *)&local_6c.n2);
                    break;
                  }
                  SysFreeString(local_4c);
                  FUN_00e63686(this_01,1);
                }
              }
            }
            local_8._0_1_ = 3;
            iVar5 = local_50;
            if (local_48 != (int *)0x0) {
              (**(code **)(*local_48 + 8))(local_48);
              iVar5 = local_50;
            }
          }
          VariantClear((VARIANTARG *)&local_6c.n2);
        } while (iVar5 < local_54);
      }
      FUN_00e63686(this_00,1);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  FUN_00ec9e3c();
  return;
}


