// Source: CiffMgr.dll @ 6812ccce; FUN_6812ccce

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6812ccce(void *this,int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  OLECHAR *psz;
  undefined *puVar4;
  short *psVar5;
  int **ppiVar6;
  _union_2683 local_44;
  int local_34;
  int local_30;
  int local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  local_24 = this;
  iVar3 = (*(code *)**(undefined4 **)*param_2)((undefined4 *)*param_2,&DAT_6814a2fc,local_14);
  piVar2 = param_1;
  if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
    local_28 = (int *)0x0;
    local_8._0_1_ = 1;
    iVar3 = FUN_68124179(param_1,param_3,PTR_u_Font_6815fdbc,(int *)&local_28);
    if ((-1 < iVar3) &&
       ((iVar3 = FUN_6812d1de(piVar2,(int *)local_14,(int *)&local_28), -1 < iVar3 &&
        (iVar3 = (**(code **)(*local_14[0] + 0xc0))(local_14[0],&local_2c), -1 < iVar3)))) {
      if (local_2c != 0) {
        local_20 = (int *)0x0;
        local_8._0_1_ = 2;
        iVar3 = FUN_68124179(piVar2,param_3,PTR_u_Bold_6815fdc0,(int *)&local_20);
        if (-1 < iVar3) {
          param_1 = (int *)0x0;
          local_8._0_1_ = 3;
          iVar3 = (**(code **)(*local_20 + 0x44))(local_20,&param_1);
          if (-1 < iVar3) {
            if (param_1 != (int *)0x0) {
              FUN_68132710((uint *)&local_44,0,0x10);
              VariantInit((VARIANTARG *)&local_44.n2);
              local_44._8_4_ = (BSTR)0x0;
              local_44.n2.vt = 8;
              local_8._0_1_ = 4;
              iVar3 = (**(code **)(*local_14[0] + 0x104))(local_14[0],&local_1c);
              if (-1 < iVar3) {
                psz = FUN_6812f174(this,(int)local_1c);
                local_44._8_4_ = SysAllocString(psz);
                iVar3 = FUN_681021f5(piVar2,&param_1,PTR_u_Weight_68160080,(undefined4 *)&local_44);
              }
              VariantClear((VARIANTARG *)&local_44.n2);
            }
            if (-1 < iVar3) {
              local_1c = (int *)0x0;
              piVar1 = (int *)*piVar2;
              ppiVar6 = &local_1c;
              iVar3 = *piVar1;
              local_8 = CONCAT31(local_8._1_3_,5);
              puVar4 = FUN_6812e9d1(local_2c);
              iVar3 = (**(code **)(iVar3 + 0xc4))(piVar1,puVar4,ppiVar6);
              if ((-1 < iVar3) && (local_1c != (int *)0x0)) {
                iVar3 = (**(code **)(*local_20 + 0x54))(local_20,local_1c,0);
              }
              local_8._0_1_ = 3;
              if (local_1c != (int *)0x0) {
                (**(code **)(*local_1c + 8))(local_1c);
              }
            }
          }
          local_8._0_1_ = 2;
          this = local_24;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
            this = local_24;
          }
        }
        local_8._0_1_ = 1;
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))(local_20);
        }
      }
      if ((-1 < iVar3) &&
         (iVar3 = (**(code **)(*local_14[0] + 200))(local_14[0],&param_1), -1 < iVar3)) {
        if (param_1 != (int *)0x0) {
          puVar4 = FUN_6812e9d1((int)param_1);
          iVar3 = FUN_6810248f(piVar2,param_3,PTR_u_Italic_6815fdc4,puVar4);
        }
        if ((-1 < iVar3) &&
           (iVar3 = (**(code **)(*local_14[0] + 0x10c))(local_14[0],&param_1), -1 < iVar3)) {
          if (param_1 != (int *)0x0) {
            puVar4 = FUN_6812e9d1((int)param_1);
            iVar3 = FUN_6810248f(piVar2,param_3,PTR_u_DblSpace_6815fdc8,puVar4);
          }
          if (((-1 < iVar3) &&
              (iVar3 = (**(code **)(*local_14[0] + 0xd0))(local_14[0],&local_2c), -1 < iVar3)) &&
             (local_2c != 0)) {
            param_1 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,6);
            iVar3 = FUN_68124179(piVar2,param_3,PTR_u_Block_6815fdcc,(int *)&param_1);
            if (-1 < iVar3) {
              iVar3 = FUN_68125c42(this,piVar2,local_14,&param_1);
            }
            local_8._0_1_ = 1;
            if (param_1 != (int *)0x0) {
              (**(code **)(*param_1 + 8))(param_1);
            }
          }
        }
      }
    }
    CComQIPtr<>(&local_18,local_14[0]);
    local_8._0_1_ = 7;
    if ((-1 < iVar3) && (local_18 != (int *)0x0)) {
      local_2c = 0;
      iVar3 = (**(code **)(*local_14[0] + 0x124))(local_14[0],&local_2c);
      if ((-1 < iVar3) && (local_2c == 2)) {
        iVar3 = (**(code **)(*(int *)*param_2 + 0x3c))((int *)*param_2,&local_34);
        if ((-1 < iVar3) &&
           (iVar3 = (**(code **)(*local_18 + 0x158))(local_18,&local_30), -1 < iVar3)) {
          if (local_34 != local_30) {
            psVar5 = FUN_6812f174(this,local_30);
            iVar3 = FUN_6810248f(piVar2,param_3,PTR_u_Escapement_6815ff5c,psVar5);
          }
          if (((((-1 < iVar3) &&
                (iVar3 = (**(code **)(*(int *)*param_2 + 0x78))((int *)*param_2,&local_1c),
                -1 < iVar3)) &&
               (iVar3 = (**(code **)(*local_18 + 0x148))(local_18,&local_20), -1 < iVar3)) &&
              (iVar3 = (**(code **)(*local_18 + 0x140))(local_18,&param_1), -1 < iVar3)) &&
             ((local_1c != local_20 || (param_1 != (int *)0x0)))) {
            param_2 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,8);
            iVar3 = FUN_68124179(piVar2,param_3,PTR_u_FixedWidth_6815ff4c,(int *)&param_2);
            if (-1 < iVar3) {
              if (local_1c != local_20) {
                psVar5 = FUN_6812f174(this,(int)local_20);
                iVar3 = FUN_6810248f(piVar2,&param_2,PTR_u_Width_6815ff50,psVar5);
              }
              if ((-1 < iVar3) && (param_1 != (int *)0x0)) {
                puVar4 = FUN_6812ee84((int)param_1);
                iVar3 = FUN_6810248f(piVar2,&param_2,PTR_u_Align_6815ff54,puVar4);
              }
            }
            local_8._0_1_ = 7;
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 8))(param_2);
            }
          }
        }
        CComQIPtr<>(&local_24,local_14[0]);
        local_8._0_1_ = 9;
        if (local_24 != (int *)0x0) {
          param_2 = (int *)0x1;
          iVar3 = (**(code **)(*local_24 + 0x160))(local_24,&param_2);
          if ((-1 < iVar3) && (param_2 != (int *)0x1)) {
            psVar5 = FUN_6812f174(this,(int)param_2);
            iVar3 = FUN_6810248f(piVar2,param_3,PTR_u_MultiStroke_6815ff90,psVar5);
          }
        }
        local_8._0_1_ = 7;
        if (local_24 != (int *)0x0) {
          (**(code **)(*local_24 + 8))(local_24);
        }
      }
    }
    local_8._0_1_ = 1;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))(local_28);
    }
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar3;
}


