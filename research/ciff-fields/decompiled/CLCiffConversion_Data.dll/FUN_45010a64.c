// Source: CLCiffConversion_Data.dll @ 45010a64; FUN_45010a64

void FUN_45010a64(BSTR param_1,int param_2)

{
  wchar_t wVar1;
  UINT UVar2;
  int iVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  uint uVar6;
  int iVar7;
  wchar_t *local_18;
  int local_14;
  ushort local_10 [4];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_14 = param_2;
  if ((param_1 != (BSTR)0x0) && (UVar2 = SysStringLen(param_1), UVar2 != 0)) {
    local_10[0] = 0x2e;
    local_10[1] = 0x2c;
    local_10[2] = 0xb7;
    pwVar4 = (wchar_t *)0x0;
    uVar6 = 0;
    do {
      if (pwVar4 != (wchar_t *)0x0) break;
      pwVar4 = (wchar_t *)FUN_45023be5((ushort *)param_1,local_10[uVar6]);
      uVar6 = uVar6 + 1;
    } while (uVar6 < 3);
    iVar3 = FUN_4502152b(*param_1);
    pwVar5 = param_1;
    iVar7 = local_14;
    while ((local_14 = iVar7, iVar3 == 0 &&
           (((pwVar4 != (wchar_t *)0x0 && (pwVar5 < pwVar4)) || (*pwVar5 != L'\0'))))) {
      pwVar5 = pwVar5 + 1;
      iVar3 = FUN_4502152b(*pwVar5);
      iVar7 = local_14;
    }
    if (pwVar4 == (wchar_t *)0x0) {
      _wcstol(pwVar5,&local_18,10);
    }
    else {
      if (pwVar4 == pwVar5) {
        local_14 = 0;
      }
      else {
        local_14 = _wcstol(pwVar5,&local_18,10);
        if (local_18 != pwVar4) goto LAB_45010b81;
      }
      if (0 < iVar7) {
        iVar3 = (UVar2 - ((int)pwVar4 - (int)param_1 >> 1)) + -1;
        if (iVar7 < iVar3) {
          pwVar5 = pwVar4 + iVar7 + 1;
          wVar1 = *pwVar5;
          *pwVar5 = L'\0';
          _wcstol(pwVar4 + 1,&local_18,10);
          *pwVar5 = wVar1;
        }
        else {
          _wcstol(pwVar4 + 1,&local_18,10);
          if ((local_18 == param_1 + UVar2) && (iVar7 = iVar7 - iVar3, 0 < iVar7)) {
            do {
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
        }
      }
    }
  }
LAB_45010b81:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


