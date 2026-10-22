// Source: CiffMgr.dll @ 68124340; FUN_68124340

void FUN_68124340(int *param_1)

{
  OLECHAR OVar1;
  longlong lVar2;
  bool bVar3;
  undefined2 uVar4;
  UINT UVar5;
  OLECHAR *_Memory;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  UINT local_c;
  
  UVar5 = SysStringLen((BSTR)*param_1);
  iVar6 = 0;
  bVar3 = false;
  if (0 < (int)UVar5) {
    puVar7 = (ushort *)*param_1;
    iVar8 = 0;
    local_c = UVar5;
    do {
      uVar4 = FUN_6812451f(*puVar7);
      if ((char)uVar4 == '\0') {
        iVar8 = iVar8 + 1;
        bVar3 = true;
      }
      puVar7 = puVar7 + 1;
      local_c = local_c - 1;
    } while (local_c != 0);
    if (bVar3) {
      lVar2 = (ulonglong)((UVar5 - iVar8) + 1) * 2;
      _Memory = (OLECHAR *)FUN_68130f16(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2)
      ;
      iVar8 = 0;
      do {
        OVar1 = *(OLECHAR *)(*param_1 + iVar8 * 2);
        uVar4 = FUN_6812451f(OVar1);
        if ((char)uVar4 != '\0') {
          _Memory[iVar6] = OVar1;
          iVar6 = iVar6 + 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)UVar5);
      _Memory[iVar6] = L'\0';
      FUN_68102644(param_1,_Memory);
      FID_conflict__free(_Memory);
    }
  }
  return;
}


