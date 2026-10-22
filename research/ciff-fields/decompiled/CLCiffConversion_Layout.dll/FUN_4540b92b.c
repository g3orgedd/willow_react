// Source: CLCiffConversion_Layout.dll @ 4540b92b; FUN_4540b92b

uint __thiscall FUN_4540b92b(void *this,int param_1,int param_2)

{
  uint *puVar1;
  uint in_EAX;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (*(char *)((int)this + 0x128) != '\0') {
    puVar1 = *(uint **)((int)this + 0x124);
    uVar4 = 0;
    in_EAX = 0;
    if ((int)(puVar1[1] - *puVar1) / 0xc != 0) {
      in_EAX = *puVar1;
      iVar3 = 0;
      do {
        iVar2 = *(int *)(iVar3 + in_EAX) - (param_1 - *(int *)((int)this + 0x100) >> 1);
        if (param_2 == iVar2) {
          return CONCAT31((int3)((uint)iVar2 >> 8),1);
        }
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 0xc;
        in_EAX = *puVar1;
      } while (uVar4 < (uint)((int)(puVar1[1] - *puVar1) / 0xc));
    }
  }
  return in_EAX & 0xffffff00;
}


