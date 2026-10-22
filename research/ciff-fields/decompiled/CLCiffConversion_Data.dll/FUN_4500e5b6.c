// Source: CLCiffConversion_Data.dll @ 4500e5b6; FUN_4500e5b6

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4500e5b6(int param_1)

{
  wchar_t *pwVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  BSTR extraout_ECX_02;
  BSTR extraout_ECX_03;
  uint in_stack_ffffff70;
  undefined2 uVar5;
  undefined4 in_stack_ffffff74;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  BSTR pOVar9;
  _union_2683 local_70;
  BSTR local_5c;
  BSTR local_58;
  BSTR local_54;
  BSTR local_50;
  BSTR local_4c;
  BSTR local_48;
  BSTR local_44;
  BSTR local_40;
  wchar_t *local_3c;
  int *local_38;
  int *local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0x4500e5c2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Data::CreateConvertList");
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_3c = (wchar_t *)0x1;
  while ((int)local_3c < 10) {
    if (*(wchar_t **)(param_1 + 0x230) == local_3c) {
      local_34 = (int *)FUN_450213f3(0x108);
      local_8._0_1_ = 2;
      if (local_34 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = FUN_4500aac9(local_34,1);
      }
      local_8._0_1_ = 1;
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)(*(int *)(*piVar2 + 4) + (int)piVar2);
      }
      local_38 = piVar2;
      FUN_450022ba(piVar2 + 0xd,(int *)(param_1 + 0x30));
      piVar3 = FUN_45001f5d(&local_58,*(OLECHAR **)(param_1 + 0x140));
      local_8._0_1_ = 3;
      FUN_450022ea(piVar2 + 0x15,piVar3);
      local_8._0_1_ = 1;
      SysFreeString(local_58);
      piVar3 = FUN_45001f5d(&local_50,*(OLECHAR **)(param_1 + 0x170));
      local_8._0_1_ = 4;
      FUN_450022ea(piVar2 + 0x16,piVar3);
      local_8._0_1_ = 1;
      uVar6 = 0x4500e68d;
      SysFreeString(local_50);
      in_stack_ffffff70 = in_stack_ffffff70 & 0xffff0000;
      FUN_450102ee(&stack0xffffff70,(VARIANTARG *)(param_1 + 0xa8));
      FUN_45011368(piVar2,in_stack_ffffff70,in_stack_ffffff74,uVar6);
      uVar5 = (undefined2)(in_stack_ffffff70 >> 0x10);
      FUN_450102ee(&stack0xffffff70,(VARIANTARG *)(param_1 + 0xd8));
      FUN_45011333((int)piVar2);
      in_stack_ffffff70 = CONCAT22(uVar5,3);
      FUN_450112fe((int)piVar2);
      uVar6 = 0x4500e6f0;
      pOVar9 = extraout_ECX;
      FUN_45001f5d(&stack0xffffff7c,*(OLECHAR **)(param_1 + 0x4f0));
      uVar7 = 0x4500e6f7;
      FUN_450136b5(piVar2,pOVar9);
      FUN_4500abdc(&stack0xffffff70,*(int **)(param_1 + 0x380));
      FUN_450113ae(piVar2,in_stack_ffffff70,uVar6,uVar7);
      in_stack_ffffff74 = 0x4500e71f;
      FUN_4500503f((undefined4 *)(param_1 + 0x4e8),*(int **)(param_1 + 0x4e8),&local_38);
      if ((*(short *)(param_1 + 0x408) == 0xd) &&
         (piVar3 = *(int **)(param_1 + 0x410), piVar3 != (int *)0x0)) {
        local_38 = piVar3;
        (**(code **)(*piVar3 + 4))();
        FUN_450022ba(piVar2 + 0xe,(int *)&local_38);
        in_stack_ffffff74 = 0x4500e750;
        (**(code **)(*piVar3 + 8))();
      }
    }
    if (*(wchar_t **)(param_1 + 0x260) == local_3c) {
      local_34 = (int *)FUN_450213f3(0x110);
      local_8._0_1_ = 5;
      if (local_34 == (int *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = FUN_4500aafd(local_34,1);
      }
      local_8._0_1_ = 1;
      if (puVar4 == (undefined4 *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)((int)puVar4 + *(int *)(puVar4[1] + 4) + 4);
      }
      local_38 = piVar2;
      FUN_450022ba(piVar2 + 0xd,(int *)(param_1 + 0x30));
      piVar3 = FUN_45001f5d(&local_5c,*(OLECHAR **)(param_1 + 0x140));
      local_8._0_1_ = 6;
      FUN_450022ea(piVar2 + 0x15,piVar3);
      local_8._0_1_ = 1;
      SysFreeString(local_5c);
      piVar3 = FUN_45001f5d(&local_4c,*(OLECHAR **)(param_1 + 0x170));
      local_8._0_1_ = 7;
      FUN_450022ea(piVar2 + 0x16,piVar3);
      local_8 = CONCAT31(local_8._1_3_,1);
      uVar6 = 0x4500e802;
      SysFreeString(local_4c);
      in_stack_ffffff70 = in_stack_ffffff70 & 0xffff0000;
      FUN_450089b4(&stack0xffffff70,*(OLECHAR **)(param_1 + 0xb0));
      FUN_45011368(piVar2,in_stack_ffffff70,in_stack_ffffff74,uVar6);
      uVar5 = (undefined2)(in_stack_ffffff70 >> 0x10);
      FUN_450089b4(&stack0xffffff70,*(OLECHAR **)(param_1 + 0xe0));
      FUN_45011333((int)piVar2);
      FUN_450089b4(&stack0xffffff70,*(OLECHAR **)(param_1 + 0x2c0));
      FUN_450113ed((int)piVar2);
      FUN_450089b4(&stack0xffffff70,*(OLECHAR **)(param_1 + 0x2f0));
      FUN_45011422((int)piVar2);
      in_stack_ffffff70 = CONCAT22(uVar5,3);
      FUN_450112fe((int)piVar2);
      uVar6 = 0x4500e89f;
      pOVar9 = extraout_ECX_00;
      FUN_45001f5d(&stack0xffffff7c,*(OLECHAR **)(param_1 + 0x4f0));
      uVar7 = 0x4500e8a6;
      FUN_450136b5(piVar2,pOVar9);
      *(bool *)((int)piVar2 + 0x45) = *(short *)(param_1 + 0x3e0) != 0;
      local_70._8_4_ = *(int *)(param_1 + 0x380);
      local_70.n2.vt = 9;
      if ((int *)local_70._8_4_ != (int *)0x0) {
        uVar7 = 0x4500e8d0;
        (**(code **)(*(int *)local_70._8_4_ + 4))();
      }
      local_8 = CONCAT31(local_8._1_3_,8);
      in_stack_ffffff70 = in_stack_ffffff70 & 0xffff0000;
      FUN_450102ee(&stack0xffffff70,(VARIANTARG *)&local_70.n2);
      FUN_450113ae(piVar2,in_stack_ffffff70,uVar6,uVar7);
      FUN_45011284(piVar2,*(int *)(param_1 + 0x200));
      piVar3 = FUN_45001f5d(&local_48,*(OLECHAR **)(param_1 + 800));
      FUN_450058c3(piVar2 + 2,piVar3);
      SysFreeString(local_48);
      pOVar9 = extraout_ECX_01;
      FUN_45001ef3(&stack0xffffff7c,(int *)(param_1 + 0x4f4));
      FUN_4501374e(piVar2,pOVar9);
      if ((*(short *)(param_1 + 0x408) == 0xd) &&
         (piVar3 = *(int **)(param_1 + 0x410), piVar3 != (int *)0x0)) {
        local_34 = piVar3;
        (**(code **)(*piVar3 + 4))();
        FUN_450022ba(piVar2 + 0xe,(int *)&local_34);
        (**(code **)(*piVar3 + 8))();
      }
      *(bool *)((int)piVar2 + 0xfd) = *(int *)(param_1 + 0x4a0) != 0;
      in_stack_ffffff74 = 0x4500e980;
      FUN_4500503f((undefined4 *)(param_1 + 0x4e8),*(int **)(param_1 + 0x4e8),&local_38);
      local_8._0_1_ = 1;
      VariantClear((VARIANTARG *)&local_70.n2);
    }
    pwVar1 = local_3c;
    if (*(wchar_t **)(param_1 + 0x290) == local_3c) {
      local_34 = (int *)FUN_450213f3(0x108);
      local_8._0_1_ = 9;
      if (local_34 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = FUN_4500aa91(local_34,1);
      }
      local_8._0_1_ = 1;
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)(*(int *)(*piVar2 + 4) + (int)piVar2);
      }
      local_38 = piVar2;
      FUN_450022ba(piVar2 + 0xd,(int *)(param_1 + 0x30));
      piVar3 = FUN_45001f5d(&local_54,*(OLECHAR **)(param_1 + 0x80));
      local_8._0_1_ = 10;
      FUN_450022ea(piVar2 + 0x10,piVar3);
      local_8._0_1_ = 1;
      SysFreeString(local_54);
      piVar3 = FUN_45001f5d(&local_44,*(OLECHAR **)(param_1 + 0x140));
      local_8._0_1_ = 0xb;
      FUN_450022ea(piVar2 + 0x15,piVar3);
      local_8._0_1_ = 1;
      SysFreeString(local_44);
      piVar3 = FUN_45001f5d(&local_40,*(OLECHAR **)(param_1 + 0x170));
      local_8._0_1_ = 0xc;
      FUN_450022ea(piVar2 + 0x16,piVar3);
      local_8._0_1_ = 1;
      uVar6 = 0x4500ea5e;
      SysFreeString(local_40);
      in_stack_ffffff70 = in_stack_ffffff70 & 0xffff0000;
      FUN_450102ee(&stack0xffffff70,(VARIANTARG *)(param_1 + 0xa8));
      FUN_45011368(piVar2,in_stack_ffffff70,in_stack_ffffff74,uVar6);
      uVar5 = (undefined2)(in_stack_ffffff70 >> 0x10);
      FUN_450102ee(&stack0xffffff70,(VARIANTARG *)(param_1 + 0xd8));
      FUN_45011333((int)piVar2);
      in_stack_ffffff70 = CONCAT22(uVar5,3);
      FUN_450112fe((int)piVar2);
      uVar6 = 0x4500eac1;
      pOVar9 = extraout_ECX_02;
      FUN_45001f5d(&stack0xffffff7c,*(OLECHAR **)(param_1 + 0x4f0));
      uVar7 = 0x4500eac8;
      FUN_450136b5(piVar2,pOVar9);
      FUN_4500abdc(&stack0xffffff70,*(int **)(param_1 + 0x380));
      FUN_450113ae(piVar2,in_stack_ffffff70,uVar6,uVar7);
      *(bool *)(piVar2 + 0x11) = *(short *)(param_1 + 0x3b0) != 0;
      in_stack_ffffff74 = 0x4500eb00;
      FUN_4500503f((undefined4 *)(param_1 + 0x4e8),*(int **)(param_1 + 0x4e8),&local_38);
    }
    if (*(wchar_t **)(param_1 + 0x440) == pwVar1) {
      piVar2 = (int *)FUN_450213f3(0x110);
      local_8._0_1_ = 0xd;
      local_34 = piVar2;
      if (piVar2 == (int *)0x0) {
        local_38 = (int *)0x0;
      }
      else {
        iVar8 = 1;
        piVar3 = *(int **)(param_1 + 0x30);
        if (piVar3 != (int *)0x0) {
          in_stack_ffffff70 = 0x4500eb36;
          (**(code **)(*piVar3 + 4))();
        }
        local_38 = FUN_4500561c(piVar2,piVar3,iVar8);
      }
      local_8._0_1_ = 1;
      if (local_38 == (int *)0x0) {
        local_38 = (int *)0x0;
      }
      else {
        local_38 = (int *)(*(int *)(*local_38 + 4) + (int)local_38);
      }
      FUN_450022ba(local_38 + 0xd,(int *)(param_1 + 0x30));
      in_stack_ffffff74 = 0x4500eb76;
      FUN_4500503f((undefined4 *)(param_1 + 0x4e8),*(int **)(param_1 + 0x4e8),&local_38);
    }
    local_3c = (wchar_t *)((int)pwVar1 + 1);
  }
  FUN_45002050(&local_3c,"Capi");
  iVar8 = _wcscmp(*(wchar_t **)(param_1 + 0x4f0),local_3c);
  FUN_45002256((int *)&local_3c);
  if (iVar8 == 0) {
    local_40 = (BSTR)FUN_450213f3(0x108);
    local_8._0_1_ = 0xe;
    if (local_40 == (BSTR)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = FUN_4500ab3e(local_40,1);
    }
    local_8._0_1_ = 1;
    if (puVar4 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)((int)puVar4 + *(int *)(puVar4[1] + 4) + 4);
    }
    local_38 = piVar2;
    FUN_450022ba(piVar2 + 0xd,(int *)(param_1 + 0x30));
    pOVar9 = extraout_ECX_03;
    FUN_45001f5d(&stack0xffffff7c,*(OLECHAR **)(param_1 + 0x4f0));
    FUN_450136b5(piVar2,pOVar9);
    if ((*(short *)(param_1 + 0x408) == 0xd) &&
       (pOVar9 = *(BSTR *)(param_1 + 0x410), pOVar9 != (BSTR)0x0)) {
      local_40 = pOVar9;
      (**(code **)(*(int *)pOVar9 + 4))();
      FUN_450022ba(piVar2 + 0xe,(int *)&local_40);
      (**(code **)(*(int *)pOVar9 + 8))();
    }
    FUN_4500503f((undefined4 *)(param_1 + 0x4e8),*(int **)(param_1 + 0x4e8),&local_38);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4500ecb3();
  return;
}


