// Source: CLCiffConversion_Layout.dll @ 4541f002; FUN_4541f002

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_4541f002(void *this,LONG param_1)

{
  wchar_t *pwVar1;
  bool bVar2;
  UINT UVar3;
  int *piVar4;
  size_t sVar5;
  byte *pbVar6;
  wchar_t *_Str;
  char local_6c [16];
  BSTR local_5c;
  wchar_t *local_58;
  BSTR local_54;
  LOGFONTA local_50;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x4541f00e;
  pbVar6 = (byte *)0x0;
  FUN_45429f70((uint *)&local_50,0,0x3c);
  _Str = (wchar_t *)0x0;
  local_58 = (wchar_t *)0x0;
  local_8 = 0;
  bVar2 = FUN_4541c6c2(this);
  if (bVar2) {
    FUN_4541dad8(this,&local_54);
    local_8 = CONCAT31(local_8._1_3_,1);
    bVar2 = FUN_4541c6e1(this);
    if ((bVar2) && (UVar3 = SysStringLen(local_54), UVar3 != 0)) {
      FUN_45404d15(&local_58,(int *)&local_54);
      _Str = local_58;
    }
    else {
      local_50.lfWeight = 900;
    }
    local_8 = local_8 & 0xffffff00;
    SysFreeString(local_54);
  }
  else {
    piVar4 = FUN_4541db3e(this,&local_54);
    FUN_454066f3(&local_58,piVar4);
    SysFreeString(local_54);
    local_50.lfWeight = 0;
    _Str = local_58;
  }
  FUN_4541cd68(this,&local_5c);
  UVar3 = SysStringLen(local_5c);
  if (UVar3 == 0) {
    if (_Str == (wchar_t *)0x0) goto LAB_4541f10e;
    sVar5 = _wcslen(_Str);
    pwVar1 = _Str;
  }
  else {
    local_54 = local_5c;
    if (local_5c == (wchar_t *)0x0) goto LAB_4541f10e;
    sVar5 = _wcslen(local_5c);
    pwVar1 = local_54;
  }
  if ((int)(sVar5 + 1) < 0x40000000) {
    pbVar6 = (byte *)AtlW2AHelper(local_6c,pwVar1,(sVar5 + 1) * 2,3);
  }
LAB_4541f10e:
  FUN_4542a6d4((byte *)local_50.lfFaceName,0x20,pbVar6,0x1f);
  local_50.lfHeight = param_1;
  local_50.lfCharSet = '\x01';
  CreateFontIndirectA(&local_50);
  SysFreeString(local_5c);
  SysFreeString(_Str);
  FUN_4542a957();
  return;
}


