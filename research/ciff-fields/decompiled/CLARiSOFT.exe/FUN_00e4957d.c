// Source: CLARiSOFT.exe @ 00e4957d; FUN_00e4957d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __thiscall FUN_00e4957d(void *this,HANDLE param_1)

{
  void *_Memory;
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  void *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (void *)0x0;
  local_8 = 0;
  cVar1 = FUN_00e49684(local_14,param_1);
  _Memory = local_14[0];
  uVar2 = 0;
  if (cVar1 != '\0') {
    uVar3 = FUN_00e4951c(this,*(void **)((int)local_14[0] + 0x1c));
    uVar2 = (undefined1)uVar3;
  }
  FID_conflict__free(_Memory);
  return uVar2;
}


