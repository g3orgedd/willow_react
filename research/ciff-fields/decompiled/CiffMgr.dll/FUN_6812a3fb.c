// Source: CiffMgr.dll @ 6812a3fb; FUN_6812a3fb

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_6812a3fb(BSTR param_1,undefined4 *param_2,undefined4 *param_3)

{
  VARIANTARG *pvarg;
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  OLECHAR *psz;
  int *piVar4;
  _union_2683 local_a4;
  undefined4 *local_94;
  void *local_90;
  int local_8c;
  BSTR local_88;
  int *local_84;
  uint local_80;
  int local_7c;
  int *local_78;
  uint local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  VARTYPE local_64 [4];
  int local_5c [21];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94;
  local_94 = param_3;
  local_88 = param_1;
  local_7c = 0;
  local_70 = (int *)0x0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  iVar3 = (**(code **)(**(int **)param_1 + 0xbc))
                    (*(int **)param_1,PTR_u_ImageMapping_6815fea4,&local_70);
  if (((iVar3 < 0) || (local_70 == (int *)0x0)) ||
     (iVar3 = (**(code **)(*(int *)*param_2 + 0x1c))((int *)*param_2,&local_8c), iVar3 < 0))
  goto LAB_6812a70c;
  if (local_8c != 1) {
    local_68 = (int *)0x0;
    local_8._0_1_ = 1;
    iVar3 = (**(code **)(*local_70 + 0x44))(local_70,&local_68);
    if ((-1 < iVar3) && (local_68 != (int *)0x0)) {
      FUN_68132710((uint *)&local_a4,0,0x10);
      VariantInit((VARIANTARG *)&local_a4.n2);
      local_8._0_1_ = 2;
      local_7c = 1;
      local_a4.n2.vt = 8;
      psz = FUN_6812f174(local_90,local_8c);
      local_a4._8_4_ = SysAllocString(psz);
      iVar3 = FUN_681021f5((undefined4 *)param_1,&local_68,PTR_u_PrintHeadDigits_68160098,
                           (undefined4 *)&local_a4);
      VariantClear((VARIANTARG *)&local_a4.n2);
    }
    local_8._0_1_ = 0;
    if (local_68 != (int *)0x0) {
      (**(code **)(*local_68 + 8))(local_68);
    }
  }
  if (iVar3 < 0) goto LAB_6812a70c;
  local_78 = (int *)0x0;
  local_8._0_1_ = 3;
  iVar3 = (**(code **)(*(int *)*param_2 + 0x38))((int *)*param_2,&local_78);
  CComQIPtr<>(&local_68,local_78);
  local_6c = (int *)0x0;
  local_8._0_1_ = 5;
  if ((-1 < iVar3) && (local_68 != (int *)0x0)) {
    FUN_68132c04(local_64,0x10,5,FUN_6810213e);
    local_74 = 5;
    local_8 = CONCAT31(local_8._1_3_,6);
    iVar3 = (**(code **)(*local_68 + 0x14))(local_68);
    do {
      if ((local_74 != 5) || (iVar3 < 0)) goto LAB_6812a6a0;
      iVar3 = (**(code **)(*local_68 + 0xc))(local_68,5,local_64,&local_74);
      local_80 = 0;
      if (local_74 != 0) {
        piVar4 = local_5c;
        do {
          if (iVar3 < 0) break;
          pvarg = (VARIANTARG *)(piVar4 + -2);
          if (((pvarg->n1).n2.vt == 9) &&
             (puVar1 = (undefined4 *)*piVar4, puVar1 != (undefined4 *)0x0)) {
            iVar3 = (**(code **)*puVar1)(puVar1,&DAT_68148474,&local_6c);
          }
          if (iVar3 < 0) {
LAB_6812a66b:
            piVar2 = local_6c;
            if (local_6c != (int *)0x0) {
              local_6c = (int *)0x0;
              (**(code **)(*piVar2 + 8))(piVar2);
            }
          }
          else if (local_6c != (int *)0x0) {
            local_84 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,7);
            iVar3 = FUN_68124179((undefined4 *)local_88,&local_70,PTR_DAT_6815fea8,(int *)&local_84)
            ;
            if (-1 < iVar3) {
              local_7c = 1;
              iVar3 = FUN_6812a2da(local_88,(int *)&local_6c,&local_84);
            }
            local_8 = CONCAT31(local_8._1_3_,6);
            if (local_84 != (int *)0x0) {
              (**(code **)(*local_84 + 8))(local_84);
            }
            goto LAB_6812a66b;
          }
          local_80 = local_80 + 1;
          piVar4 = piVar4 + 4;
          VariantClear(pvarg);
        } while (local_80 < local_74);
      }
    } while( true );
  }
LAB_6812a6ba:
  local_8._0_1_ = 4;
  if (local_6c != (int *)0x0) {
    (**(code **)(*local_6c + 8))(local_6c);
  }
  local_8._0_1_ = 3;
  if (local_68 != (int *)0x0) {
    (**(code **)(*local_68 + 8))(local_68);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_78 != (int *)0x0) {
    (**(code **)(*local_78 + 8))(local_78);
  }
  if ((-1 < iVar3) && (local_7c != 0)) {
    (**(code **)(*(int *)*local_94 + 0x54))((int *)*local_94,local_70,0);
  }
LAB_6812a70c:
  local_8 = 0xffffffff;
  if (local_70 != (int *)0x0) {
    (**(code **)(*local_70 + 8))(local_70);
  }
  FUN_681320d7();
  return;
LAB_6812a6a0:
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 5;
  _eh_vector_destructor_iterator_(local_64,0x10,5,FUN_68102159);
  goto LAB_6812a6ba;
}


