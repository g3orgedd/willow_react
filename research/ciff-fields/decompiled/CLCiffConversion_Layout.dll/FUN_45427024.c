// Source: CLCiffConversion_Layout.dll @ 45427024; FUN_45427024

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_45427024(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

{
  HKEY pHVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  size_t sVar7;
  CRegKey *this_00;
  HKEY local_1160;
  undefined4 local_115c;
  undefined4 local_1158;
  HKEY local_1154;
  undefined4 local_1150;
  undefined4 local_114c;
  HKEY local_1148;
  undefined4 local_1144;
  undefined4 local_1140;
  int local_113c;
  HKEY local_1138;
  undefined4 local_1134;
  undefined4 local_1130;
  HKEY local_112c;
  undefined4 local_1128;
  undefined4 local_1124;
  HKEY local_1120;
  uint local_111c;
  char local_1118 [4096];
  byte local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_45446351;
  local_10 = ExceptionList;
  local_14 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1120 = param_2;
  local_112c = (HKEY)0x0;
  local_1128 = 0;
  local_1124 = 0;
  local_8 = 0;
  uStack_7 = 0;
LAB_45427084:
  iVar3 = FUN_45426781(this,(undefined1 *)param_1);
  do {
    if (iVar3 < 0) {
LAB_454275b8:
      ATL::CRegKey::Close((CRegKey *)&local_112c);
      ExceptionList = local_10;
      FUN_4542a8d1(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_45427096:
    if ((char)*param_1 == '}') goto LAB_454275b8;
    local_113c = 1;
    iVar3 = lstrcmpiA((LPCSTR)param_1,"Delete");
    local_111c = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiA((LPCSTR)param_1,"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_45426781(this,(undefined1 *)param_1);
      if (iVar3 < 0) goto LAB_454275b8;
      if (param_3 == 0) goto LAB_454271a5;
      local_1138 = (HKEY)0x0;
      local_1134 = 0;
      local_1130 = 0;
      pcVar5 = FUN_45427c18((LPCSTR)param_1,'\\');
      if (pcVar5 == (char *)0x0) {
        iVar3 = FUN_45425642((LPCSTR)param_1);
        if (iVar3 != 0) {
          local_1138 = local_1120;
          local_1134 = 0;
          local_1130 = 0;
          ATL::CRegKey::RecurseDeleteKey((CRegKey *)&local_1138,(char *)param_1);
          local_1138 = (HKEY)0x0;
          local_1134 = 0;
          local_1130 = 0;
        }
        if (local_111c == 0) {
          ATL::CRegKey::Close((CRegKey *)&local_1138);
          goto LAB_454271a5;
        }
        iVar3 = FUN_45426781(this,(undefined1 *)param_1);
        if (-1 < iVar3) {
          iVar3 = FUN_45427b90(this,(char *)param_1);
          ATL::CRegKey::Close((CRegKey *)&local_1138);
LAB_45427189:
          if (-1 < iVar3) goto LAB_4542755f;
          goto LAB_454275b8;
        }
        this_00 = (CRegKey *)&local_1138;
        goto LAB_454275f2;
      }
      ATL::CRegKey::Close((CRegKey *)&local_1138);
      goto LAB_454275b8;
    }
LAB_454271a5:
    iVar3 = lstrcmpiA((LPCSTR)param_1,"NoRemove");
    if (iVar3 == 0) {
      local_113c = 0;
      iVar3 = FUN_45426781(this,(undefined1 *)param_1);
      if (iVar3 < 0) goto LAB_454275b8;
    }
    iVar3 = lstrcmpiA((LPCSTR)param_1,"Val");
    if (iVar3 != 0) {
      pcVar5 = FUN_45427c18((LPCSTR)param_1,'\\');
      pHVar1 = local_1120;
      if (pcVar5 == (char *)0x0) {
        if (param_3 == 0) {
          if (param_4 == 0) {
            local_111c = Open(&local_112c,local_1120,(LPCSTR)param_1,0x20019);
          }
          else {
            local_111c = 2;
          }
          iVar3 = param_4;
          if (local_111c != 0) {
            iVar3 = 1;
          }
          iVar4 = FUN_4542a6d4(local_118,0x104,(byte *)param_1,0xffffffff);
          FUN_45402fb2(iVar4);
          iVar4 = FUN_45426781(this,(undefined1 *)param_1);
          if (((-1 < iVar4) && (iVar4 = FUN_45427b90(this,(char *)param_1), -1 < iVar4)) &&
             ((((char)*param_1 != '{' || (sVar7 = _strlen((char *)param_1), sVar7 != 1)) ||
              (((iVar4 = FUN_45427024(this,param_1,local_112c,0,iVar3), -1 < iVar4 || (iVar3 != 0))
               && (iVar3 = FUN_45426781(this,(undefined1 *)param_1), -1 < iVar3)))))) break;
        }
        else {
          iVar3 = Open(&local_112c,local_1120,(LPCSTR)param_1,0x2001f);
          if (((iVar3 != 0) &&
              (iVar3 = Open(&local_112c,pHVar1,(LPCSTR)param_1,0x20019), iVar3 != 0)) &&
             (uVar6 = Create(&local_112c,pHVar1,param_1,(LPWSTR)0x0,0,0x2001f,
                             (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_45427475;
          iVar3 = FUN_45426781(this,(undefined1 *)param_1);
          if (-1 < iVar3) {
            if ((char)*param_1 == '=') {
              iVar3 = FUN_454243a1(this,(CRegKey *)&local_112c,(char *)0x0,(undefined1 *)param_1);
              goto LAB_45427189;
            }
            goto LAB_4542755f;
          }
        }
      }
      goto LAB_454275b8;
    }
    iVar3 = FUN_45426781(this,local_1118);
    if (((iVar3 < 0) || (iVar3 = FUN_45426781(this,(undefined1 *)param_1), iVar3 < 0)) ||
       ((char)*param_1 != '=')) goto LAB_454275b8;
    if (param_3 != 0) {
      local_1150 = 0;
      local_114c = 0;
      local_8 = 1;
      local_1154 = local_1120;
      iVar3 = FUN_454243a1(this,(CRegKey *)&local_1154,local_1118,(undefined1 *)param_1);
      this_00 = (CRegKey *)&local_1154;
      local_1154 = (HKEY)0x0;
      local_1150 = 0;
      local_114c = 0;
      if (-1 < iVar3) {
        local_8 = 0;
        goto LAB_4542755a;
      }
      goto LAB_454275f2;
    }
    if ((param_4 == 0) && (local_113c != 0)) {
      local_1160 = (HKEY)0x0;
      local_115c = 0;
      local_1158 = 0;
      uVar6 = Open(&local_1160,local_1120,(LPCSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueA(local_1160,local_1118), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_45424c03(uVar6);
        this_00 = (CRegKey *)&local_1160;
LAB_454275f2:
        ATL::CRegKey::Close(this_00);
        goto LAB_454275b8;
      }
      ATL::CRegKey::Close((CRegKey *)&local_1160);
    }
    iVar3 = FUN_45427b90(this,(char *)param_1);
  } while( true );
  if (local_111c != 2) {
    if (local_111c == 0) {
      if ((param_4 != 0) && (bVar2 = FUN_4542625f(local_112c), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_45425642((LPCSTR)local_118);
        if ((iVar3 != 0) && (local_113c != 0)) {
          ATL::CRegKey::RecurseDeleteKey((CRegKey *)&local_112c,(char *)local_118);
        }
        goto LAB_45427096;
      }
      bVar2 = FUN_4542625f(local_112c);
      local_111c = CONCAT31(extraout_var_00,bVar2);
      uVar6 = ATL::CRegKey::Close((CRegKey *)&local_112c);
      if (uVar6 == 0) {
        if ((local_113c != 0) && (local_111c == 0)) {
          local_1144 = 0;
          local_1140 = 0;
          local_1148 = local_1120;
          uVar6 = DeleteSubKey(&local_1148,(LPCSTR)local_118);
          local_1148 = (HKEY)0x0;
          local_1144 = 0;
          local_1140 = 0;
          if (uVar6 != 0) {
            FUN_45424c03(uVar6);
            this_00 = (CRegKey *)&local_1148;
            goto LAB_454275f2;
          }
          this_00 = (CRegKey *)&local_1148;
LAB_4542755a:
          ATL::CRegKey::Close(this_00);
LAB_4542755f:
          if (((param_3 != 0) && ((char)*param_1 == '{')) &&
             (sVar7 = _strlen((char *)param_1), sVar7 == 1)) {
            iVar3 = FUN_45427024(this,param_1,local_112c,param_3,0);
            if (-1 < iVar3) goto LAB_45427084;
            goto LAB_454275b8;
          }
        }
        goto LAB_45427096;
      }
    }
    else {
      uVar6 = local_111c;
      if (param_4 != 0) goto LAB_45427096;
    }
LAB_45427475:
    FUN_45424c03(uVar6);
    goto LAB_454275b8;
  }
  goto LAB_45427096;
}


