// Source: CiffMgr.dll @ 6812d4ec; FUN_6812d4ec

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_6812d4ec(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  VARIANTARG *pvarg;
  int iVar1;
  UINT UVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  BSTR pOVar7;
  int **ppiVar8;
  _union_2683 local_a0;
  undefined4 *local_90;
  int *local_8c;
  int *local_88;
  uint local_84;
  int *local_80;
  BSTR local_7c;
  BSTR local_78;
  uint local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  VARTYPE local_64 [4];
  int local_5c [21];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94;
  local_80 = (int *)0x0;
  local_8c = param_1;
  local_90 = param_3;
  local_8 = 0;
  iVar1 = (**(code **)(*(int *)*param_2 + 0x20))((int *)*param_2,&local_80);
  CComQIPtr<>(&local_6c,local_80);
  local_68 = (int *)0x0;
  local_8._0_1_ = 2;
  if ((-1 < iVar1) && (local_6c != (int *)0x0)) {
    FUN_68132c04(local_64,0x10,5,FUN_6810213e);
    local_74 = 5;
    local_8 = CONCAT31(local_8._1_3_,3);
    (**(code **)(*local_6c + 0x14))(local_6c);
    do {
      if ((local_74 != 5) || (iVar1 < 0)) goto LAB_6812d753;
      (**(code **)(*local_6c + 0xc))(local_6c,5,local_64,&local_74);
      local_84 = 0;
      if (local_74 != 0) {
        piVar3 = local_5c;
        do {
          if (iVar1 < 0) break;
          pvarg = (VARIANTARG *)(piVar3 + -2);
          if (((pvarg->n1).n2.vt == 9) &&
             (puVar5 = (undefined4 *)*piVar3, puVar5 != (undefined4 *)0x0)) {
            iVar1 = (**(code **)*puVar5)(puVar5,&DAT_6814b074,&local_68);
          }
          if (iVar1 < 0) {
LAB_6812d721:
            piVar4 = local_68;
            if (local_68 != (int *)0x0) {
              local_68 = (int *)0x0;
              (**(code **)(*piVar4 + 8))(piVar4);
            }
          }
          else if (local_68 != (int *)0x0) {
            local_7c = (BSTR)0x0;
            local_8._0_1_ = 4;
            iVar1 = (**(code **)(*local_68 + 0x1c))(local_68,&local_7c);
            if (-1 < iVar1) {
              local_88 = (int *)0x0;
              ppiVar8 = &local_88;
              local_8._0_1_ = 5;
              piVar4 = (int *)*local_8c;
              puVar5 = local_90;
              puVar6 = PTR_u_Item_6815fd84;
              pOVar7 = local_7c;
              if (piVar4 != (int *)0x0) {
                (**(code **)(*piVar4 + 4))(piVar4);
              }
              FUN_68102315(piVar4,puVar5,puVar6,pOVar7,ppiVar8);
              local_78 = (BSTR)0x0;
              local_8._0_1_ = 6;
              iVar1 = (**(code **)(*local_68 + 0x24))(local_68,&local_78);
              if ((-1 < iVar1) && (UVar2 = SysStringLen(local_78), UVar2 != 0)) {
                local_70 = (int *)0x0;
                local_8._0_1_ = 7;
                iVar1 = (**(code **)(*local_88 + 0x44))(local_88,&local_70);
                if ((-1 < iVar1) && (local_70 != (int *)0x0)) {
                  local_a0.n2.vt = 0;
                  FUN_68102191(&local_a0,(int *)&local_78);
                  local_8._0_1_ = 8;
                  iVar1 = FUN_681021f5(local_8c,&local_70,PTR_DAT_68160100,(undefined4 *)&local_a0);
                  VariantClear((VARIANTARG *)&local_a0.n2);
                }
                local_8._0_1_ = 6;
                if (local_70 != (int *)0x0) {
                  (**(code **)(*local_70 + 8))(local_70);
                }
              }
              SysFreeString(local_78);
              local_8._0_1_ = 4;
              if (local_88 != (int *)0x0) {
                (**(code **)(*local_88 + 8))(local_88);
              }
            }
            local_8 = CONCAT31(local_8._1_3_,3);
            SysFreeString(local_7c);
            goto LAB_6812d721;
          }
          local_84 = local_84 + 1;
          piVar3 = piVar3 + 4;
          VariantClear(pvarg);
        } while (local_84 < local_74);
      }
    } while( true );
  }
LAB_6812d76e:
  local_8._0_1_ = 1;
  if (local_68 != (int *)0x0) {
    (**(code **)(*local_68 + 8))(local_68);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_6c != (int *)0x0) {
    (**(code **)(*local_6c + 8))(local_6c);
  }
  local_8 = 0xffffffff;
  if (local_80 != (int *)0x0) {
    (**(code **)(*local_80 + 8))(local_80);
  }
  FUN_681320d7();
  return;
LAB_6812d753:
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  _eh_vector_destructor_iterator_(local_64,0x10,5,FUN_68102159);
  goto LAB_6812d76e;
}


