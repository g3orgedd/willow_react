// Source: CLCiffConversion_Data.dll @ 4502274d; FUN_4502274d

int __cdecl FUN_4502274d(ushort *param_1,ushort *param_2,int *param_3)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_45021444(local_14,param_3);
  if ((param_1 == (ushort *)0x0) || (param_2 == (ushort *)0x0)) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_45027e29();
    iVar5 = 0x7fffffff;
  }
  else {
    if (*(int *)(local_14[0] + 0xa8) == 0) {
      iVar5 = (int)param_1 - (int)param_2;
      do {
        uVar1 = *(ushort *)(iVar5 + (int)param_2);
        if ((0x40 < uVar1) && (uVar1 < 0x5b)) {
          uVar1 = uVar1 + 0x20;
        }
        uVar2 = *param_2;
        if ((0x40 < uVar2) && (uVar2 < 0x5b)) {
          uVar2 = uVar2 + 0x20;
        }
        param_2 = param_2 + 1;
      } while ((uVar1 != 0) && (uVar1 == uVar2));
    }
    else {
      do {
        uVar4 = FUN_45027fb4((uint)*param_1,local_14);
        uVar1 = (ushort)uVar4;
        param_1 = param_1 + 1;
        uVar4 = FUN_45027fb4((uint)*param_2,local_14);
        uVar2 = (ushort)uVar4;
        param_2 = param_2 + 1;
        if (uVar1 == 0) break;
      } while (uVar1 == uVar2);
    }
    iVar5 = (uint)uVar1 - (uint)uVar2;
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar5;
}


