// Source: CLCiffConversion_Data.dll @ 45010bdd; FUN_45010bdd

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_45010bdd(long *param_1,long *param_2,long *param_3,uint *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  size_t sVar3;
  long lVar4;
  wchar_t ****ppppwVar5;
  long *plVar6;
  uint uVar7;
  uint *puVar8;
  wchar_t *in_stack_0000002c;
  char in_stack_00000030;
  undefined *local_7c;
  wchar_t *local_78;
  long *local_74;
  uint local_70;
  long *local_6c;
  long *local_68;
  uint *local_64;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_60 [24];
  wchar_t **local_48 [4];
  undefined4 local_38;
  undefined4 local_34;
  wchar_t ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_68 = param_1;
  local_74 = param_2;
  local_6c = param_3;
  local_64 = param_4;
  local_78 = in_stack_0000002c;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_60,"CIFFDatabaseResolve::ProcessSubString");
  local_70 = *(uint *)(in_stack_0000002c + 8);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_70 != 0) {
    if (in_stack_00000030 == '\0') {
      local_34 = 7;
      local_38 = 0;
      local_48[0]._0_2_ = 0;
      local_8 = CONCAT31(local_8._1_3_,3);
      uVar7 = 0;
      while ((int)uVar7 <= (int)local_70) {
        puVar2 = FUN_45014419(local_78,local_30,uVar7,local_70 - uVar7);
        FUN_4500589e(local_48,puVar2);
        FUN_450046d9(local_30,'\x01',0);
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
        sVar3 = _wcslen(L"cl:Z");
        FID_conflict_assign(local_30,(undefined8 *)L"cl:Z",sVar3);
        iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
        FUN_450046d9(local_30,'\x01',0);
        if (iVar1 == 0) {
          local_1c = 7;
          local_20 = 0;
          local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
          sVar3 = _wcslen(L"cl:sc");
          FID_conflict_assign(local_30,(undefined8 *)L"cl:sc",sVar3);
          FUN_4500589e(local_48,(undefined8 *)local_30);
          FUN_450046d9(local_30,'\x01',0);
        }
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
        sVar3 = _wcslen(L"cl:X");
        FID_conflict_assign(local_30,(undefined8 *)L"cl:X",sVar3);
        iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
        FUN_450046d9(local_30,'\x01',0);
        if (iVar1 == 0) {
          local_1c = 7;
          local_20 = 0;
          local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
          sVar3 = _wcslen(L"cl:hhc");
          FID_conflict_assign(local_30,(undefined8 *)L"cl:hhc",sVar3);
          FUN_4500589e(local_48,(undefined8 *)local_30);
          FUN_450046d9(local_30,'\x01',0);
        }
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
        sVar3 = _wcslen(L"d");
        FID_conflict_assign(local_30,(undefined8 *)&DAT_4503f588,sVar3);
        iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
        FUN_450046d9(local_30,'\x01',0);
        puVar8 = local_64;
        if (iVar1 == 0) {
          FUN_45014419(&stack0x00000014,local_30,*local_64,1);
          ppppwVar5 = local_30;
          if (7 < local_1c) {
            ppppwVar5 = (wchar_t ****)local_30[0];
          }
          lVar4 = __wtol((wchar_t *)ppppwVar5);
          plVar6 = local_68;
          goto LAB_45010e2b;
        }
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
        sVar3 = _wcslen(L"dd");
        FID_conflict_assign(local_30,(undefined8 *)&DAT_4503f58c,sVar3);
        iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
        FUN_450046d9(local_30,'\x01',0);
        puVar8 = local_64;
        if (iVar1 == 0) {
          FUN_45014419(&stack0x00000014,local_30,*local_64,2);
          ppppwVar5 = local_30;
          if (7 < local_1c) {
            ppppwVar5 = (wchar_t ****)local_30[0];
          }
          lVar4 = __wtol((wchar_t *)ppppwVar5);
          plVar6 = local_68;
          goto LAB_45011214;
        }
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
        sVar3 = _wcslen(L"ddd");
        FID_conflict_assign(local_30,(undefined8 *)&DAT_4503f594,sVar3);
        iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
        FUN_450046d9(local_30,'\x01',0);
        puVar8 = local_64;
        if (iVar1 == 0) {
          FUN_45014419(&stack0x00000014,local_30,*local_64,3);
          ppppwVar5 = local_30;
          if (7 < local_1c) {
            ppppwVar5 = (wchar_t ****)local_30[0];
          }
          lVar4 = __wtol((wchar_t *)ppppwVar5);
          *local_68 = lVar4;
          *puVar8 = *puVar8 + 3;
LAB_45011219:
          FUN_450046d9(local_30,'\x01',0);
        }
        else {
          local_1c = 7;
          local_20 = 0;
          local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
          sVar3 = _wcslen(L"M");
          FID_conflict_assign(local_30,(undefined8 *)&DAT_4503df0c,sVar3);
          iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
          FUN_450046d9(local_30,'\x01',0);
          puVar8 = local_64;
          if (iVar1 == 0) {
            FUN_45014419(&stack0x00000014,local_30,*local_64,1);
            ppppwVar5 = local_30;
            if (7 < local_1c) {
              ppppwVar5 = (wchar_t ****)local_30[0];
            }
            lVar4 = __wtol((wchar_t *)ppppwVar5);
            plVar6 = local_74;
LAB_45010e2b:
            *plVar6 = lVar4;
            *puVar8 = *puVar8 + 1;
            goto LAB_45011219;
          }
          local_1c = 7;
          local_20 = 0;
          local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
          sVar3 = _wcslen(L"MM");
          FID_conflict_assign(local_30,(undefined8 *)&DAT_4503f59c,sVar3);
          iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
          FUN_450046d9(local_30,'\x01',0);
          puVar8 = local_64;
          if (iVar1 == 0) {
            FUN_45014419(&stack0x00000014,local_30,*local_64,2);
            ppppwVar5 = local_30;
            if (7 < local_1c) {
              ppppwVar5 = (wchar_t ****)local_30[0];
            }
            lVar4 = __wtol((wchar_t *)ppppwVar5);
            plVar6 = local_74;
LAB_45011214:
            *plVar6 = lVar4;
            *puVar8 = *puVar8 + 2;
            goto LAB_45011219;
          }
          local_1c = 7;
          local_20 = 0;
          local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
          sVar3 = _wcslen(L"y");
          FID_conflict_assign(local_30,(undefined8 *)&DAT_4503f5a4,sVar3);
          iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
          FUN_450046d9(local_30,'\x01',0);
          puVar8 = local_64;
          if (iVar1 == 0) {
            FUN_45014419(&stack0x00000014,local_30,*local_64,1);
            ppppwVar5 = local_30;
            if (7 < local_1c) {
              ppppwVar5 = (wchar_t ****)local_30[0];
            }
            lVar4 = __wtol((wchar_t *)ppppwVar5);
            plVar6 = local_6c;
            goto LAB_45010e2b;
          }
          local_1c = 7;
          local_20 = 0;
          local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
          sVar3 = _wcslen(L"yy");
          FID_conflict_assign(local_30,(undefined8 *)&DAT_4503f5a8,sVar3);
          iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
          FUN_450046d9(local_30,'\x01',0);
          puVar8 = local_64;
          if (iVar1 == 0) {
            FUN_45014419(&stack0x00000014,local_30,*local_64,2);
            ppppwVar5 = local_30;
            if (7 < local_1c) {
              ppppwVar5 = (wchar_t ****)local_30[0];
            }
            lVar4 = __wtol((wchar_t *)ppppwVar5);
            plVar6 = local_6c;
            goto LAB_45011214;
          }
          local_1c = 7;
          local_20 = 0;
          local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
          sVar3 = _wcslen(L"yyyy");
          FID_conflict_assign(local_30,(undefined8 *)L"yyyy",sVar3);
          iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
          FUN_450046d9(local_30,'\x01',0);
          puVar8 = local_64;
          if (iVar1 == 0) {
            FUN_45014419(&stack0x00000014,local_30,*local_64,4);
            ppppwVar5 = local_30;
            if (7 < local_1c) {
              ppppwVar5 = (wchar_t ****)local_30[0];
            }
            lVar4 = __wtol((wchar_t *)ppppwVar5);
            *local_6c = lVar4;
            *puVar8 = *puVar8 + 4;
            goto LAB_45011219;
          }
          local_1c = 7;
          local_20 = 0;
          local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
          sVar3 = _wcslen(L"cl:ww");
          FID_conflict_assign(local_30,(undefined8 *)L"cl:ww",sVar3);
          iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
          FUN_450046d9(local_30,'\x01',0);
          if (iVar1 == 0) {
LAB_450111e9:
            puVar8 = local_64;
            FUN_45014419(&stack0x00000014,local_30,*local_64,2);
            ppppwVar5 = local_30;
            if (7 < local_1c) {
              ppppwVar5 = (wchar_t ****)local_30[0];
            }
            lVar4 = __wtol((wchar_t *)ppppwVar5);
            lVar4 = lVar4 * 7;
            plVar6 = local_68;
            goto LAB_45011214;
          }
          local_1c = 7;
          local_20 = 0;
          local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
          sVar3 = _wcslen(L"cl:wwz");
          FID_conflict_assign(local_30,(undefined8 *)L"cl:wwz",sVar3);
          iVar1 = FUN_45007b0d(local_48,(wchar_t *)local_30);
          FUN_450046d9(local_30,'\x01',0);
          if (iVar1 == 0) goto LAB_450111e9;
        }
        uVar7 = local_70 + 1;
        local_7c = PTR_DAT_4505101c;
        FUN_45002256((int *)&local_7c);
      }
      ppppwVar5 = (wchar_t ****)local_48;
    }
    else {
      FUN_45014419(&stack0x00000014,local_30,*param_4,local_70);
      iVar1 = FUN_45007b0d(local_30,in_stack_0000002c);
      ppppwVar5 = local_30;
      if (iVar1 != 0) {
        FUN_450046d9(ppppwVar5,'\x01',0);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_60,true,0)
        ;
        goto LAB_45011270;
      }
    }
    FUN_450046d9(ppppwVar5,'\x01',0);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_60,true,0);
LAB_45011270:
  FUN_450046d9(&stack0x00000014,'\x01',0);
  FUN_45022ec7();
  return;
}


