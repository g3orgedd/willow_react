// Source: CLCSTextBasedField.dll @ 424679df; FUN_424679df

void __thiscall FUN_424679df(void *this,wchar_t *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_58 [12];
  wchar_t *local_4c;
  wchar_t local_48 [32];
  uint local_8;
  
  local_8 = DAT_424ba210 ^ (uint)&stack0xfffffffc;
  local_4c = param_1;
  if (param_1 != (wchar_t *)0x0) {
    *param_2 = 0xffffffff;
    uVar2 = FUN_424675bc(param_1,(uint *)local_48,(int)local_58);
    if ((((char)uVar2 != '\0') && (iVar3 = FUN_42467666(this,local_48), iVar3 == -1)) &&
       (piVar4 = FUN_4246741a(this,param_2), piVar4 != (int *)0x0)) {
      cVar1 = FUN_4246780c(this,piVar4,local_4c);
      if (cVar1 == '\0') {
        FUN_4246753e(this,(int)piVar4);
      }
      else {
        FUN_4246775e((int)piVar4);
      }
    }
  }
  FUN_4246ec70(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


