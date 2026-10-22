// Source: CLARiSOFT.exe @ 00e4a7de; FUN_00e4a7de

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_00e4a7de(void *param_1)

{
  uint uVar1;
  char cVar2;
  HDC hdc;
  int iVar3;
  DEVMODEW *lpdm;
  undefined1 uVar4;
  uint uVar5;
  undefined4 local_14;
  
  uVar4 = 0;
  hdc = FUN_00e495c4(param_1,*(DEVMODEW **)((int)param_1 + 8));
  iVar3 = 0;
  if (hdc != (HDC)0x0) {
    iVar3 = StartDocW(hdc,(DOCINFOW *)((int)param_1 + 0xc));
    *(int *)((int)param_1 + 0x20) = iVar3;
    uVar4 = 0;
    if (0 < iVar3) {
      (**(code **)**(undefined4 **)((int)param_1 + 4))(hdc);
      local_14 = 0;
      uVar1 = *(uint *)((int)param_1 + 0x28);
      while (uVar5 = uVar1, uVar5 <= *(uint *)((int)param_1 + 0x2c)) {
        cVar2 = (**(code **)(**(int **)((int)param_1 + 4) + 0x18))(uVar5);
        if (cVar2 == '\0') break;
        lpdm = (DEVMODEW *)(**(code **)(**(int **)((int)param_1 + 4) + 0x14))(local_14,uVar5);
        if (lpdm != (DEVMODEW *)0x0) {
          ResetDCW(hdc,lpdm);
        }
        StartPage(hdc);
        (**(code **)(**(int **)((int)param_1 + 4) + 8))(uVar5,hdc);
        cVar2 = (**(code **)(**(int **)((int)param_1 + 4) + 0xc))(uVar5,hdc);
        if (cVar2 == '\0') {
          *(undefined1 *)((int)param_1 + 0x24) = 1;
        }
        (**(code **)(**(int **)((int)param_1 + 4) + 0x10))(uVar5,hdc);
        EndPage(hdc);
        if (*(char *)((int)param_1 + 0x24) != '\0') break;
        local_14 = uVar5;
        uVar1 = uVar5 + 1;
      }
      (**(code **)(**(int **)((int)param_1 + 4) + 4))(hdc,*(undefined1 *)((int)param_1 + 0x24));
      if (*(char *)((int)param_1 + 0x24) == '\0') {
        iVar3 = EndDoc(hdc);
      }
      else {
        iVar3 = AbortDoc(hdc);
      }
      *(undefined4 *)((int)param_1 + 0x20) = 0;
      uVar4 = 1;
    }
    if (hdc != (HDC)0x0) {
      iVar3 = DeleteDC(hdc);
    }
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),uVar4);
}


