// Source: CLCiffConversion_Layout.dll @ 4541d731; FUN_4541d731

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_4541d731(undefined4 *param_1,int param_2)

{
  wchar_t *_Str;
  UINT UVar1;
  size_t sVar2;
  char *pcVar3;
  uint uVar4;
  undefined8 *puVar5;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar6;
  char ****ppppcVar7;
  long lVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  char local_94 [16];
  long local_84;
  uint local_80;
  int *local_7c;
  undefined4 local_78;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_74 [24];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_5c [24];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_44 [24];
  char ***local_2c [5];
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x4541d73d;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_44,"CCapabilitiesFont::GetNearestSupportedSize");
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  UVar1 = SysStringLen((BSTR)*param_1);
  if (UVar1 == 0) goto LAB_4541d94d;
  _Str = (wchar_t *)*param_1;
  if (_Str == (wchar_t *)0x0) {
LAB_4541d77a:
    pcVar3 = (char *)0x0;
  }
  else {
    sVar2 = _wcslen(_Str);
    if (0x3fffffff < (int)(sVar2 + 1)) goto LAB_4541d77a;
    pcVar3 = AtlW2AHelper(local_94,_Str,(sVar2 + 1) * 2,3);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_5c,pcVar3);
  local_78 = 0;
  local_8._0_1_ = 1;
  local_7c = (int *)FUN_4540437f((int *)0x0,(int *)0x0);
  local_8._0_1_ = 2;
  uVar10 = 0;
  while( true ) {
    piVar9 = local_7c;
    sVar2 = _strlen(",");
    uVar4 = FUN_45404a6f(local_5c,(uint *)&DAT_454477cc,uVar10,sVar2);
    if (uVar4 == 0xffffffff) break;
    puVar5 = (undefined8 *)FUN_45404b65(local_5c,(undefined1 *)local_2c,uVar10,uVar4 - uVar10);
    local_8._0_1_ = 3;
    FUN_45402609(&local_7c,piVar9,puVar5);
    local_8._0_1_ = 2;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_2c,true,0);
    uVar10 = uVar4 + 1;
  }
  piVar11 = (int *)*piVar9;
  iVar12 = -1;
  if (piVar11 != piVar9) {
    do {
      piVar9 = piVar11 + 2;
      sVar2 = _strlen("-");
      local_80 = FUN_45404a6f(piVar9,(uint *)&DAT_454477d0,0,sVar2);
      if (local_80 == 0xffffffff) {
        if (0xf < (uint)piVar11[7]) {
          piVar9 = (int *)*piVar9;
        }
        lVar8 = _atol((char *)piVar9);
      }
      else {
        FUN_45404b65(piVar9,(undefined1 *)local_2c,0,local_80);
        local_8._0_1_ = 4;
        ppppcVar7 = local_2c;
        if (0xf < local_18) {
          ppppcVar7 = (char ****)local_2c[0];
        }
        local_84 = _atol((char *)ppppcVar7);
        pbVar6 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 FUN_45404b65(piVar9,local_74,local_80 + 1,(local_80 - piVar11[6]) + 1);
        FUN_454131b7(local_2c,pbVar6);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_74,true,0)
        ;
        ppppcVar7 = local_2c;
        if (0xf < local_18) {
          ppppcVar7 = (char ****)local_2c[0];
        }
        lVar8 = _atol((char *)ppppcVar7);
        if ((param_2 <= lVar8) && (lVar8 = local_84, local_84 <= param_2)) {
          local_8._0_1_ = 2;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_2c,
                     true,0);
          break;
        }
        local_8._0_1_ = 2;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_2c,true,
                   0);
      }
      iVar12 = FUN_45416187(iVar12,lVar8,param_2);
      piVar11 = (int *)*piVar11;
    } while (piVar11 != local_7c);
  }
  FUN_4540303d(0x4544962c);
  FUN_45404939((int *)&local_7c);
  FID_conflict__free(local_7c);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_5c,true,0);
LAB_4541d94d:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_44,true,0);
  FUN_4542a957();
  return;
}


