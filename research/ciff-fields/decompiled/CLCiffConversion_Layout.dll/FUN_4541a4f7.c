// Source: CLCiffConversion_Layout.dll @ 4541a4f7; FUN_4541a4f7

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541a4f7(void *this,int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  BSTR extraout_ECX;
  int iVar3;
  BSTR pOVar4;
  int *local_64;
  int *local_60;
  int *local_5c;
  int *local_58;
  int *local_54;
  int *local_50;
  int *local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  undefined4 *local_3c;
  int *local_38;
  undefined4 *local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0;
  if (*(int *)((int)this + 0x3c) == 0) {
    local_8 = 0xffffffff;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))();
    }
    FUN_4541ae04();
    return;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::CreateConvertList");
  local_8._0_1_ = 2;
  for (iVar3 = 1; iVar3 < 10; iVar3 = iVar3 + 1) {
    if (*(int *)((int)this + 0x480) == iVar3) {
      local_34 = (undefined4 *)FUN_454298b4(0x108);
      local_8._0_1_ = 3;
      if (local_34 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = FUN_45422826(local_34);
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_8._0_1_ = 2;
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_5c);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_5c != (int *)0x0) {
        (**(code **)(*local_5c + 8))();
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x240) == iVar3) {
      local_34 = (undefined4 *)FUN_454298b4(0x108);
      local_8._0_1_ = 4;
      if (local_34 == (undefined4 *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = FUN_454128f0(local_34,1);
      }
      local_8._0_1_ = 2;
      if (piVar2 == (int *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)(*(int *)(*piVar2 + 4) + (int)piVar2);
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_50);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_50 != (int *)0x0) {
        (**(code **)(*local_50 + 8))();
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x270) == iVar3) {
      local_34 = (undefined4 *)FUN_454298b4(0x110);
      local_8._0_1_ = 5;
      if (local_34 == (undefined4 *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = FUN_45412995(local_34,1);
      }
      local_8._0_1_ = 2;
      if (piVar2 == (int *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)(*(int *)(*piVar2 + 4) + (int)piVar2);
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_58);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_58 != (int *)0x0) {
        (**(code **)(*local_58 + 8))();
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x2a0) == iVar3) {
      local_34 = (undefined4 *)FUN_454298b4(0x108);
      local_8._0_1_ = 6;
      if (local_34 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = FUN_45412958(local_34,1);
      }
      local_8._0_1_ = 2;
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)((int)puVar1 + *(int *)(puVar1[1] + 4) + 4);
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_60);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_60 != (int *)0x0) {
        (**(code **)(*local_60 + 8))();
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x3c0) == iVar3) {
      local_34 = (undefined4 *)FUN_454298b4(0x108);
      local_8._0_1_ = 7;
      if (local_34 == (undefined4 *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = FUN_45412924(local_34,1);
      }
      local_8._0_1_ = 2;
      if (piVar2 == (int *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)(*(int *)(*piVar2 + 4) + (int)piVar2);
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_64);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_64 != (int *)0x0) {
        (**(code **)(*local_64 + 8))();
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x2d0) == iVar3) {
      local_34 = (undefined4 *)FUN_454298b4(0x110);
      local_8._0_1_ = 8;
      if (local_34 == (undefined4 *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = FUN_454129dd(local_34,1);
      }
      local_8._0_1_ = 2;
      if (piVar2 == (int *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)(*(int *)(*piVar2 + 4) + (int)piVar2);
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
      FUN_45404ce5(puVar1 + 0x37,(int *)&param_1);
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_4c);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_4c != (int *)0x0) {
        (**(code **)(*local_4c + 8))();
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x300) == iVar3) {
      puVar1 = (undefined4 *)FUN_454298b4(0x100);
      local_8._0_1_ = 9;
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        local_34 = puVar1;
        FUN_454127a6(puVar1);
        *puVar1 = CCIFFFieldOrder::vftable;
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_8._0_1_ = 2;
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_40);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_40 != (int *)0x0) {
        (**(code **)(*local_40 + 8))();
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x330) == iVar3) {
      puVar1 = (undefined4 *)FUN_454298b4(0x100);
      local_8._0_1_ = 10;
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        local_34 = puVar1;
        FUN_454127a6(puVar1);
        *puVar1 = CCIFFPosition::vftable;
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_8._0_1_ = 2;
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
      FUN_45404ce5(puVar1 + 0x37,(int *)&param_1);
      pOVar4 = extraout_ECX;
      FUN_454028b9(&stack0xffffff84,*(char **)((int)this + 0x4dc));
      FUN_45421480(puVar1,pOVar4);
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_54);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_54 != (int *)0x0) {
        (**(code **)(*local_54 + 8))();
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x360) == iVar3) {
      puVar1 = (undefined4 *)FUN_454298b4(0x100);
      local_8._0_1_ = 0xb;
      local_3c = puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        FUN_454127a6(puVar1);
        *puVar1 = CCIFFAddTabFields::vftable;
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_8._0_1_ = 2;
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_44);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_44 != (int *)0x0) {
        (**(code **)(*local_44 + 8))();
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x390) == iVar3) {
      puVar1 = (undefined4 *)FUN_454298b4(0x108);
      local_8._0_1_ = 0xc;
      local_3c = puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        FUN_454127a6(puVar1);
        *puVar1 = CCIFFTag::vftable;
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_8._0_1_ = 2;
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_48);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_48 != (int *)0x0) {
        (**(code **)(*local_48 + 8))();
      }
      puVar1[0x13] = this;
      if (*(short *)((int)this + 0x118) == 8) {
        FUN_45401cab(puVar1 + 0x12,*(OLECHAR **)((int)this + 0x120));
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x3f0) == iVar3) {
      puVar1 = (undefined4 *)FUN_454298b4(0x100);
      local_8._0_1_ = 0xd;
      local_3c = puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        FUN_454127a6(puVar1);
        *puVar1 = CLZipher_CiffField::vftable;
      }
      puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
      local_8._0_1_ = 2;
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
      piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_38);
      FUN_45404ce5(puVar1 + 0xf,piVar2);
      if (local_38 != (int *)0x0) {
        (**(code **)(*local_38 + 8))();
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
    if (*(int *)((int)this + 0x450) == iVar3) {
      local_3c = (undefined4 *)FUN_454298b4(0x108);
      local_8._0_1_ = 0xe;
      if (local_3c == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = FUN_45423725(local_3c);
      }
      local_8._0_1_ = 2;
      local_34 = puVar1;
      FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
      FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
      FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
      puVar1[0x13] = this;
      if (*(short *)((int)this + 0x118) == 8) {
        FUN_45401cab(puVar1 + 0x12,*(OLECHAR **)((int)this + 0x120));
      }
      FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
    }
  }
  puVar1 = (undefined4 *)FUN_454298b4(0x100);
  local_8._0_1_ = 0xf;
  local_3c = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_454127a6(puVar1);
    *puVar1 = CCiffPriceVerifierBarcodes::vftable;
  }
  puVar1[0xc] = *(undefined4 *)((int)this + 0x4e8);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_34 = puVar1;
  FUN_45404ce5(puVar1 + 0xd,(int *)((int)this + 0x30));
  FUN_45404ce5(puVar1 + 0xe,(int *)((int)this + 0x38));
  FUN_45404ce5(puVar1 + 0x1b,(int *)((int)this + 0x40));
  piVar2 = FUN_45415515(*(void **)((int)this + 0x3c),(int *)&local_38);
  FUN_45404ce5(puVar1 + 0xf,piVar2);
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))();
  }
  FUN_4541222d((undefined4 *)((int)this + 0x4c8),*(int **)((int)this + 0x4c8),&local_34);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  FUN_4541ae04();
  return;
}


