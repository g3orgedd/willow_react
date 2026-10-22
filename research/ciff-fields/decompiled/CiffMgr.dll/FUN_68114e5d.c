// Source: CiffMgr.dll @ 68114e5d; FUN_68114e5d

undefined4 FUN_68114e5d(int param_1,OLECHAR *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  BSTR extraout_var;
  
  FUN_6810210e(&stack0xffffffec,param_2);
  puVar1 = FUN_68114a53(&param_2,*(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 8),
                        extraout_var);
  if ((VARIANTARG *)*puVar1 == *(VARIANTARG **)(param_1 + 8)) {
    uVar2 = 0x80070057;
  }
  else {
    FUN_68104800((void *)(param_1 + 4),&param_2,(VARIANTARG *)*puVar1);
    uVar2 = 0;
  }
  return uVar2;
}


