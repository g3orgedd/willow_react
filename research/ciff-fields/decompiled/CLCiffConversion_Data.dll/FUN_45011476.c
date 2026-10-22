// Source: CLCiffConversion_Data.dll @ 45011476; FUN_45011476

int __thiscall FUN_45011476(void *this,undefined1 (*param_1) [16],LPCWSTR param_2)

{
  void *pvVar1;
  rsize_t rVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 (*pauVar5) [16];
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 (*pauVar9) [16];
  int iVar10;
  int local_1c;
  int local_10;
  int local_8;
  
  if ((param_1 == (undefined1 (*) [16])0x0) || (iVar4 = lstrlenW((LPCWSTR)param_1), iVar4 == 0)) {
    iVar8 = 0;
  }
  else {
    iVar8 = 0;
    local_1c = 0;
    if (param_2 == (LPCWSTR)0x0) {
      local_8 = 0;
    }
    else {
      local_8 = lstrlenW(param_2);
    }
    pauVar9 = *(undefined1 (**) [16])this;
    iVar7 = *(int *)(pauVar9[-1] + 8);
    puVar3 = *pauVar9;
    if (pauVar9 < (undefined1 (*) [16])(puVar3 + iVar7 * 2)) {
      do {
        pauVar5 = FUN_45022427(pauVar9,param_1);
        while (pauVar5 != (undefined1 (*) [16])0x0) {
          pauVar9 = (undefined1 (*) [16])(*pauVar5 + iVar4 * 2);
          iVar8 = iVar8 + 1;
          pauVar5 = FUN_45022427(pauVar9,param_1);
          local_1c = iVar8;
        }
        iVar6 = lstrlenW((LPCWSTR)pauVar9);
        pauVar9 = (undefined1 (*) [16])(*pauVar9 + iVar6 * 2 + 2);
      } while (pauVar9 < (undefined1 (*) [16])(puVar3 + iVar7 * 2));
      if (0 < iVar8) {
        FUN_4500363c(this);
        pvVar1 = *(void **)this;
        local_10 = *(int *)((int)pvVar1 + -8);
        iVar8 = (local_8 - iVar4) * local_1c + local_10;
        if ((*(int *)((int)pvVar1 + -4) < iVar8) || (1 < *(int *)((int)pvVar1 + -0xc))) {
          iVar7 = FUN_4500244d(this,iVar8);
          if (iVar7 == 0) {
            return -1;
          }
          FUN_45004ebd(*(void **)this,iVar8 * 2 + 2,pvVar1,*(int *)((int)pvVar1 + -8) * 2);
          FUN_45004176((int *)((int)pvVar1 + -0xc));
        }
        pauVar9 = *(undefined1 (**) [16])this;
        iVar7 = *(int *)(pauVar9[-1] + 8);
        puVar3 = *pauVar9;
        for (; pauVar9 < (undefined1 (*) [16])(puVar3 + iVar7 * 2);
            pauVar9 = (undefined1 (*) [16])(*pauVar9 + iVar6 * 2 + 2)) {
          pauVar5 = FUN_45022427(pauVar9,param_1);
          if (pauVar5 != (undefined1 (*) [16])0x0) {
            do {
              iVar6 = (int)pauVar5 - *(int *)this >> 1;
              iVar10 = *(int *)(*(int *)this + -4) - iVar6;
              pauVar9 = (undefined1 (*) [16])(*pauVar5 + local_8 * 2);
              rVar2 = ((local_10 - iVar6) - iVar4) * 2;
              FUN_45014375(pauVar9,(iVar10 - local_8) * 2 + 2,*pauVar5 + iVar4 * 2,rVar2);
              FUN_45004ebd(pauVar5,iVar10 * 2 + 2,param_2,local_8 * 2);
              *(undefined2 *)(rVar2 + (int)pauVar9) = 0;
              local_10 = local_10 + (local_8 - iVar4);
              pauVar5 = FUN_45022427(pauVar9,param_1);
            } while (pauVar5 != (undefined1 (*) [16])0x0);
          }
          iVar6 = lstrlenW((LPCWSTR)pauVar9);
        }
        *(int *)(*(int *)this + -8) = iVar8;
        iVar8 = local_1c;
      }
    }
  }
  return iVar8;
}


