// Source: CiffMgr.dll @ 6812ab09; FUN_6812ab09

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void FUN_6812ab09(BSTR param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_a0 [16];
  VARIANTARG *local_90;
  undefined4 *local_8c;
  BSTR local_84;
  int *local_80;
  uint local_7c;
  int *local_78;
  int *local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  VARTYPE local_64 [4];
  int local_5c [21];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x90;
  local_84 = param_1;
  local_8c = param_3;
  local_7c = local_7c & 0xffffff00;
  local_68 = (int *)0x0;
  local_8 = 0;
  iVar3 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_68);
  if ((-1 < iVar3) && (local_68 != (int *)0x0)) {
    FUN_68132710((uint *)local_a0,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_a0)->n2);
    local_a0._8_4_ = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    local_a0._0_2_ = 8;
    iVar3 = (**(code **)(*(int *)*param_2 + 0x34))
                      ((int *)*param_2,&(((_union_2683 *)local_a0)->n2).n3);
    if (-1 < iVar3) {
      iVar3 = FUN_681021f5((undefined4 *)local_84,&local_68,PTR_u_Name_68160030,
                           (undefined4 *)local_a0);
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_a0)->n2);
  }
  local_8 = 0xffffffff;
  if (local_68 != (int *)0x0) {
    (**(code **)(*local_68 + 8))(local_68);
  }
  if (iVar3 < 0) goto LAB_6812ada1;
  local_78 = (int *)0x0;
  local_8 = 2;
  iVar3 = (**(code **)(*(int *)*param_2 + 0x20))((int *)*param_2,&local_78);
  CComQIPtr<>(&local_70,local_78);
  local_6c = (int *)0x0;
  local_8._0_1_ = 4;
  if ((-1 < iVar3) && (local_70 != (int *)0x0)) {
    FUN_68132c04(local_64,0x10,5,FUN_6810213e);
    local_74 = (int *)0x5;
    local_8 = CONCAT31(local_8._1_3_,5);
    (**(code **)(*local_70 + 0x14))(local_70);
    do {
      if ((local_74 != (int *)0x5) || (iVar3 < 0)) goto LAB_6812ad55;
      iVar3 = (**(code **)(*local_70 + 0xc))(local_70,5,local_64,&local_74);
      local_68 = (int *)0x0;
      if (local_74 != (int *)0x0) {
        piVar4 = local_5c;
        do {
          if (iVar3 < 0) break;
          local_90 = (VARIANTARG *)(piVar4 + -2);
          if (((local_90->n1).n2.vt == 9) &&
             (puVar1 = (undefined4 *)*piVar4, puVar1 != (undefined4 *)0x0)) {
            iVar3 = (**(code **)*puVar1)(puVar1,&DAT_68149e14,&local_6c);
          }
          if (iVar3 < 0) {
LAB_6812ad1e:
            piVar2 = local_6c;
            if (local_6c != (int *)0x0) {
              local_6c = (int *)0x0;
              (**(code **)(*piVar2 + 8))(piVar2);
            }
          }
          else if (local_6c != (int *)0x0) {
            local_80 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,6);
            iVar3 = FUN_68124179((undefined4 *)local_84,local_8c,PTR_u_Param_6815ff04,
                                 (int *)&local_80);
            if (-1 < iVar3) {
              iVar3 = FUN_6812a7d3(local_84,(int *)&local_6c,(int *)&local_80);
              local_7c = local_7c & 0xff;
              if (iVar3 == 0) {
                local_7c = 1;
              }
            }
            local_8 = CONCAT31(local_8._1_3_,5);
            if (local_80 != (int *)0x0) {
              (**(code **)(*local_80 + 8))(local_80);
            }
            goto LAB_6812ad1e;
          }
          local_68 = (int *)((int)local_68 + 1);
          piVar4 = piVar4 + 4;
          VariantClear(local_90);
        } while (local_68 < local_74);
      }
    } while( true );
  }
LAB_6812ad71:
  local_8._0_1_ = 3;
  if (local_6c != (int *)0x0) {
    (**(code **)(*local_6c + 8))(local_6c);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_70 != (int *)0x0) {
    (**(code **)(*local_70 + 8))(local_70);
  }
  local_8 = 0xffffffff;
  if (local_78 != (int *)0x0) {
    (**(code **)(*local_78 + 8))(local_78);
  }
LAB_6812ada1:
  FUN_681320d7();
  return;
LAB_6812ad55:
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  _eh_vector_destructor_iterator_(local_64,0x10,5,FUN_68102159);
  goto LAB_6812ad71;
}


