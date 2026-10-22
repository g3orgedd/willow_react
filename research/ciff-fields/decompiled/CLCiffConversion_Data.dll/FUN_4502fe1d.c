// Source: CLCiffConversion_Data.dll @ 4502fe1d; FUN_4502fe1d

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4502fe1d(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  undefined **ppuVar4;
  int iVar5;
  uint CodePage;
  char *_Str1;
  size_t sVar6;
  errno_t eVar7;
  DWORD DVar8;
  int *piVar9;
  undefined4 *puVar10;
  long lVar11;
  char *pcVar12;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined **local_24;
  int local_20 [5];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_4504fd98;
  uStack_c = 0x4502fe29;
  local_20[0] = 0;
  local_28 = 0;
  local_2c = 0;
  local_24 = (undefined **)0x0;
  local_30 = 0;
  __lock(7);
  local_8 = (undefined *)0x0;
  local_24 = FUN_4502fd49();
  iVar5 = FUN_4502fda3(local_20);
  if (((iVar5 != 0) || (iVar5 = FUN_4502fd4f(&local_28), iVar5 != 0)) ||
     (iVar5 = FUN_4502fd79(&local_2c), iVar5 != 0)) goto LAB_4502ff27;
  CodePage = FUN_450326ef();
  _DAT_45055a28 = 0;
  _DAT_4505240c = 0xffffffff;
  _DAT_45052400 = 0xffffffff;
  _Str1 = __getenv_helper_nolock("TZ");
  if ((_Str1 == (char *)0x0) || (*_Str1 == '\0')) {
    if (DAT_45055a20 != (char *)0x0) {
      FID_conflict__free(DAT_45055a20);
      DAT_45055a20 = (char *)0x0;
    }
    DVar8 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_45055a30);
    if (DVar8 != 0xffffffff) {
      _DAT_45055a28 = 1;
      local_20[0] = DAT_45055a30 * 0x3c;
      if (DAT_45055a76 != 0) {
        local_20[0] = local_20[0] + DAT_45055a84 * 0x3c;
      }
      if ((DAT_45055aca == 0) || (DAT_45055ad8 == 0)) {
        local_28 = 0;
        local_2c = 0;
      }
      else {
        local_28 = 1;
        local_2c = (DAT_45055ad8 - DAT_45055a84) * 0x3c;
      }
      iVar5 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_45055a34,-1,*local_24,0x3f,(LPCSTR)0x0,
                                  &local_34);
      if ((iVar5 == 0) || (local_34 != 0)) {
        **local_24 = 0;
      }
      else {
        (*local_24)[0x3f] = 0;
      }
      iVar5 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_45055a88,-1,local_24[1],0x3f,(LPCSTR)0x0,
                                  &local_34);
      if ((iVar5 == 0) || (local_34 != 0)) {
        *local_24[1] = 0;
      }
      else {
        local_24[1][0x3f] = 0;
      }
    }
    local_30 = 1;
  }
  else {
    if (DAT_45055a20 == (char *)0x0) {
LAB_4502fee3:
      sVar6 = _strlen(_Str1);
      DAT_45055a20 = FUN_4502df29(sVar6 + 1);
      if (DAT_45055a20 != (char *)0x0) {
        pcVar12 = _Str1;
        sVar6 = _strlen(_Str1);
        eVar7 = _strcpy_s(DAT_45055a20,sVar6 + 1,pcVar12);
        if (eVar7 != 0) goto LAB_4502ff27;
        goto LAB_45030024;
      }
    }
    else {
      iVar5 = _strcmp(_Str1,DAT_45055a20);
      if (iVar5 != 0) {
        if (DAT_45055a20 != (char *)0x0) {
          FID_conflict__free(DAT_45055a20);
        }
        goto LAB_4502fee3;
      }
    }
    local_30 = 1;
  }
LAB_45030024:
  iVar5 = local_20[0];
  piVar9 = FUN_4502fd43();
  uVar3 = local_28;
  *piVar9 = iVar5;
  puVar10 = FUN_4502fd37();
  iVar5 = local_2c;
  *puVar10 = uVar3;
  piVar9 = FUN_4502fd3d();
  *piVar9 = iVar5;
  local_8 = (undefined *)0xfffffffe;
  FUN_450300ad();
  ppuVar4 = local_24;
  if (local_30 == 0) {
    iVar5 = FUN_45034950(*local_24,0x40,_Str1,3);
    if (iVar5 != 0) {
LAB_4502ff27:
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    pcVar12 = _Str1 + 3;
    cVar1 = *pcVar12;
    if (cVar1 == '-') {
      pcVar12 = _Str1 + 4;
    }
    lVar11 = _atol(pcVar12);
    local_20[0] = lVar11 * 0xe10;
    for (; (cVar2 = *pcVar12, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
        pcVar12 = pcVar12 + 1) {
    }
    if (*pcVar12 == ':') {
      pcVar12 = pcVar12 + 1;
      lVar11 = _atol(pcVar12);
      local_20[0] = local_20[0] + lVar11 * 0x3c;
      for (; ('/' < *pcVar12 && (*pcVar12 < ':')); pcVar12 = pcVar12 + 1) {
      }
      if (*pcVar12 == ':') {
        pcVar12 = pcVar12 + 1;
        lVar11 = _atol(pcVar12);
        local_20[0] = local_20[0] + lVar11;
        for (; ('/' < *pcVar12 && (*pcVar12 < ':')); pcVar12 = pcVar12 + 1) {
        }
      }
    }
    if (cVar1 == '-') {
      local_20[0] = -local_20[0];
    }
    if (*pcVar12 == '\0') {
      local_28 = 0;
      *ppuVar4[1] = 0;
    }
    else {
      local_28 = 1;
      iVar5 = FUN_45034950(ppuVar4[1],0x40,pcVar12,3);
      if (iVar5 != 0) goto LAB_4502ff27;
    }
    iVar5 = local_20[0];
    piVar9 = FUN_4502fd43();
    uVar3 = local_28;
    *piVar9 = iVar5;
    puVar10 = FUN_4502fd37();
    *puVar10 = uVar3;
  }
  return;
}


