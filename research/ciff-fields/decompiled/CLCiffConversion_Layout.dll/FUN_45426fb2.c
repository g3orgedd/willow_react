// Source: CLCiffConversion_Layout.dll @ 45426fb2; FUN_45426fb2

int __thiscall FUN_45426fb2(void *this,int param_1,uint *param_2)

{
  bool bVar1;
  uint *puVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  piVar4 = *(int **)((int)this + 0x2c);
  iVar5 = 0;
  if ((piVar4 != (int *)0x0) && (puVar2 = (uint *)*piVar4, puVar2 != (uint *)0x0)) {
    do {
      if ((param_2 == (uint *)0x0) ||
         (bVar1 = FUN_454285b6(param_2,puVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_4542505a((GUID *)*piVar4,piVar3,iVar6);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      piVar4 = piVar4 + 9;
      puVar2 = (uint *)*piVar4;
    } while (puVar2 != (uint *)0x0);
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  iVar5 = FUN_45426f84(param_1,param_2);
  return iVar5;
}


