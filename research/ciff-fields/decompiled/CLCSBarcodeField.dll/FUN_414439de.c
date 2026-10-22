// Source: CLCSBarcodeField.dll @ 414439de; FUN_414439de

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

char __thiscall FUN_414439de(void *this,int param_1)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined8 uVar5;
  
  uVar5 = DAT_414842a0;
  uVar1 = DAT_41484288;
  if (param_1 == 0x13) {
    *(undefined4 *)((int)this + 0x40) = 0x13;
  }
  else {
    if (param_1 != 0x14) {
      cVar4 = '\0';
      goto LAB_41443a23;
    }
    *(undefined4 *)((int)this + 0x40) = 0x14;
    uVar5 = uVar1;
  }
  cVar4 = '\x01';
  *(undefined8 *)((int)this + 0x30) = uVar5;
LAB_41443a23:
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)this + 0x40);
  if ((cVar4 == '\x01') && (*(int *)((int)this + 0x44) == 0)) {
    puVar2 = (undefined4 *)FUN_41460343(0x100);
    puVar3 = (undefined4 *)0x0;
    if (puVar2 != (undefined4 *)0x0) {
      puVar3 = FUN_41449986(puVar2);
    }
    *(undefined4 **)((int)this + 0x44) = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      cVar4 = '\0';
    }
  }
  return cVar4;
}


