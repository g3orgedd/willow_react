// Source: CiffMgr.dll @ 68108420; FUN_68108420

int FUN_68108420(int param_1,void **param_2)

{
  int *piVar1;
  int iVar2;
  int *local_8;
  
  iVar2 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    iVar2 = FUN_68108494(&local_8);
    if (-1 < iVar2) {
      piVar1 = *(int **)(param_1 + 8);
      FUN_6811538e(local_8 + 1,*(int **)(param_1 + 4));
      local_8[2] = (int)piVar1;
      local_8[3] = *piVar1;
      local_8[3] = *(int *)(param_1 + 0xc);
      iVar2 = ATL::AtlInternalQueryInterface
                        (local_8,(_ATL_INTMAP_ENTRY *)&PTR_DAT_681480dc,(_GUID *)&DAT_6814e19c,
                         param_2);
      if (iVar2 < 0) {
        (**(code **)(*local_8 + 0x1c))(1);
      }
    }
  }
  return iVar2;
}


