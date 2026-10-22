// Source: CiffHelper.dll @ 4081c2ec; FUN_4081c2ec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __thiscall FUN_4081c2ec(void *this,int *param_1)

{
  stringdispid *psVar1;
  BSTR pOVar2;
  bool bVar3;
  uint *puVar4;
  undefined4 *puVar5;
  void *extraout_EAX;
  uint uVar6;
  int **this_00;
  BSTR extraout_ECX;
  BSTR pOVar7;
  int *piVar8;
  int *piVar9;
  stringdispid *this_01;
  int iVar10;
  int *piVar11;
  _union_2683 local_54;
  int *local_44;
  undefined4 local_40;
  int *local_3c;
  stringdispid *local_38;
  int local_34 [2];
  void *local_2c;
  stringdispid *local_28;
  BSTR local_24;
  stringdispid *local_20;
  BSTR local_1c;
  BSTR local_18;
  BSTR local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x4081c2f8;
  if (*param_1 == 0) {
    uVar6 = (uint)this & 0xffffff00;
  }
  else {
    if (*(char *)((int)this + 0x80) == '\0') {
      local_40 = 0;
      local_2c = this;
      local_44 = (int *)FUN_4081d55e((int *)0x0,(int *)0x0);
      local_8 = 0;
      local_20 = (stringdispid *)0x0;
      local_38 = (stringdispid *)0x0;
      local_3c = (int *)FUN_4081d55e((int *)0x0,(int *)0x0);
      local_8 = CONCAT31(local_8._1_3_,1);
      (**(code **)(*(int *)*param_1 + 0x1c))();
      pOVar7 = local_14;
      local_24 = local_14;
      uVar6 = -(uint)((int)(ZEXT48(local_14) * 4 >> 0x20) != 0) | (uint)(ZEXT48(local_14) * 4);
      puVar4 = (uint *)FUN_4082c99b(-(uint)(0xfffffffb < uVar6) | uVar6 + 4);
      if (puVar4 == (uint *)0x0) {
        this_01 = (stringdispid *)0x0;
        local_28 = (stringdispid *)0x0;
      }
      else {
        *puVar4 = (uint)pOVar7;
        this_01 = (stringdispid *)(puVar4 + 1);
        local_28 = this_01;
        FUN_4082db06(this_01,4,(int)local_24,&LAB_40802e70);
      }
      local_24 = (BSTR)0x0;
      psVar1 = this_01;
      if (0 < (int)local_14) {
        do {
          local_20 = psVar1;
          FUN_40802e76((uint *)&local_54);
          local_24 = (BSTR)((int)local_24 + 1);
          local_8._0_1_ = 2;
          (**(code **)(*(int *)*param_1 + 0x30))((int *)*param_1);
          CComQIPtr<>(&local_20,(undefined4 *)local_54._8_4_);
          local_1c = (BSTR)0x0;
          local_8._0_1_ = 4;
          (**(code **)(*(int *)local_20 + 0xbc))(local_20,&local_1c);
          bVar3 = FUN_40803ed6(&local_1c,L"CurrentDate");
          if (bVar3) {
            this_00 = &local_44;
            piVar8 = local_44;
          }
          else {
            this_00 = &local_3c;
            piVar8 = local_3c;
          }
          FUN_4081a0e4(this_00,piVar8,(VARIANTARG *)&local_54.n2);
          local_18 = (BSTR)0x0;
          local_8._0_1_ = 5;
          (**(code **)(*(int *)local_20 + 0x1c))(local_20,&local_18);
          FUN_40803e5b(this_01,(int *)&local_18);
          SysFreeString(local_18);
          SysFreeString(local_1c);
          local_8._0_1_ = 2;
          if (local_20 != (stringdispid *)0x0) {
            (**(code **)(*(int *)local_20 + 8))();
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          VariantClear((VARIANTARG *)&local_54.n2);
          this_01 = this_01 + 4;
          psVar1 = local_20;
        } while ((int)local_24 < (int)local_14);
        local_20 = local_38;
        this_01 = local_28;
      }
      iVar10 = 0;
      if (0 < (int)local_14) {
        do {
          (**(code **)(*(int *)*param_1 + 0x24))();
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)local_14);
      }
      if (this_01 != (stringdispid *)0x0) {
        ATL::CComTypeInfoHolder::stringdispid::_vector_deleting_destructor_(this_01,3);
      }
      piVar8 = (int *)*local_44;
      if (piVar8 != local_44) {
        do {
          local_54._0_4_ = local_54._0_4_ & 0xffff0000;
          FUN_4080f8db(&local_54,(VARIANTARG *)(piVar8 + 2));
          local_8._0_1_ = 6;
          (**(code **)(*(int *)*param_1 + 0x38))
                    ((int *)*param_1,local_54._0_4_,local_54.decVal.Hi32);
          local_8 = CONCAT31(local_8._1_3_,1);
          VariantClear((VARIANTARG *)&local_54.n2);
          piVar8 = (int *)*piVar8;
        } while (piVar8 != local_44);
      }
      FUN_4081d601((int *)&local_44);
      piVar8 = local_3c;
      while (piVar9 = (int *)*piVar8, piVar9 != piVar8) {
        do {
          CComQIPtr<>(&local_1c,(undefined4 *)piVar9[4]);
          local_24 = (BSTR)0x0;
          local_8 = CONCAT31(local_8._1_3_,8);
          (**(code **)(*(int *)local_1c + 0xbc))();
          local_18 = (BSTR)&stack0xffffff98;
          piVar11 = (int *)*param_1;
          pOVar7 = (BSTR)0x0;
          pOVar2 = (BSTR)&stack0xffffff98;
          if (piVar11 != (int *)0x0) {
            (**(code **)(*piVar11 + 4))();
            pOVar7 = extraout_ECX;
            pOVar2 = local_18;
          }
          local_18 = pOVar2;
          local_8._0_1_ = 9;
          FUN_40803baf(&stack0xffffff94,(int *)&local_24);
          local_8._0_1_ = 8;
          FUN_4081bb85(&local_28,pOVar7,piVar11);
          local_8._0_1_ = 10;
          if (local_28 == (stringdispid *)0x0) {
            piVar9 = (int *)*piVar9;
          }
          else {
            (**(code **)(*(int *)*param_1 + 0x38))((int *)*param_1,piVar9[2],piVar9[3]);
            puVar5 = (undefined4 *)FUN_4081d62b(&local_3c,local_34,piVar9);
            piVar9 = (int *)*puVar5;
            piVar8 = local_3c;
          }
          local_8._0_1_ = 8;
          if (local_28 != (stringdispid *)0x0) {
            (**(code **)(*(int *)local_28 + 8))();
          }
          SysFreeString(local_24);
          local_8 = CONCAT31(local_8._1_3_,1);
          if (local_1c != (BSTR)0x0) {
            (**(code **)(*(int *)local_1c + 8))();
          }
        } while (piVar9 != piVar8);
        if (local_20 == local_38) break;
        local_20 = local_38;
      }
      *(undefined1 *)((int)local_2c + 0x80) = 1;
      FUN_4081d601((int *)&local_3c);
      FID_conflict__free(local_3c);
      FUN_4081d601((int *)&local_44);
      FID_conflict__free(local_44);
      this = extraout_EAX;
    }
    uVar6 = CONCAT31((int3)((uint)this >> 8),1);
  }
  return uVar6;
}


