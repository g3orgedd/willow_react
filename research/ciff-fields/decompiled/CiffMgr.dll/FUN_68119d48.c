// Source: CiffMgr.dll @ 68119d48; FUN_68119d48

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_68119d48(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar1 = FUN_68124126(param_1,0x6815f7f0,7,(int *)local_14,&local_18);
  uVar2 = 0;
  if (-1 < iVar1) {
    uVar2 = local_18;
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return uVar2;
}


