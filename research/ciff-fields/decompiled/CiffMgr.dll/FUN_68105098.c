// Source: CiffMgr.dll @ 68105098; FUN_68105098

void FUN_68105098(int param_1,int param_2,wchar_t *param_3)

{
  int *this;
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined8 local_20 [3];
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  iVar3 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  this = (int *)(param_1 + 0x74);
  piVar1 = (int *)*this;
  piVar2 = (int *)*piVar1;
  if (piVar2 != piVar1) {
    do {
      if (iVar3 == param_2 + 1) {
        basic_string<>(local_20,param_3);
        FUN_68104bc6(this,piVar2,local_20);
        FUN_68105b16(local_20,'\x01',0);
        break;
      }
      piVar2 = (int *)*piVar2;
      iVar3 = iVar3 + 1;
    } while (piVar2 != piVar1);
  }
  basic_string<>(local_20,param_3);
  FUN_68104bc6(this,(int *)*this,local_20);
  FUN_68105b16(local_20,'\x01',0);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


