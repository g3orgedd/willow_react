// Source: CiffMgr.dll @ 68111edf; FUN_68111edf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_68111edf(void *this,int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  uVar4 = 0;
  local_14[0] = 0;
  local_8 = 0;
  if (param_1 != 0) {
    SysFreeString((BSTR)0x0);
    local_14[0] = param_1;
  }
  uVar2 = FUN_68112452((void *)((int)this + 0x98),local_14[0]);
  if (uVar2 == 0xffffffff) {
    uVar4 = 0x80070057;
  }
  else {
    uVar1 = *(uint *)(*(int *)((int)this + 0x9c) + 4 + uVar2 * 8);
    FUN_681123fe((void *)((int)this + 0x98),uVar2);
    FUN_68104800((int *)((int)this + 4),&local_18,
                 (VARIANTARG *)(uVar1 * 0x10 + *(int *)((int)this + 4)));
    uVar2 = (*(int *)((int)this + 0xa4) != 0) - 1;
    if (uVar2 != 0xffffffff) {
      while( true ) {
        if (*(int *)((int)this + 0xa4) == 0) {
          uVar3 = 0xffffffff;
        }
        else {
          uVar3 = *(int *)((int)this + 0xa4) - 1;
        }
        if (uVar3 < uVar2) break;
        uVar3 = *(uint *)(*(int *)((int)this + 0x9c) + 4 + uVar2 * 8);
        if (uVar1 <= uVar3) {
          *(uint *)(*(int *)((int)this + 0x9c) + 4 + uVar2 * 8) = uVar3 - 1;
        }
        uVar2 = uVar2 + 1;
      }
    }
  }
  local_14[0] = 0;
  FUN_6811115c(local_14);
  return uVar4;
}


