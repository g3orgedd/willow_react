// Source: CLCiffConversion_Layout.dll @ 45411100; FUN_45411100

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __fastcall FUN_45411100(int *param_1)

{
  int *piVar1;
  wchar_t *pwVar2;
  byte bVar3;
  LPCSTR pCVar4;
  uint uVar5;
  long lVar6;
  size_t sVar7;
  wchar_t *pwVar8;
  wchar_t *pwVar9;
  char *pcVar10;
  int *piVar11;
  LPCSTR ***ppppCVar12;
  int iVar13;
  OLECHAR *pOVar14;
  wchar_t local_1c0 [8];
  wchar_t *local_1b0;
  char *local_1ac;
  int *local_1a8;
  char *local_1a4;
  int *local_1a0;
  LPCSTR local_19c;
  wchar_t *local_198;
  wchar_t *local_194;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_190 [24];
  LPCSTR **local_178 [5];
  uint local_164;
  LPCSTR **local_160 [5];
  uint local_14c;
  CHAR local_148 [100];
  CHAR local_e4 [100];
  CHAR local_80 [100];
  wchar_t *local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1a0;
  local_8 = 0x4541110f;
  local_1a0 = param_1;
  if ((param_1[1] - *param_1 & 0xfffffff8U) != 0) {
    FUN_4540f8f2(*param_1,param_1[1]);
    param_1[1] = *param_1;
  }
  pCVar4 = FUN_4540856d();
  GetPrivateProfileStringA("shiftcodes","activeshifts"," ",local_e4,100,pCVar4);
  pCVar4 = (LPCSTR)_atol(local_e4);
  local_1a4 = pCVar4;
  FUN_45411fae(param_1,(uint)pCVar4);
  local_19c = (LPCSTR)0x0;
  if (0 < (int)pCVar4) {
    do {
      local_1a8 = (int *)(local_19c + 1);
      _sprintf_s((char *)local_1c,6,"%02d",local_1a8);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_178,
                 "start");
      local_8 = 0;
      if ((char)local_1c[0] == '\0') {
        uVar5 = 0;
      }
      else {
        uVar5 = _strlen((char *)local_1c);
      }
      FUN_45404764(local_178,(char *)local_1c,uVar5);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_160,"code"
                );
      local_8._0_1_ = 1;
      if ((char)local_1c[0] == '\0') {
        uVar5 = 0;
      }
      else {
        uVar5 = _strlen((char *)local_1c);
      }
      FUN_45404764(local_160,(char *)local_1c,uVar5);
      ppppCVar12 = local_178;
      if (0xf < local_164) {
        ppppCVar12 = (LPCSTR ***)local_178[0];
      }
      pCVar4 = FUN_4540856d();
      GetPrivateProfileStringA("shiftcodes",(LPCSTR)ppppCVar12," ",local_e4,100,pCVar4);
      lVar6 = _atol(local_e4);
      ppppCVar12 = local_160;
      if (0xf < local_14c) {
        ppppCVar12 = (LPCSTR ***)local_160[0];
      }
      pCVar4 = FUN_4540856d();
      GetPrivateProfileStringA("shiftcodes",(LPCSTR)ppppCVar12," ",local_e4,100,pCVar4);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_190,local_e4);
      local_8 = CONCAT31(local_8._1_3_,2);
      *(long *)(*param_1 + (int)local_19c * 8) = lVar6;
      FUN_45402c99((void *)((int)local_19c * 8 + 4 + *param_1),local_e4);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_190,true,0);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_160,true,0
                );
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_178,true,0
                );
      local_19c = (LPCSTR)local_1a8;
    } while ((int)local_1a8 < (int)local_1a4);
  }
  local_19c = (LPCSTR)0x0;
  do {
    local_198 = (wchar_t *)0x0;
    local_194 = (wchar_t *)0x0;
    local_8 = 4;
    switch(local_19c) {
    case (LPCSTR)0x0:
      FUN_45401cab(&local_198,L"Jan");
      pOVar14 = L"JA";
      break;
    case (LPCSTR)0x1:
      FUN_45401cab(&local_198,L"Feb");
      pOVar14 = L"FE";
      break;
    case (LPCSTR)0x2:
      FUN_45401cab(&local_198,L"Mar");
      pOVar14 = L"MR";
      break;
    case (LPCSTR)0x3:
      FUN_45401cab(&local_198,L"Apr");
      pOVar14 = L"AL";
      break;
    case (LPCSTR)0x4:
      FUN_45401cab(&local_198,L"May");
      pOVar14 = L"MA";
      break;
    case (LPCSTR)0x5:
      FUN_45401cab(&local_198,L"Jun");
      pOVar14 = L"JN";
      break;
    case (LPCSTR)0x6:
      FUN_45401cab(&local_198,L"Jul");
      pOVar14 = L"JL";
      break;
    case (LPCSTR)0x7:
      FUN_45401cab(&local_198,L"Aug");
      pOVar14 = L"AU";
      break;
    case (LPCSTR)0x8:
      FUN_45401cab(&local_198,L"Sep");
      pOVar14 = L"SE";
      break;
    case (LPCSTR)0x9:
      FUN_45401cab(&local_198,L"Oct");
      pOVar14 = L"OC";
      break;
    case (LPCSTR)0xa:
      FUN_45401cab(&local_198,L"Nov");
      pOVar14 = L"NO";
      break;
    default:
      FUN_45401cab(&local_198,L"Dec");
      pOVar14 = L"DE";
    }
    FUN_45401cab(&local_194,pOVar14);
    pwVar9 = local_194;
    if (local_194 == (wchar_t *)0x0) {
LAB_4541147d:
      local_1ac = (char *)0x0;
    }
    else {
      sVar7 = _wcslen(local_194);
      if (0x3fffffff < (int)(sVar7 + 1)) goto LAB_4541147d;
      local_1ac = AtlW2AHelper((char *)local_1c0,pwVar9,(sVar7 + 1) * 2,3);
    }
    pwVar2 = local_198;
    if (local_198 == (wchar_t *)0x0) {
LAB_454114bb:
      local_1a4 = (char *)0x0;
    }
    else {
      sVar7 = _wcslen(local_198);
      if (0x3fffffff < (int)(sVar7 + 1)) goto LAB_454114bb;
      local_1a4 = AtlW2AHelper((char *)local_1c0,pwVar2,(sVar7 + 1) * 2,3);
    }
    sVar7 = _wcslen(L"monthcodes");
    if ((int)(sVar7 + 1) < 0x40000000) {
      pcVar10 = AtlW2AHelper((char *)local_1c0,L"monthcodes",(sVar7 + 1) * 2,3);
    }
    else {
      pcVar10 = (LPCSTR)0x0;
    }
    pCVar4 = FUN_4540856d();
    GetPrivateProfileStringA(pcVar10,local_1a4,local_1ac,local_80,100,pCVar4);
    sVar7 = _strlen(local_80);
    if ((int)(sVar7 + 1) < 0x40000000) {
      pwVar8 = AtlA2WHelper(local_1c0,local_80,sVar7 + 1,3);
    }
    else {
      pwVar8 = (wchar_t *)0x0;
    }
    piVar11 = local_1a0;
    FID_conflict_assign(local_1a0 + (int)local_19c * 6 + 0x57,pwVar8);
    SysFreeString(pwVar9);
    local_8 = 0xffffffff;
    SysFreeString(pwVar2);
    local_19c = local_19c + 1;
  } while ((int)local_19c < 0xc);
  local_1a8 = piVar11 + 0x9f;
  local_194 = (wchar_t *)0x0;
  do {
    _sprintf_s((char *)&local_198,3,"%02d",local_194);
    FUN_454028b9(local_1c,(char *)&local_198);
    bVar3 = (char)local_194 + 0x41;
    local_8 = 5;
    local_1ac._0_2_ = (ushort)bVar3;
    if ('H' < (char)bVar3) {
      bVar3 = (char)local_194 + 0x42;
      local_1ac = (char *)CONCAT31(local_1ac._1_3_,bVar3);
    }
    if ('N' < (char)bVar3) {
      local_1ac = (char *)CONCAT31(local_1ac._1_3_,bVar3 + 1);
    }
    FUN_454028b9(&local_1b0,(char *)&local_1ac);
    pwVar9 = local_1b0;
    local_8 = CONCAT31(local_8._1_3_,6);
    if (local_1b0 == (wchar_t *)0x0) {
LAB_45411641:
      local_19c = (char *)0x0;
    }
    else {
      sVar7 = _wcslen(local_1b0);
      if (0x3fffffff < (int)(sVar7 + 1)) goto LAB_45411641;
      local_19c = AtlW2AHelper((char *)local_1c0,pwVar9,(sVar7 + 1) * 2,3);
    }
    pwVar2 = local_1c[0];
    if (local_1c[0] == (wchar_t *)0x0) {
LAB_4541167b:
      local_1a4 = (char *)0x0;
    }
    else {
      sVar7 = _wcslen(local_1c[0]);
      if (0x3fffffff < (int)(sVar7 + 1)) goto LAB_4541167b;
      local_1a4 = AtlW2AHelper((char *)local_1c0,pwVar2,(sVar7 + 1) * 2,3);
    }
    pcVar10 = (LPCSTR)0x0;
    sVar7 = _wcslen(L"hourcodes");
    if ((int)(sVar7 + 1) < 0x40000000) {
      pcVar10 = AtlW2AHelper((char *)local_1c0,L"hourcodes",(sVar7 + 1) * 2,3);
    }
    pCVar4 = FUN_4540856d();
    GetPrivateProfileStringA(pcVar10,local_1a4,local_19c,local_80,100,pCVar4);
    sVar7 = _strlen(local_80);
    if ((int)(sVar7 + 1) < 0x40000000) {
      pwVar8 = AtlA2WHelper(local_1c0,local_80,sVar7 + 1,3);
    }
    else {
      pwVar8 = (wchar_t *)0x0;
    }
    piVar11 = local_1a8;
    FID_conflict_assign(local_1a8,pwVar8);
    SysFreeString(pwVar9);
    local_8 = 0xffffffff;
    SysFreeString(pwVar2);
    local_1a8 = piVar11 + 6;
    local_194 = (wchar_t *)((int)local_194 + 1);
  } while ((int)local_194 < 0x18);
  local_1ac = (char *)0x0;
  do {
    local_194 = (wchar_t *)0x0;
    local_198 = (BSTR)0x0;
    local_8 = 8;
    if (local_1ac == (char *)0x0) {
      FUN_45401cab(&local_194,L"Mon");
      pOVar14 = L"MO";
LAB_45411843:
      FUN_45401cab(&local_198,pOVar14);
      pwVar9 = local_198;
      if (local_198 == (wchar_t *)0x0) goto LAB_4541185e;
      sVar7 = _wcslen(local_198);
      if ((int)(sVar7 + 1) < 0x40000000) {
        local_19c = AtlW2AHelper((char *)local_1c0,pwVar9,(sVar7 + 1) * 2,3);
      }
      else {
        local_19c = (char *)0x0;
      }
    }
    else {
      if (local_1ac == (char *)0x1) {
        FUN_45401cab(&local_194,L"Tue");
        pOVar14 = L"TU";
        goto LAB_45411843;
      }
      if (local_1ac == (char *)0x2) {
        FUN_45401cab(&local_194,L"Wed");
        pOVar14 = L"WE";
        goto LAB_45411843;
      }
      if (local_1ac == (char *)0x3) {
        FUN_45401cab(&local_194,L"Thu");
        pOVar14 = L"TH";
        goto LAB_45411843;
      }
      if (local_1ac == (char *)0x4) {
        FUN_45401cab(&local_194,L"Fri");
        pOVar14 = L"FR";
        goto LAB_45411843;
      }
      if (local_1ac == (char *)0x5) {
        FUN_45401cab(&local_194,L"Sat");
        pOVar14 = L"SA";
        goto LAB_45411843;
      }
      if (local_1ac == (char *)0x6) {
        FUN_45401cab(&local_194,L"Sun");
        pOVar14 = L"SU";
        goto LAB_45411843;
      }
LAB_4541185e:
      local_19c = (char *)0x0;
      pwVar9 = local_198;
    }
    pwVar2 = local_194;
    if (local_194 == (wchar_t *)0x0) {
LAB_454118b4:
      local_1a4 = (char *)0x0;
    }
    else {
      sVar7 = _wcslen(local_194);
      if (0x3fffffff < (int)(sVar7 + 1)) goto LAB_454118b4;
      local_1a4 = AtlW2AHelper((char *)local_1c0,pwVar2,(sVar7 + 1) * 2,3);
    }
    sVar7 = _wcslen(L"dayofweekcodes");
    if ((int)(sVar7 + 1) < 0x40000000) {
      pcVar10 = AtlW2AHelper((char *)local_1c0,L"dayofweekcodes",(sVar7 + 1) * 2,3);
    }
    else {
      pcVar10 = (LPCSTR)0x0;
    }
    pCVar4 = FUN_4540856d();
    GetPrivateProfileStringA(pcVar10,local_1a4,local_19c,local_80,100,pCVar4);
    sVar7 = _strlen(local_80);
    if ((int)(sVar7 + 1) < 0x40000000) {
      pwVar8 = AtlA2WHelper(local_1c0,local_80,sVar7 + 1,3);
    }
    else {
      pwVar8 = (wchar_t *)0x0;
    }
    piVar11 = local_1a0;
    FID_conflict_assign(local_1a0 + (int)local_1ac * 6 + 0x12f,pwVar8);
    SysFreeString(pwVar9);
    SysFreeString(pwVar2);
    local_1ac = local_1ac + 1;
    if (6 < (int)local_1ac) {
      local_1a8 = piVar11 + 0x38d;
      iVar13 = 0;
      do {
        local_19c = PTR_DAT_4545d110;
        local_8 = 9;
        FUN_45405c46(&local_19c,"%02d");
        sVar7 = _wcslen(L"  ");
        if ((int)(sVar7 + 1) < 0x40000000) {
          local_1a0 = (int *)AtlW2AHelper((char *)local_1c0,L"  ",(sVar7 + 1) * 2,3);
        }
        else {
          local_1a0 = (int *)0x0;
        }
        sVar7 = _wcslen(L"minutecodes");
        if ((int)(sVar7 + 1) < 0x40000000) {
          pcVar10 = AtlW2AHelper((char *)local_1c0,L"minutecodes",(sVar7 + 1) * 2,3);
        }
        else {
          pcVar10 = (LPCSTR)0x0;
        }
        pCVar4 = FUN_4540856d();
        GetPrivateProfileStringA(pcVar10,local_19c,(LPCSTR)local_1a0,local_80,100,pCVar4);
        sVar7 = _strlen(local_80);
        if ((int)(sVar7 + 1) < 0x40000000) {
          pwVar9 = AtlA2WHelper(local_1c0,local_80,sVar7 + 1,3);
        }
        else {
          pwVar9 = (wchar_t *)0x0;
        }
        piVar1 = local_1a8;
        FID_conflict_assign(local_1a8,pwVar9);
        local_8 = 0xffffffff;
        FUN_45402c5d((int *)&local_19c);
        iVar13 = iVar13 + 1;
        local_1a8 = piVar1 + 6;
      } while (iVar13 < 0x3c);
      local_1a8 = piVar11 + 0x213;
      iVar13 = 0;
      do {
        iVar13 = iVar13 + 1;
        _sprintf_s((char *)&local_198,3,"%02d",iVar13);
        sVar7 = _wcslen(L"  ");
        if ((int)(sVar7 + 1) < 0x40000000) {
          local_1a0 = (int *)AtlW2AHelper((char *)local_1c0,L"  ",(sVar7 + 1) * 2,3);
        }
        else {
          local_1a0 = (int *)0x0;
        }
        sVar7 = _wcslen(L"weekofyearcodes");
        if ((int)(sVar7 + 1) < 0x40000000) {
          pcVar10 = AtlW2AHelper((char *)local_1c0,L"weekofyearcodes",(sVar7 + 1) * 2,3);
        }
        else {
          pcVar10 = (LPCSTR)0x0;
        }
        pCVar4 = FUN_4540856d();
        GetPrivateProfileStringA(pcVar10,(LPCSTR)&local_198,(LPCSTR)local_1a0,local_80,100,pCVar4);
        sVar7 = _strlen(local_80);
        if ((int)(sVar7 + 1) < 0x40000000) {
          pwVar9 = AtlA2WHelper(local_1c0,local_80,sVar7 + 1,3);
        }
        else {
          pwVar9 = (wchar_t *)0x0;
        }
        piVar1 = local_1a8;
        FID_conflict_assign(local_1a8,pwVar9);
        local_1a8 = piVar1 + 6;
      } while (iVar13 < 0x35);
      local_1a8 = piVar11 + 0x351;
      iVar13 = 0;
      do {
        _sprintf_s((char *)&local_198,3,"%02d",iVar13);
        sVar7 = _wcslen(L"  ");
        if ((int)(sVar7 + 1) < 0x40000000) {
          local_1a0 = (int *)AtlW2AHelper((char *)local_1c0,L"  ",(sVar7 + 1) * 2,3);
        }
        else {
          local_1a0 = (int *)0x0;
        }
        sVar7 = _wcslen(L"yearofdecadecodes");
        if ((int)(sVar7 + 1) < 0x40000000) {
          pcVar10 = AtlW2AHelper((char *)local_1c0,L"yearofdecadecodes",(sVar7 + 1) * 2,3);
        }
        else {
          pcVar10 = (LPCSTR)0x0;
        }
        pCVar4 = FUN_4540856d();
        GetPrivateProfileStringA(pcVar10,(LPCSTR)&local_198,(LPCSTR)local_1a0,local_80,100,pCVar4);
        sVar7 = _strlen(local_80);
        if ((int)(sVar7 + 1) < 0x40000000) {
          pwVar9 = AtlA2WHelper(local_1c0,local_80,sVar7 + 1,3);
        }
        else {
          pwVar9 = (wchar_t *)0x0;
        }
        piVar1 = local_1a8;
        FID_conflict_assign(local_1a8,pwVar9);
        iVar13 = iVar13 + 1;
        local_1a8 = piVar1 + 6;
      } while (iVar13 < 10);
      iVar13 = 0;
      piVar11 = piVar11 + 0x159;
      do {
        iVar13 = iVar13 + 1;
        _sprintf_s((char *)&local_194,3,"%02d",iVar13);
        sVar7 = _wcslen(L"  ");
        if ((int)(sVar7 + 1) < 0x40000000) {
          local_1a0 = (int *)AtlW2AHelper((char *)local_1c0,L"  ",(sVar7 + 1) * 2,3);
        }
        else {
          local_1a0 = (int *)0x0;
        }
        sVar7 = _wcslen(L"dayofmonthcodes");
        if ((int)(sVar7 + 1) < 0x40000000) {
          pcVar10 = AtlW2AHelper((char *)local_1c0,L"dayofmonthcodes",(sVar7 + 1) * 2,3);
        }
        else {
          pcVar10 = (LPCSTR)0x0;
        }
        pCVar4 = FUN_4540856d();
        GetPrivateProfileStringA(pcVar10,(LPCSTR)&local_194,(LPCSTR)local_1a0,local_148,100,pCVar4);
        sVar7 = _strlen(local_148);
        if ((int)(sVar7 + 1) < 0x40000000) {
          pwVar9 = AtlA2WHelper(local_1c0,local_148,sVar7 + 1,3);
        }
        else {
          pwVar9 = (wchar_t *)0x0;
        }
        FID_conflict_assign(piVar11,pwVar9);
        piVar11 = piVar11 + 6;
      } while (iVar13 < 0x1f);
      FUN_4542a957();
      return;
    }
  } while( true );
}


