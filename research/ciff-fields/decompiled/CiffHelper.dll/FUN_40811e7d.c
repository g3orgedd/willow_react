// Source: CiffHelper.dll @ 40811e7d; FUN_40811e7d

void __fastcall FUN_40811e7d(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar1 = (undefined4 *)*param_1;
  puVar2 = (undefined4 *)*puVar1;
  puVar4 = (undefined4 *)*puVar2;
  while (puVar4 != puVar1) {
    iVar5 = FUN_40808f0b(puVar2 + 2,(wchar_t *)(puVar4 + 2));
    if (iVar5 == 0) {
      puVar3 = (undefined4 *)*puVar4;
      *puVar2 = puVar3;
      puVar3[1] = puVar2;
      FUN_40819551(puVar4);
      param_1[1] = param_1[1] + -1;
      puVar4 = puVar3;
    }
    else {
      puVar2 = puVar4;
      puVar4 = (undefined4 *)*puVar4;
    }
  }
  return;
}


