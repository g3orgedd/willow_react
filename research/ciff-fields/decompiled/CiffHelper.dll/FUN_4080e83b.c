// Source: CiffHelper.dll @ 4080e83b; FUN_4080e83b

uint __cdecl FUN_4080e83b(ushort *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (*(int *)(param_1 + -4) == 5) {
    iVar2 = *(int *)("***** GetADOErrors  ***** ADO EXCEPTION ******* Error.Error(0x%08x)" +
                    (uint)*param_1 * 4 + 0x34) +
            *(int *)(
                    "***** GetADOErrors  ***** ADO EXCEPTION ******* CCLError::ErrorMessage *** %ls"
                    + (uint)param_1[1] * 4 + 0x34) +
            *(int *)("CCiffDataHelper::OpenConnection" + (uint)param_1[2] * 4 + 0x18) +
            *(int *)("***** GetADOErrors  ***** ADO EXCEPTION ******* Error.Error(0x%08x)" +
                    (uint)param_1[3] * 4 + 0x34) +
            *(int *)(
                    "***** GetADOErrors  ***** ADO EXCEPTION ******* CCLError::ErrorMessage *** %ls"
                    + (uint)param_1[4] * 4 + 0x34);
  }
  else if (*(int *)(param_1 + -4) == 4) {
    iVar2 = *(int *)(
                    "***** GetADOErrors  ***** ADO EXCEPTION ******* CCLError::ErrorMessage *** %ls"
                    + (uint)*param_1 * 4 + 0x34) +
            *(int *)(
                    "***** GetADOErrors  ***** ADO EXCEPTION ******* CCLError::ErrorMessage *** %ls"
                    + (uint)param_1[1] * 4 + 0x34) +
            *(int *)("***** GetADOErrors  ***** ADO EXCEPTION ******* Error.Error(0x%08x)" +
                    (uint)param_1[2] * 4 + 0xc) +
            *(int *)("CCiffDataHelper::OpenConnection" + (uint)param_1[3] * 4 + 0x18);
  }
  uVar1 = 0;
  do {
    if (*(int *)(param_1 + -4) == 5) {
      uVar3 = uVar1;
      if ((&DAT_4084bf44)[uVar1] == 10 - iVar2 % 10) break;
    }
    else if (*(int *)(param_1 + -4) == 4) {
      uVar3 = ((iVar2 % 10) * 3) % 10;
      break;
    }
    uVar1 = uVar1 + 1;
    uVar3 = 0;
  } while (uVar1 < 10);
  FUN_40803143((int *)&param_1);
  return uVar3;
}


