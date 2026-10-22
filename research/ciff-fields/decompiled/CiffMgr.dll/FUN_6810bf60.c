// Source: CiffMgr.dll @ 6810bf60; FUN_6810bf60

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_6810bf60(void *this,wchar_t *param_1,wchar_t *param_2)

{
  size_t sVar1;
  void *_Memory;
  void *_Memory_00;
  int iVar2;
  int iVar3;
  void *local_20;
  void *local_1c;
  uint local_18;
  uint local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x6810bf6c;
  if ((param_1 == (wchar_t *)0x0) || (param_2 == (wchar_t *)0x0)) {
    return false;
  }
  iVar3 = 0;
  sVar1 = _wcslen(param_1);
  local_14 = sVar1 * 2 + 2;
  _Memory = (void *)FUN_68132ccc(-(uint)((int)((ulonglong)local_14 * 2 >> 0x20) != 0) |
                                 (uint)((ulonglong)local_14 * 2));
  local_8 = 0;
  local_20 = _Memory;
  sVar1 = _wcslen(param_2);
  local_18 = sVar1 * 2 + 2;
  _Memory_00 = (void *)FUN_68132ccc(-(uint)((int)((ulonglong)local_18 * 2 >> 0x20) != 0) |
                                    (uint)((ulonglong)local_18 * 2));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_1c = _Memory_00;
  if ((_Memory != (void *)0x0) && (_Memory_00 != (void *)0x0)) {
    FUN_68104847(_Memory,local_14,param_1,local_14);
    FUN_68104847(_Memory_00,local_18,param_2,local_18);
    iVar2 = FUN_6810bf0b(this,&local_20,&local_1c);
    if (iVar2 != 0) {
      _Memory = (void *)0x0;
      _Memory_00 = (void *)0x0;
      goto LAB_6810c038;
    }
  }
  iVar3 = -0x7ff8fff2;
LAB_6810c038:
  FID_conflict__free(_Memory_00);
  FID_conflict__free(_Memory);
  return -1 < iVar3;
}


