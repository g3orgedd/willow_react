// Source: CiffMgr.dll @ 6812dc1c; FUN_6812dc1c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

int FUN_6812dc1c(SAFEARRAY *param_1,SAFEARRAY *param_2,undefined4 *param_3,undefined4 param_4,
                int *param_5)

{
  SAFEARRAY *pSVar1;
  SAFEARRAY *pSVar2;
  int iVar3;
  _union_2683 local_3c;
  undefined1 local_2c [16];
  int *local_1c [2];
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar3 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,local_14);
  pSVar2 = param_2;
  pSVar1 = param_1;
  if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
    CComQIPtr<>(local_1c,*(undefined4 **)param_2);
    local_8._0_1_ = 1;
    if (local_1c[0] != (int *)0x0) {
      param_2 = (SAFEARRAY *)0x1;
      iVar3 = (**(code **)(*local_1c[0] + 0xd0))(local_1c[0],&param_2);
      if ((-1 < iVar3) && (param_2 != (SAFEARRAY *)0x1)) {
        FUN_68132710((uint *)&local_3c,0,0x10);
        VariantInit((VARIANTARG *)&local_3c.n2);
        local_3c.n2.vt = 3;
        local_3c._8_4_ = param_2;
        local_8._0_1_ = 2;
        FUN_681021f5((undefined4 *)pSVar1,local_14,PTR_u_Version_681600f4,(undefined4 *)&local_3c);
        VariantClear((VARIANTARG *)&local_3c.n2);
      }
    }
    FUN_68132710((uint *)local_2c,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_2c)->n2);
    local_2c._8_4_ = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    local_2c._0_2_ = 8;
    iVar3 = (**(code **)(**(int **)pSVar2 + 0x5c))
                      (*(int **)pSVar2,&(((_union_2683 *)local_2c)->n2).n3);
    if (((-1 < iVar3) && ((BSTR)local_2c._8_4_ != (BSTR)0x0)) &&
       (*(OLECHAR *)local_2c._8_4_ != L'\0')) {
      iVar3 = FUN_681021f5((undefined4 *)pSVar1,local_14,PTR_u_InternalName_68160020,
                           (undefined4 *)local_2c);
    }
    SysFreeString((BSTR)local_2c._8_4_);
    local_2c._8_4_ = SysAllocString((OLECHAR *)PTR_u_default_68160014);
    if (-1 < iVar3) {
      FUN_681021f5((undefined4 *)pSVar1,local_14,PTR_u_xml_space_681600a0,(undefined4 *)local_2c);
    }
    param_1 = (SAFEARRAY *)0x0;
    iVar3 = (**(code **)(**(int **)pSVar2 + 0x9c))(*(int **)pSVar2,&param_1);
    if ((-1 < iVar3) && (param_1 == (SAFEARRAY *)0x1)) {
      FUN_68132710((uint *)&local_3c,0,0x10);
      VariantInit((VARIANTARG *)&local_3c.n2);
      local_3c.n2.vt = 3;
      local_3c._8_4_ = param_1;
      local_8 = CONCAT31(local_8._1_3_,4);
      iVar3 = FUN_681021f5((undefined4 *)pSVar1,local_14,PTR_u_Temporary_681600a8,
                           (undefined4 *)&local_3c);
      VariantClear((VARIANTARG *)&local_3c.n2);
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_2c)->n2);
    local_8 = local_8 & 0xffffff00;
    if (local_1c[0] != (int *)0x0) {
      (**(code **)(*local_1c[0] + 8))(local_1c[0]);
    }
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  if (-1 < iVar3) {
    param_1 = (SAFEARRAY *)0x0;
    local_8 = 5;
    iVar3 = FUN_68124179((undefined4 *)pSVar1,param_3,PTR_u_Header_6815fc40,(int *)&param_1);
    if (-1 < iVar3) {
      iVar3 = FUN_68129bfc((BSTR)pSVar1,(BSTR)pSVar2,&param_1);
    }
    local_8 = 0xffffffff;
    if (param_1 != (SAFEARRAY *)0x0) {
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
    if ((-1 < iVar3) &&
       (iVar3 = FUN_6812cad1((BSTR)pSVar1,(undefined4 *)pSVar2,param_3), -1 < iVar3)) {
      FUN_68132710((uint *)&local_3c,0,0x10);
      VariantInit((VARIANTARG *)&local_3c.n2);
      local_8 = 6;
      iVar3 = (**(code **)(**(int **)pSVar2 + 0x80))(*(int **)pSVar2,&local_3c);
      if ((-1 < iVar3) && (local_3c.n2.vt == 9)) {
        param_2 = (SAFEARRAY *)0x0;
        local_8._0_1_ = 7;
        iVar3 = (*(code *)**(undefined4 **)local_3c._8_4_)(local_3c._8_4_,&DAT_681488c8,&param_2);
        if ((-1 < iVar3) && (param_2 != (SAFEARRAY *)0x0)) {
          param_1 = (SAFEARRAY *)0x0;
          local_8 = CONCAT31(local_8._1_3_,8);
          iVar3 = FUN_68124179((undefined4 *)pSVar1,param_3,PTR_u_GenericSettings_6815fc48,
                               (int *)&param_1);
          if (-1 < iVar3) {
            iVar3 = FUN_6812932f((BSTR)pSVar1,(int *)&param_2,&param_1);
          }
          local_8._0_1_ = 7;
          if (param_1 != (SAFEARRAY *)0x0) {
            (**(code **)(*(int *)param_1 + 8))(param_1);
          }
        }
        local_8 = CONCAT31(local_8._1_3_,6);
        if (param_2 != (SAFEARRAY *)0x0) {
          (**(code **)(*(int *)param_2 + 8))(param_2);
        }
      }
      local_8 = 0xffffffff;
      VariantClear((VARIANTARG *)&local_3c.n2);
      if ((-1 < iVar3) && (((uint)param_5 & 1) == 0)) {
        FUN_68132710((uint *)&local_3c,0,0x10);
        VariantInit((VARIANTARG *)&local_3c.n2);
        local_8 = 9;
        iVar3 = (**(code **)(**(int **)pSVar2 + 0xac))(*(int **)pSVar2,&local_3c);
        if ((-1 < iVar3) && (local_3c.n2.vt == 9)) {
          param_2 = (SAFEARRAY *)0x0;
          local_8._0_1_ = 10;
          iVar3 = (*(code *)**(undefined4 **)local_3c._8_4_)(local_3c._8_4_,&DAT_68148970,&param_2);
          if ((-1 < iVar3) && (param_2 != (SAFEARRAY *)0x0)) {
            local_1c[0] = (int *)0x0;
            iVar3 = (**(code **)(*(int *)param_2 + 0x24))(param_2,local_1c);
            if ((-1 < iVar3) && (0 < (int)local_1c[0])) {
              param_5 = (int *)0x0;
              local_8 = CONCAT31(local_8._1_3_,0xb);
              iVar3 = FUN_68124179((undefined4 *)pSVar1,param_3,PTR_u_Embedded_6815feb4,
                                   (int *)&param_5);
              if (-1 < iVar3) {
                iVar3 = FUN_68128755(pSVar1,&param_2,&param_5,param_4);
              }
              local_8._0_1_ = 10;
              if (param_5 != (int *)0x0) {
                (**(code **)(*param_5 + 8))(param_5);
              }
            }
          }
          local_8 = CONCAT31(local_8._1_3_,9);
          if (param_2 != (SAFEARRAY *)0x0) {
            (**(code **)(*(int *)param_2 + 8))(param_2);
          }
        }
        VariantClear((VARIANTARG *)&local_3c.n2);
      }
    }
  }
  return iVar3;
}


