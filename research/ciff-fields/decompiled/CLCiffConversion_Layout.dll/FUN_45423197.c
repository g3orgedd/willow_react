// Source: CLCiffConversion_Layout.dll @ 45423197; FUN_45423197

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_45423197(int *param_1,int *param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  _union_2683 local_64;
  _union_2683 local_54;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int *local_2c;
  int local_28;
  BSTR local_24;
  BSTR local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x454231a3;
  local_30 = 0;
  iVar3 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_30);
  if (-1 < iVar3) {
    local_38 = 0x3f800000;
    local_34 = 0x3f800000;
    iVar3 = (**(code **)(*(int *)*param_1 + 0x54))((int *)*param_1,&local_3c);
    if ((-1 < iVar3) && (local_3c == 0)) {
      (**(code **)(*(int *)*param_2 + 0x2c))((int *)*param_2,&local_38);
      (**(code **)(*(int *)*param_2 + 0x34))((int *)*param_2,&local_34);
    }
    thunk_FUN_45409c9b((int *)(local_1c + 0x100));
    iVar4 = 0;
    if (0 < local_30) {
      do {
        local_14[0] = (int *)0x0;
        local_8 = 0;
        FUN_45429f70((uint *)&local_64,0,0x10);
        VariantInit((VARIANTARG *)&local_64.n2);
        iVar4 = iVar4 + 1;
        local_8._0_1_ = 1;
        local_40 = iVar4;
        iVar3 = (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,iVar4,&local_64);
        if ((((-1 < iVar3) && (local_64.n2.vt == 9)) &&
            (iVar3 = (*(code *)**(undefined4 **)local_64._8_4_)
                               (local_64._8_4_,&DAT_45447c3c,local_14), -1 < iVar3)) &&
           (local_14[0] != (int *)0x0)) {
          local_2c = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_454228de(param_2,local_14,&local_2c);
          local_28 = 0;
          iVar3 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&local_28);
          if ((-1 < iVar3) && (iVar5 = 0, iVar4 = local_40, 0 < local_28)) {
            do {
              local_18 = (int *)0x0;
              FUN_45429f70((uint *)&local_54,0,0x10);
              VariantInit((VARIANTARG *)&local_54.n2);
              local_44 = iVar5 + 1;
              local_8._0_1_ = 4;
              bVar1 = false;
              iVar3 = (**(code **)(*local_14[0] + 0x24))(local_14[0],local_44,&local_54);
              if (((iVar3 < 0) ||
                  ((local_54.n2.vt != 9 ||
                   (iVar3 = (*(code *)**(undefined4 **)local_54._8_4_)
                                      (local_54._8_4_,&DAT_45447c4c,&local_18), iVar3 < 0)))) ||
                 (local_18 == (int *)0x0)) {
LAB_454233f4:
                iVar5 = local_44;
              }
              else {
                local_24 = (BSTR)0x0;
                local_8._0_1_ = 5;
                iVar3 = (**(code **)(*local_18 + 0x68))(local_18,&local_24);
                if ((-1 < iVar3) && (bVar2 = FUN_45402d4b(&local_24,L"RichText"), bVar2)) {
                  local_20 = (BSTR)0x0;
                  local_8._0_1_ = 6;
                  (**(code **)(*local_18 + 0x1c))(local_18,&local_20);
                  (**(code **)(*local_14[0] + 0x2c))(local_14[0],local_20);
                  piVar6 = local_14[0];
                  piVar7 = param_1;
                  if (local_14[0] != (int *)0x0) {
                    (**(code **)(*local_14[0] + 4))
                              (local_14[0],local_14[0],param_1,local_3c,local_38,local_34);
                  }
                  iVar3 = FUN_454229a0((int *)&local_2c,(int *)&local_18,piVar6,piVar7);
                  bVar1 = true;
                  SysFreeString(local_20);
                }
                SysFreeString(local_24);
                if (!bVar1) goto LAB_454233f4;
              }
              VariantClear((VARIANTARG *)&local_54.n2);
              local_8 = CONCAT31(local_8._1_3_,2);
              if (local_18 != (int *)0x0) {
                (**(code **)(*local_18 + 8))(local_18);
              }
              iVar4 = local_40;
            } while (iVar5 < local_28);
          }
          local_8._0_1_ = 1;
          if (local_2c != (int *)0x0) {
            (**(code **)(*local_2c + 8))(local_2c);
          }
        }
        VariantClear((VARIANTARG *)&local_64.n2);
        local_8 = 0xffffffff;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
      } while (iVar4 < local_30);
    }
  }
  return iVar3;
}


