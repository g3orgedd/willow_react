// Source: CiffHelper.dll @ 40810662; FUN_40810662

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_40810662(void *this,int *param_1)

{
  UINT UVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  _union_2683 local_58;
  int local_44;
  int local_40;
  WCHAR local_3c [2];
  OLECHAR *local_38;
  BSTR local_34;
  BSTR local_30;
  int *local_2c;
  void *local_28;
  BSTR local_24;
  int *local_20;
  int *local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  iVar3 = 0;
  local_8 = 0;
  local_30 = (BSTR)0x0;
  local_28 = this;
  FUN_40802db0(&local_30,0x4084c434);
  local_24 = (BSTR)0x0;
  local_8._0_1_ = 3;
  (**(code **)(*param_1 + 0x5c))(param_1,&local_24);
  UVar1 = SysStringLen(local_24);
  pcVar5 = SysFreeString_exref;
  if (UVar1 == 0) goto LAB_408108ea;
  FUN_408030e3(&local_40,*(LPCWSTR *)((int)this + 0x74));
  local_8._0_1_ = 4;
  FUN_408030e3(local_3c,local_24);
  local_8._0_1_ = 5;
  FUN_4080aa73((void *)((int)this + 0x8c),&local_38,local_3c,&local_40);
  local_8._0_1_ = 6;
  FUN_40802e40(&local_34,local_38);
  local_20 = (int *)0x0;
  local_8._0_1_ = 8;
  iVar2 = FUN_4080f725((void *)((int)this + 0x28),(BSTR)&local_34,(int)&local_20);
  if ((iVar2 < 0) || (local_20 == (int *)0x0)) {
    local_44 = -0x7fffbffb;
                    /* WARNING: Subroutine does not return */
    FUN_4082d44f(&local_44,&DAT_4085cfdc);
  }
  local_1c = (int *)0x0;
  local_8._0_1_ = 9;
  iVar2 = (**(code **)(*local_20 + 0x54))(local_20,&local_1c);
  if ((-1 < iVar2) && (local_1c != (int *)0x0)) {
    local_68 = CONCAT22(local_68._2_2_,3);
    local_60 = 0;
    local_2c = (int *)0x0;
    local_8._0_1_ = 10;
    iVar2 = (**(code **)(*local_1c + 0x28))(local_1c,local_68,uStack_64,0,uStack_5c,&local_2c);
    pcVar5 = VariantClear_exref;
    if ((-1 < iVar2) && (local_2c != (int *)0x0)) {
      FUN_40802e76((uint *)&local_58);
      local_8._0_1_ = 0xb;
      (**(code **)(*local_2c + 0x34))(local_2c,&local_58);
      local_18[0] = 2;
      (**(code **)(*param_1 + 0x7c))(param_1,local_18);
      iVar4 = 1;
      iVar2 = local_18[0];
      if (0 < local_18[0]) {
        do {
          iVar4 = iVar4 * 10;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      if (local_58.n2.vt == 2) {
        iVar3 = (int)(short)local_58._8_2_;
      }
      else if (local_58.n2.vt == 3) {
        iVar3 = CONCAT22(local_58._10_2_,local_58._8_2_);
      }
      else if (local_58.n2.vt == 4) {
        iVar3 = (int)((float)iVar4 * (float)CONCAT22(local_58._10_2_,local_58._8_2_) + _DAT_4084c450
                     );
      }
      else if (local_58.n2.vt == 5) {
        iVar3 = (int)((float)(double)CONCAT44(local_58._12_4_,
                                              CONCAT22(local_58._10_2_,local_58._8_2_)) *
                      (float)iVar4 + _DAT_4084c450);
      }
      else {
        if (local_58.n2.vt == 6) {
LAB_408107e4:
          VariantChangeType((VARIANTARG *)&local_58.n2,(VARIANTARG *)&local_58,0,8);
        }
        else if (local_58.n2.vt != 8) {
          if (local_58.n2.vt != 0xe) goto LAB_4081084e;
          goto LAB_408107e4;
        }
        iVar3 = FUN_4081c61f((BSTR)CONCAT22(local_58._10_2_,local_58._8_2_),local_18[0]);
      }
LAB_4081084e:
      (**(code **)(*param_1 + 0x30))(param_1,iVar3);
      (**(code **)(*param_1 + 0x28))(param_1,iVar3);
      pcVar5 = VariantClear_exref;
      VariantClear((VARIANTARG *)&local_58.n2);
    }
    (*pcVar5)(&local_68);
  }
  local_8._0_1_ = 8;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  (**(code **)(*local_20 + 0x80))(local_20);
  local_8._0_1_ = 7;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  pcVar5 = SysFreeString_exref;
  SysFreeString(local_34);
  FUN_40803143((int *)&local_38);
  FUN_40803143((int *)local_3c);
  FUN_40803143(&local_40);
LAB_408108ea:
  (*pcVar5)(local_24);
  FUN_40802ea3((int *)&local_30);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_4081096e();
  return;
}


