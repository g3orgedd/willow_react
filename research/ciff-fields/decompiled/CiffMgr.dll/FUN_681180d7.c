// Source: CiffMgr.dll @ 681180d7; FUN_681180d7

void __fastcall FUN_681180d7(void *param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  *(undefined2 *)((int)param_1 + 0xad8) = 0;
  *(undefined2 *)((int)param_1 + 0xace) = 0;
  if (*(int *)((int)param_1 + 8) != 0) {
    puVar1 = (undefined2 *)((int)param_1 + 0xa9c);
    do {
      uVar2 = uVar2 + 1;
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    } while (uVar2 < *(uint *)((int)param_1 + 8));
  }
  for (iVar3 = *(int *)((int)param_1 + 0xae0); iVar3 != 0; iVar3 = iVar3 + -1) {
    FUN_68117f62(param_1,0);
  }
  return;
}


