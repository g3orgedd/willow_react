// Source: CLCiffConversion_Layout.dll @ 4542d431; FUN_4542d431

undefined4 __cdecl
FUN_4542d431(undefined *param_1,wchar_t *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  undefined4 uVar2;
  size_t sVar3;
  int iVar4;
  wchar_t *local_24;
  int local_20;
  wchar_t *local_1c;
  undefined4 local_18;
  
  local_24 = (wchar_t *)0x0;
  piVar1 = &local_20;
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
  }
  if ((param_2 == (wchar_t *)0x0) || (param_3 == 0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45432798();
    uVar2 = 0xffffffff;
  }
  else {
    sVar3 = _wcslen(param_2);
    local_18 = 0x49;
    local_1c = param_2;
    local_24 = param_2;
    if (sVar3 < 0x40000000) {
      local_20 = sVar3 * 2;
    }
    else {
      local_20 = 0x7fffffff;
    }
    uVar2 = (*(code *)param_1)(&local_24,param_3,param_4,param_5);
  }
  return uVar2;
}


