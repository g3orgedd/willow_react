// Source: CLARiSOFT.exe @ 00e36a16; FUN_00e36a16

void __thiscall FUN_00e36a16(void *this,undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)((int)this + 4);
  if (0 < iVar1) {
    do {
      piVar2 = (int *)FUN_00e77808(this,iVar3);
      if ((undefined4 *)*piVar2 != param_1) {
        (*(code *)**(undefined4 **)*piVar2)(param_1,param_2,param_3);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}


