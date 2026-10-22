// Source: CLCiffConversion_Layout.dll @ 4540ba4b; FUN_4540ba4b

uint __thiscall FUN_4540ba4b(void *this,int param_1)

{
  int *piVar1;
  uint in_EAX;
  int iVar2;
  uint uVar3;
  
  if (*(char *)((int)this + 0x128) != '\0') {
    piVar1 = *(int **)((int)this + 0x124);
    uVar3 = 0;
    in_EAX = 0;
    if ((piVar1[1] - *piVar1) / 0xc != 0) {
      iVar2 = *piVar1;
      in_EAX = 0;
      do {
        if (param_1 == *(int *)(in_EAX + iVar2 + 8)) {
          return CONCAT31((int3)(in_EAX >> 8),1);
        }
        in_EAX = in_EAX + 0xc;
        uVar3 = uVar3 + 1;
        iVar2 = *piVar1;
      } while (uVar3 < (uint)((piVar1[1] - *piVar1) / 0xc));
    }
  }
  return in_EAX & 0xffffff00;
}


