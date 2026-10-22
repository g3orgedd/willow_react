// Source: CLCiffConversion_Data.dll @ 45014c23; FUN_45014c23

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_45014c23(void *this,wchar_t *param_1,wchar_t *param_2)

{
  uint uVar1;
  size_t sVar2;
  void *_Memory;
  void *_Memory_00;
  int iVar3;
  void *local_1c;
  void *local_18;
  uint local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x45014c2f;
  sVar2 = _wcslen(param_1);
  local_14 = sVar2 * 2 + 2;
  _Memory = (void *)FUN_45025afe(-(uint)((int)((ulonglong)local_14 * 2 >> 0x20) != 0) |
                                 (uint)((ulonglong)local_14 * 2));
  local_8 = 0;
  local_1c = _Memory;
  sVar2 = _wcslen(param_2);
  uVar1 = sVar2 * 2 + 2;
  _Memory_00 = (void *)FUN_45025afe(-(uint)((int)((ulonglong)uVar1 * 2 >> 0x20) != 0) |
                                    (uint)((ulonglong)uVar1 * 2));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_18 = _Memory_00;
  FUN_45004ebd(_Memory,local_14,param_1,local_14);
  FUN_45004ebd(_Memory_00,uVar1,param_2,uVar1);
  iVar3 = FUN_45014bce(this,&local_1c,&local_18);
  if (iVar3 == 0) {
    iVar3 = -0x7ff8fff2;
  }
  else {
    iVar3 = 0;
    _Memory = (void *)0x0;
    _Memory_00 = (void *)0x0;
  }
  FID_conflict__free(_Memory_00);
  FID_conflict__free(_Memory);
  return -1 < iVar3;
}


