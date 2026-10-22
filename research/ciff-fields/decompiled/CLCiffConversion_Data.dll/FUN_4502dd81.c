// Source: CLCiffConversion_Data.dll @ 4502dd81; doexit

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x4502dea1) */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 2012 Release */

void __cdecl doexit(int param_1,int param_2,int param_3)

{
  int *piVar1;
  PVOID pvVar2;
  code *pcVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *local_20;
  
  __lock(8);
  pcVar3 = DecodePointer_exref;
  if (DAT_450553a4 != 1) {
    DAT_450553cc = 1;
    DAT_450553c8 = (undefined1)param_3;
    if (param_2 == 0) {
      local_20 = DecodePointer(DAT_45056f90);
      if (local_20 != (int *)0x0) {
        piVar1 = DecodePointer(DAT_45056f8c);
        piVar6 = piVar1;
        while (piVar1 = piVar1 + -1, local_20 <= piVar1) {
          pvVar2 = EncodePointer((PVOID)0x0);
          if ((PVOID)*piVar1 != pvVar2) {
            if (piVar1 < local_20) break;
            pcVar3 = (code *)(*pcVar3)(*piVar1);
            pvVar2 = EncodePointer((PVOID)0x0);
            *piVar1 = (int)pvVar2;
            (*pcVar3)();
            pcVar3 = DecodePointer_exref;
            piVar4 = DecodePointer(DAT_45056f90);
            piVar5 = DecodePointer(DAT_45056f8c);
            if ((local_20 != piVar4) || (piVar6 != piVar5)) {
              piVar1 = piVar5;
              local_20 = piVar4;
              piVar6 = piVar5;
            }
          }
        }
      }
      FUN_4502dd17((undefined4 *)&DAT_4503d2d4,(undefined4 *)&DAT_4503d2e4);
    }
    FUN_4502dd17((undefined4 *)&DAT_4503d2e8,(undefined4 *)&DAT_4503d2ec);
  }
  FUN_4502de9b();
  if (param_3 == 0) {
    DAT_450553a4 = 1;
    FUN_45031f41(8);
    ___crtExitProcess(param_1);
    return;
  }
  return;
}


