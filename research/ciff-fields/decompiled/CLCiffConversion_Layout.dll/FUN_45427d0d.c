// Source: CLCiffConversion_Layout.dll @ 45427d0d; FUN_45427d0d

int __thiscall FUN_45427d0d(void *this,int param_1,uint *param_2)

{
  bool bVar1;
  uint *puVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)((int)this + 0x2c);
  iVar4 = 0;
  if ((piVar5 != (int *)0x0) && (puVar2 = (uint *)*piVar5, puVar2 != (uint *)0x0)) {
    do {
      if ((param_2 == (uint *)0x0) ||
         (bVar1 = FUN_454285b6(param_2,puVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar4 = 0;
        piVar3 = (int *)(*(code *)piVar5[7])();
        iVar4 = FUN_4542505a((GUID *)*piVar5,piVar3,iVar4);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (*(code *)piVar5[1])(0);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      piVar5 = piVar5 + 9;
      puVar2 = (uint *)*piVar5;
    } while (puVar2 != (uint *)0x0);
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  iVar4 = FUN_45427ce7(param_1,param_2);
  return iVar4;
}


