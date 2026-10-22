// Source: CiffMgr.dll @ 68129475; FUN_68129475

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

int __thiscall FUN_68129475(void *this,int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  short *psVar3;
  undefined *puVar4;
  OLECHAR *psz;
  int *piVar5;
  int iVar6;
  undefined1 local_40 [16];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int *local_1c;
  void *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  local_18 = this;
  iVar2 = (*(code *)**(undefined4 **)*param_2)((undefined4 *)*param_2,&DAT_6814a9b8,local_14);
  if (((iVar2 < 0) || (local_14[0] == (int *)0x0)) ||
     (iVar2 = (**(code **)(*local_14[0] + 0xa8))(local_14[0],&local_2c), iVar2 < 0))
  goto LAB_681299a3;
  psVar3 = FUN_6812f174(this,local_2c);
  piVar1 = param_1;
  iVar2 = FUN_6810248f(param_1,param_3,PTR_u_GfxW_6815fe74,psVar3);
  if ((iVar2 < 0) || (iVar2 = (**(code **)(*local_14[0] + 0xb0))(local_14[0],&param_2), iVar2 < 0))
  goto LAB_681299a3;
  psVar3 = FUN_6812f174(this,(int)param_2);
  iVar2 = FUN_6810248f(piVar1,param_3,PTR_u_GfxH_6815fe78,psVar3);
  if ((iVar2 < 0) || (iVar2 = (**(code **)(*local_14[0] + 0xb8))(local_14[0],&local_30), iVar2 < 0))
  goto LAB_681299a3;
  if (((local_30 == 1) || (local_30 == 2)) || (local_30 == 3)) {
    piVar5 = (int *)PTR_u_StaticGfx_6815fe7c;
    if (((local_30 != 1) && (piVar5 = (int *)PTR_u_VariableGfx_6815fe84, local_30 != 2)) &&
       (piVar5 = param_3, local_30 == 3)) {
      piVar5 = (int *)PTR_u_EmbeddedGfx_6815fe88;
    }
    param_2 = (int *)0x0;
    local_8._0_1_ = 1;
    iVar2 = FUN_68124179(piVar1,param_3,piVar5,(int *)&param_2);
    piVar5 = param_2;
    if ((-1 < iVar2) &&
       (iVar2 = (**(code **)(*local_14[0] + 0xbc))(local_14[0],&local_28), piVar5 = param_2,
       -1 < iVar2)) {
      if (local_28 != 1) {
        puVar4 = FUN_6812e9d1(local_28);
        iVar2 = FUN_6810248f(piVar1,&param_2,PTR_u_AspectRatio_6815fe8c,puVar4);
      }
      piVar5 = param_2;
      if ((-1 < iVar2) &&
         (iVar2 = (**(code **)(*local_14[0] + 0xc4))(local_14[0],&param_3), piVar5 = param_2,
         -1 < iVar2)) {
        if (param_3 != (int *)0x0) {
          puVar4 = FUN_6812e9d1((int)param_3);
          iVar2 = FUN_6810248f(piVar1,&param_2,PTR_u_ResizeFrame_6815fe90,puVar4);
        }
        piVar5 = param_2;
        if (-1 < iVar2) {
          CComQIPtr<>(&param_1,local_14[0]);
          local_8._0_1_ = 2;
          if (param_1 != (int *)0x0) {
            param_3 = (int *)0x0;
            iVar2 = (**(code **)(*param_1 + 0xfc))(param_1,&param_3);
            if ((-1 < iVar2) && (param_3 != (int *)0x0)) {
              puVar4 = FUN_6812e9d1((int)param_3);
              iVar2 = FUN_6810248f(piVar1,&param_2,PTR_u_LogoReferencePrinter_6815fff4,puVar4);
            }
          }
          local_8._0_1_ = 1;
          piVar5 = param_2;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
            piVar5 = param_2;
          }
        }
      }
    }
  }
  else {
    if (local_30 != 0) goto LAB_681299a3;
    param_1 = (int *)0x0;
    local_8._0_1_ = 3;
    iVar2 = FUN_68124179(piVar1,param_3,PTR_u_Primitive_6815fe80,(int *)&param_1);
    piVar5 = param_1;
    if ((-1 < iVar2) &&
       (iVar2 = (**(code **)(*local_14[0] + 0xcc))(local_14[0],&local_28), piVar5 = param_1,
       -1 < iVar2)) {
      puVar4 = FUN_6812f9be(local_28);
      iVar2 = FUN_6810248f(piVar1,&param_1,PTR_u_Shape_6815fe94,puVar4);
      piVar5 = param_1;
      if ((-1 < iVar2) &&
         (iVar2 = (**(code **)(*local_14[0] + 0xd4))(local_14[0],&param_3), piVar5 = param_1,
         -1 < iVar2)) {
        psVar3 = FUN_6812f174(local_18,(int)param_3);
        iVar2 = FUN_6810248f(piVar1,&param_1,PTR_u_LineW_6815fe98,psVar3);
        piVar5 = param_1;
        if (-1 < iVar2) {
          local_24 = 0;
          iVar2 = (**(code **)(*local_14[0] + 0xdc))(local_14[0],&local_24);
          piVar5 = param_1;
          if ((-1 < iVar2) && (local_24 != 0)) {
            param_2 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,4);
            iVar2 = FUN_68124179(piVar1,&param_1,PTR_u_ComplexShape_6815fe9c,(int *)&param_2);
            if ((-1 < iVar2) && (param_2 != (int *)0x0)) {
              if (local_28 == 0) {
                local_20 = 2;
              }
              else {
                if (2 < local_28 - 5U) {
                  local_20 = 0;
                  goto LAB_68129843;
                }
                iVar2 = (**(code **)(*local_14[0] + 0xf0))(local_14[0],&local_20);
              }
              param_3 = (int *)0x0;
              if (0 < local_20) {
                iVar6 = 0;
                do {
                  if (iVar2 < 0) break;
                  local_1c = (int *)0x0;
                  local_8._0_1_ = 5;
                  iVar2 = FUN_68124179(piVar1,&param_2,PTR_u_Point_6815fea0,(int *)&local_1c);
                  if ((-1 < iVar2) && (local_1c != (int *)0x0)) {
                    param_3 = (int *)0x0;
                    local_8._0_1_ = 6;
                    iVar2 = (**(code **)(*local_1c + 0x44))(local_1c,&param_3);
                    if ((-1 < iVar2) && (param_3 != (int *)0x0)) {
                      FUN_68132710((uint *)local_40,0,0x10);
                      VariantInit((VARIANTARG *)&((_union_2683 *)local_40)->n2);
                      local_40._8_4_ = 0;
                      local_8._0_1_ = 7;
                      local_40._0_2_ = 8;
                      psz = FUN_6812f174(local_18,iVar6);
                      local_40._8_4_ = SysAllocString(psz);
                      iVar2 = FUN_681021f5(piVar1,&param_3,PTR_DAT_6816008c,(undefined4 *)local_40);
                      if (-1 < iVar2) {
                        SysFreeString((BSTR)local_40._8_4_);
                        local_40._8_4_ = (BSTR)0x0;
                        local_40._0_2_ = 3;
                        iVar2 = (**(code **)(*local_14[0] + 0xe0))
                                          (local_14[0],iVar6,&(((_union_2683 *)local_40)->n2).n3);
                        if ((-1 < iVar2) &&
                           (iVar2 = FUN_681021f5(piVar1,&param_3,PTR_DAT_68160090,
                                                 (undefined4 *)local_40), -1 < iVar2)) {
                          local_40._8_4_ = (BSTR)0x0;
                          local_40._0_2_ = 3;
                          iVar2 = (**(code **)(*local_14[0] + 0xe8))
                                            (local_14[0],iVar6,&(((_union_2683 *)local_40)->n2).n3);
                          if (-1 < iVar2) {
                            iVar2 = FUN_681021f5(piVar1,&param_3,PTR_DAT_68160094,
                                                 (undefined4 *)local_40);
                          }
                        }
                      }
                      VariantClear((VARIANTARG *)&((_union_2683 *)local_40)->n2);
                    }
                    local_8._0_1_ = 5;
                    if (param_3 != (int *)0x0) {
                      (**(code **)(*param_3 + 8))(param_3);
                    }
                  }
                  local_8 = CONCAT31(local_8._1_3_,4);
                  if (local_1c != (int *)0x0) {
                    (**(code **)(*local_1c + 8))(local_1c);
                  }
                  iVar6 = iVar6 + 1;
                } while (iVar6 < local_20);
              }
            }
LAB_68129843:
            local_8._0_1_ = 3;
            piVar5 = param_1;
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 8))(param_2);
              piVar5 = param_1;
            }
          }
        }
      }
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
  }
LAB_681299a3:
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar2;
}


