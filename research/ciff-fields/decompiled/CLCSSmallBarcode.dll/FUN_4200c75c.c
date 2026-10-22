// Source: CLCSSmallBarcode.dll @ 4200c75c; FUN_4200c75c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_4200c75c(void *this,HDC param_1,int *param_2)

{
  HGDIOBJ h;
  int iVar1;
  void *local_1c;
  BSTR local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x4200c768;
  h = GetCurrentObject(param_1,7);
  if ((h != (HGDIOBJ)0x0) && (iVar1 = GetObjectW(h,0x54,(LPVOID)((int)this + 0x8c)), iVar1 != 0)) {
    iVar1 = *(int *)((int)this + 0x98) + 3;
    *(int *)((int)this + 4) = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
    iVar1 = (**(code **)(*(int *)this + 0x10))(&local_1c,local_14,(int)this + 0x100);
    if (-1 < iVar1) {
      iVar1 = (local_14[0] + -1) * *(int *)((int)this + 0xec) +
              (*(int *)((int)this + 0xf0) + *(int *)((int)this + 0xec) * 2) * 3 * local_14[0];
      *(int *)((int)this + 0x70) = iVar1;
      if (*(int *)((int)this + 0x1c) != 0) {
        *(int *)((int)this + 0x70) = iVar1 + *(int *)((int)this + 0xf4) * 2;
      }
      iVar1 = FUN_4200b42d((int)this);
      if (((iVar1 == 0) && (iVar1 = FUN_4200c99b(this,(int)local_1c,local_14[0]), -1 < iVar1)) &&
         (*(int *)((int)this + 0x18) != 0)) {
        if (*(int *)((int)this + 0x108) == 3) {
          FUN_42002e4a(&local_18,(int *)((int)this + 0x58));
          local_8 = 0;
          FUN_4200bdaa((BSTR)&local_18,(int *)((int)this + 0x58));
          local_8 = 0xffffffff;
          SysFreeString(local_18);
        }
        iVar1 = FUN_4200cb5f(this,param_1,param_2);
      }
    }
    FID_conflict__free(local_1c);
    return iVar1;
  }
  return -0x7fffbffb;
}


