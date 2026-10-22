// Source: CLCSSmallBarcode.dll @ 4205e9f4; FUN_4205e9f4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_4205e9f4(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined8 uVar4;
  
  if ((param_1 < 10) ||
     (((uVar4 = DAT_4209e2f8, 0xb < param_1 && (uVar4 = DAT_4209e2e0, 0xd < param_1)) &&
      (uVar4 = DAT_4209e2e8, param_1 != 0xe)))) {
    bVar3 = false;
  }
  else {
    puVar2 = (undefined4 *)0x0;
    *(undefined8 *)((int)this + 0x30) = uVar4;
    bVar3 = true;
    *(int *)((int)this + 0x14) = param_1;
    if (*(int *)((int)this + 0x40) == 0) {
      puVar1 = (undefined4 *)FUN_42067914(0xfc);
      if (puVar1 != (undefined4 *)0x0) {
        puVar2 = FUN_420299ed(puVar1);
      }
      bVar3 = puVar2 != (undefined4 *)0x0;
      *(undefined4 **)((int)this + 0x40) = puVar2;
    }
  }
  return bVar3;
}


