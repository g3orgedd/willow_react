// Source: CiffMgr.dll @ 6812adb8; FUN_6812adb8

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_6812adb8(BSTR param_1,undefined4 *param_2,undefined4 *param_3)

{
  VARIANTARG *pvarg;
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint unaff_EBX;
  int *piVar4;
  int *local_80;
  uint local_7c;
  int *local_78;
  uint local_74;
  uint local_70;
  int *local_6c;
  int *local_68;
  VARTYPE local_64 [4];
  int local_5c [21];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_78 = (int *)0x0;
  local_8 = 0;
  iVar3 = (**(code **)(*(int *)*param_2 + 0x20))((int *)*param_2,&local_78);
  CComQIPtr<>(&local_6c,local_78);
  local_68 = (int *)0x0;
  local_74 = unaff_EBX & 0xffffff00;
  local_8._0_1_ = 2;
  if ((-1 < iVar3) && (local_6c != (int *)0x0)) {
    FUN_68132c04(local_64,0x10,5,FUN_6810213e);
    local_70 = 5;
    local_8 = CONCAT31(local_8._1_3_,3);
    (**(code **)(*local_6c + 0x14))(local_6c);
    do {
      if ((local_70 != 5) || (iVar3 < 0)) goto LAB_6812af4e;
      iVar3 = (**(code **)(*local_6c + 0xc))(local_6c,5,local_64,&local_70);
      local_7c = 0;
      if (local_70 != 0) {
        piVar4 = local_5c;
        do {
          if (iVar3 < 0) break;
          pvarg = (VARIANTARG *)(piVar4 + -2);
          if (((pvarg->n1).n2.vt == 9) &&
             (puVar1 = (undefined4 *)*piVar4, puVar1 != (undefined4 *)0x0)) {
            iVar3 = (**(code **)*puVar1)(puVar1,&DAT_68149cf4,&local_68);
          }
          if (iVar3 < 0) {
LAB_6812af16:
            piVar2 = local_68;
            if (local_68 != (int *)0x0) {
              local_68 = (int *)0x0;
              (**(code **)(*piVar2 + 8))(piVar2);
            }
          }
          else if (local_68 != (int *)0x0) {
            local_80 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,4);
            iVar3 = FUN_68124179((undefined4 *)param_1,param_3,PTR_u_ParamSet_6815ff00,
                                 (int *)&local_80);
            if (-1 < iVar3) {
              iVar3 = FUN_6812ab09(param_1,&local_68,&local_80);
              local_74 = local_74 & 0xff;
              if (iVar3 == 0) {
                local_74 = 1;
              }
            }
            local_8 = CONCAT31(local_8._1_3_,3);
            if (local_80 != (int *)0x0) {
              (**(code **)(*local_80 + 8))(local_80);
            }
            goto LAB_6812af16;
          }
          local_7c = local_7c + 1;
          piVar4 = piVar4 + 4;
          VariantClear(pvarg);
        } while (local_7c < local_70);
      }
    } while( true );
  }
LAB_6812af69:
  local_8._0_1_ = 1;
  if (local_68 != (int *)0x0) {
    (**(code **)(*local_68 + 8))(local_68);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_6c != (int *)0x0) {
    (**(code **)(*local_6c + 8))(local_6c);
  }
  local_8 = 0xffffffff;
  if (local_78 != (int *)0x0) {
    (**(code **)(*local_78 + 8))(local_78);
  }
  FUN_681320d7();
  return;
LAB_6812af4e:
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  _eh_vector_destructor_iterator_(local_64,0x10,5,FUN_68102159);
  goto LAB_6812af69;
}


