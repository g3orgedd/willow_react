// Source: CLARiSOFT.exe @ 00e2e20c; FUN_00e2e20c

uint __thiscall FUN_00e2e20c(void *this,CComBSTR *param_1)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  uint in_EAX;
  undefined3 extraout_var;
  undefined4 *puVar4;
  int iVar5;
  
  iVar2 = *(int *)((int)this + 8);
  iVar5 = 0;
  puVar4 = (undefined4 *)**(undefined4 **)((int)this + 4);
  if (0 < iVar2) {
    do {
      piVar1 = puVar4 + 2;
      puVar4 = (undefined4 *)*puVar4;
      in_EAX = *(uint *)*piVar1;
      if (*(int *)(in_EAX + 0x10) == 3) {
        bVar3 = ATL::CComBSTR::operator==((CComBSTR *)((uint *)*piVar1 + 1),param_1);
        in_EAX = CONCAT31(extraout_var,bVar3);
        if (bVar3) {
          return CONCAT31(extraout_var,1);
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar2);
  }
  return in_EAX & 0xffffff00;
}


