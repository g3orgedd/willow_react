// Source: CLPrintPreview.ocx @ 3f417e69; FUN_3f417e69

void __fastcall FUN_3f417e69(void *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_3f415c52(param_1,*(int *)((int)param_1 + 0x170) - *(int *)((int)param_1 + 0x168),1);
  iVar2 = FUN_3f415c52(param_1,*(int *)((int)param_1 + 0x174) - *(int *)((int)param_1 + 0x16c),0);
  iVar1 = *(int *)((int)param_1 + 0x1b0) - iVar1;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  iVar2 = *(int *)((int)param_1 + 0x1b4) - iVar2;
  *(int *)((int)param_1 + 0x17c) = iVar1;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  *(int *)((int)param_1 + 0x184) = iVar2;
  FUN_3f403715(0x3f4433d4);
  FUN_3f415eb5((void *)((int)param_1 + 0xb4),0,*(undefined4 *)((int)param_1 + 0x17c),0,
               *(undefined4 *)((int)param_1 + 0x184));
  return;
}


