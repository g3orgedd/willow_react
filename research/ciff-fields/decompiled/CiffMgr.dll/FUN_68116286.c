// Source: CiffMgr.dll @ 68116286; FUN_68116286

void __cdecl FUN_68116286(undefined2 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = (*(code *)**(undefined4 **)*param_2)((undefined4 *)*param_2,&DAT_6814e18c,param_1 + 4);
  if (iVar1 < 0) {
    iVar1 = (*(code *)**(undefined4 **)*param_2)((undefined4 *)*param_2,&DAT_6814e1dc,param_1 + 4);
    if (iVar1 < 0) {
      return;
    }
    uVar2 = 0xd;
  }
  else {
    uVar2 = 9;
  }
  *param_1 = uVar2;
  return;
}


