// Source: CLCiffConversion_Layout.dll @ 4542eeb9; FUN_4542eeb9

undefined1 (*) [16] __cdecl
FUN_4542eeb9(undefined1 (*param_1) [16],undefined1 (*param_2) [16],int *param_3)

{
  byte bVar1;
  undefined1 (*pauVar2) [16];
  int *piVar3;
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  undefined1 (*pauVar8) [16];
  undefined1 (*pauVar9) [16];
  undefined1 (*pauVar10) [16];
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  char local_10;
  
  FUN_4542c8eb(local_1c,param_3);
  pauVar8 = (undefined1 (*) [16])0x0;
  if (*(int *)(local_18 + 8) == 0) {
    pauVar2 = FUN_45439d90(param_1,param_2);
    goto LAB_4542ef85;
  }
  if (param_2 != (undefined1 (*) [16])0x0) {
    pauVar2 = param_1;
    if ((*param_2)[0] == '\0') goto LAB_4542ef85;
    if (param_1 != (undefined1 (*) [16])0x0) {
      sVar4 = _strlen((char *)param_2);
      sVar5 = _strlen((char *)param_1);
      pauVar2 = pauVar8;
      if ((*param_1)[0] != '\0') {
        iVar6 = (int)param_1 - (int)param_2;
        pauVar9 = param_1;
        while (pauVar2 = pauVar8, pauVar9 <= (undefined1 (*) [16])((int)param_1 + (sVar5 - sVar4)))
        {
          pauVar10 = param_2;
          bVar1 = (*pauVar9)[0];
          while (pauVar2 = pauVar9, bVar1 != 0) {
            if ((*pauVar10)[0] == '\0') goto LAB_4542ef85;
            if ((*pauVar10)[iVar6] != (*pauVar10)[0]) break;
            pauVar10 = (undefined1 (*) [16])(*pauVar10 + 1);
            bVar1 = (*pauVar10)[iVar6];
          }
          if ((*pauVar10)[0] == '\0') break;
          pauVar10 = (undefined1 (*) [16])(*pauVar9 + 1);
          iVar7 = iVar6 + 1;
          if ((*(byte *)((byte)(*pauVar9)[0] + 0x19 + local_18) & 4) != 0) {
            pauVar2 = pauVar8;
            if ((*pauVar10)[0] == '\0') break;
            pauVar10 = (undefined1 (*) [16])(*pauVar9 + 2);
            iVar7 = iVar6 + 2;
          }
          iVar6 = iVar7;
          pauVar2 = pauVar8;
          pauVar9 = pauVar10;
          if ((*pauVar10)[0] == '\0') break;
        }
      }
      goto LAB_4542ef85;
    }
  }
  piVar3 = __errno();
  *piVar3 = 0x16;
  FUN_45432798();
  pauVar2 = pauVar8;
LAB_4542ef85:
  if (local_10 != '\0') {
    *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
  }
  return pauVar2;
}


