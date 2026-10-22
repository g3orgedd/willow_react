// Source: CLARiSOFT.exe @ 00e11044; FUN_00e11044

uint __thiscall
FUN_00e11044(void *this,LPVARIANT param_1,LPVARIANT param_2,LCID param_3,ULONG param_4)

{
  char cVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  
  sVar3 = *(short *)this;
  if (sVar3 == 0x10) {
    cVar1 = *(char *)((int)&param_1->n1 + 8);
    cVar2 = *(char *)((int)&param_2->n1 + 8);
    if (cVar1 != cVar2) {
      if (cVar2 < cVar1) {
        return 2;
      }
      return 0;
    }
  }
  else {
    if (sVar3 == 0x12) {
      uVar4 = *(ushort *)((int)&param_1->n1 + 8);
      uVar5 = *(ushort *)((int)&param_2->n1 + 8);
      bVar10 = uVar5 < uVar4;
      bVar11 = uVar5 == uVar4;
    }
    else {
      if (sVar3 != 0x13) {
        if (sVar3 != 0x15) {
          uVar9 = VarCmp(param_1,param_2,param_3,param_4);
          return uVar9;
        }
        uVar9 = *(uint *)((int)&param_1->n1 + 8);
        uVar6 = *(uint *)((int)&param_1->n1 + 0xc);
        uVar7 = *(uint *)((int)&param_2->n1 + 8);
        uVar8 = *(uint *)((int)&param_2->n1 + 0xc);
        if ((uVar9 == uVar7) && (uVar6 == uVar8)) {
          return 1;
        }
        if (uVar8 <= uVar6) {
          if (uVar6 != uVar8) {
            return 2;
          }
          if (uVar7 < uVar9) {
            return 2;
          }
        }
        return 0;
      }
      uVar9 = *(uint *)((int)&param_1->n1 + 8);
      uVar6 = *(uint *)((int)&param_2->n1 + 8);
      bVar10 = uVar6 < uVar9;
      bVar11 = uVar6 == uVar9;
    }
    if (!bVar11) {
      return -(uint)bVar10 & 2;
    }
  }
  return 1;
}


