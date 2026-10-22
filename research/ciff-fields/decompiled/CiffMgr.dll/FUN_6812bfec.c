// Source: CiffMgr.dll @ 6812bfec; FUN_6812bfec

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void FUN_6812bfec(BSTR param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_9c [16];
  VARIANTARG *local_8c;
  undefined4 *local_84;
  int *local_80;
  int *local_7c;
  int *local_78;
  BSTR local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  VARTYPE local_64 [4];
  int local_5c [21];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x8c;
  local_74 = param_1;
  local_84 = param_3;
  local_78 = param_4;
  local_68 = (int *)0x0;
  local_8 = 0;
  iVar3 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_68);
  if ((-1 < iVar3) && (local_68 != (int *)0x0)) {
    FUN_68132710((uint *)local_9c,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_9c)->n2);
    local_9c._0_2_ = 8;
    local_9c._8_4_ = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar3 = (**(code **)(*(int *)*param_2 + 0x34))
                      ((int *)*param_2,&(((_union_2683 *)local_9c)->n2).n3);
    if (-1 < iVar3) {
      iVar3 = FUN_681021f5((undefined4 *)local_74,&local_68,PTR_u_ImageReference_68160044,
                           (undefined4 *)local_9c);
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_9c)->n2);
  }
  local_8 = 0xffffffff;
  if (local_68 != (int *)0x0) {
    (**(code **)(*local_68 + 8))(local_68);
  }
  if (iVar3 < 0) goto LAB_6812c2c0;
  local_68 = (int *)0x0;
  local_8 = 2;
  iVar3 = FUN_68124179((undefined4 *)local_74,local_84,PTR_u_SubHeader_6815fcb4,(int *)&local_68);
  if (-1 < iVar3) {
    iVar3 = FUN_6812c2ca((int *)local_74,param_2,&local_68,local_78);
  }
  local_8 = 0xffffffff;
  if (local_68 != (int *)0x0) {
    (**(code **)(*local_68 + 8))(local_68);
  }
  if (iVar3 < 0) goto LAB_6812c2c0;
  local_78 = (int *)0x0;
  local_8 = 3;
  iVar3 = (**(code **)(*(int *)*param_2 + 0x20))((int *)*param_2,&local_78);
  CComQIPtr<>(&local_70,local_78);
  local_6c = (int *)0x0;
  local_8._0_1_ = 5;
  if ((-1 < iVar3) && (local_70 != (int *)0x0)) {
    FUN_68132c04(local_64,0x10,5,FUN_6810213e);
    local_7c = (int *)0x5;
    local_8 = CONCAT31(local_8._1_3_,6);
    (**(code **)(*local_70 + 0x14))(local_70);
    do {
      if ((local_7c != (int *)0x5) || (iVar3 < 0)) goto LAB_6812c276;
      (**(code **)(*local_70 + 0xc))(local_70,5,local_64,&local_7c);
      local_68 = (int *)0x0;
      if (local_7c != (int *)0x0) {
        piVar4 = local_5c;
        do {
          if (iVar3 < 0) break;
          local_8c = (VARIANTARG *)(piVar4 + -2);
          if (((local_8c->n1).n2.vt == 9) &&
             (puVar1 = (undefined4 *)*piVar4, puVar1 != (undefined4 *)0x0)) {
            iVar3 = (**(code **)*puVar1)(puVar1,&DAT_6814a33c,&local_6c);
          }
          if (iVar3 < 0) {
LAB_6812c23d:
            piVar2 = local_6c;
            if (local_6c != (int *)0x0) {
              local_6c = (int *)0x0;
              (**(code **)(*piVar2 + 8))(piVar2);
            }
          }
          else if (local_6c != (int *)0x0) {
            local_80 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,7);
            iVar3 = FUN_68124179((undefined4 *)local_74,local_84,PTR_u_Field_6815fcd8,
                                 (int *)&local_80);
            if (-1 < iVar3) {
              iVar3 = FUN_68128924(local_74,(BSTR)&local_6c,&local_80);
            }
            local_8 = CONCAT31(local_8._1_3_,6);
            if (local_80 != (int *)0x0) {
              (**(code **)(*local_80 + 8))(local_80);
            }
            goto LAB_6812c23d;
          }
          local_68 = (int *)((int)local_68 + 1);
          piVar4 = piVar4 + 4;
          VariantClear(local_8c);
        } while (local_68 < local_7c);
      }
    } while( true );
  }
LAB_6812c290:
  local_8._0_1_ = 4;
  if (local_6c != (int *)0x0) {
    (**(code **)(*local_6c + 8))(local_6c);
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (local_70 != (int *)0x0) {
    (**(code **)(*local_70 + 8))(local_70);
  }
  local_8 = 0xffffffff;
  if (local_78 != (int *)0x0) {
    (**(code **)(*local_78 + 8))(local_78);
  }
LAB_6812c2c0:
  FUN_681320d7();
  return;
LAB_6812c276:
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 5;
  _eh_vector_destructor_iterator_(local_64,0x10,5,FUN_68102159);
  goto LAB_6812c290;
}


