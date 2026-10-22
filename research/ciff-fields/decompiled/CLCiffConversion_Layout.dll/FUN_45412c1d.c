// Source: CLCiffConversion_Layout.dll @ 45412c1d; FUN_45412c1d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_45412c1d(void *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  LPCSTR pCVar3;
  
  FUN_45412452((undefined4 *)((int)param_1 + 0xc));
  *(undefined4 *)((int)param_1 + 0x2c) = 0;
  *(undefined4 *)((int)param_1 + 0x30) = 0;
  *(undefined4 *)((int)param_1 + 0x34) = 0;
  *(undefined4 *)((int)param_1 + 0x38) = 0;
  *(undefined4 *)((int)param_1 + 0x40) = 0;
  FUN_4542cebb((int)param_1 + 0x48,0x30,0x18,FUN_45412d30);
  *(undefined4 *)((int)param_1 + 0x4c8) = 0;
  *(undefined4 *)((int)param_1 + 0x4cc) = 0;
  uVar2 = FUN_454043b0((int *)0x0,(int *)0x0);
  *(undefined4 *)((int)param_1 + 0x4c8) = uVar2;
  *(undefined4 *)((int)param_1 + 0x4d0) = 0;
  *(undefined4 *)((int)param_1 + 0x4d4) = 0;
  *(undefined4 *)((int)param_1 + 0x4d8) = 0;
  *(undefined **)((int)param_1 + 0x4dc) = PTR_DAT_4545d110;
  *(undefined4 *)((int)param_1 + 0x4e0) = PTR_DAT_4545d110;
  piVar1 = *(int **)((int)param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  pCVar3 = (LPCSTR)FUN_45408450();
  FUN_45402cd0((undefined4 *)((int)param_1 + 0x4e0),pCVar3);
  FUN_454287c9(param_1,'\x01');
  *(undefined1 *)((int)param_1 + 0x4e4) = 0;
  FUN_45415fe0("CLCiffConversion_Layout");
  *(undefined4 *)((int)param_1 + 0x3c) = 0;
  return param_1;
}


