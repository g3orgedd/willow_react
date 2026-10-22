// Source: CLCiffConversion_Layout.dll @ 4541100c; FUN_4541100c

BSTR __thiscall FUN_4541100c(void *this,int *param_1,int param_2)

{
  UINT UVar1;
  size_t ui;
  BSTR pOVar2;
  uint uVar3;
  int *piVar4;
  
  *(undefined4 *)((int)this + 0xa8) = 0;
  SysFreeString(*(BSTR *)((int)this + 0xb8));
  *(undefined4 *)((int)this + 0xb8) = 0;
  UVar1 = SysStringLen((BSTR)*param_1);
  uVar3 = 0;
  if (UVar1 != 0) {
    do {
      FUN_45411e13(this,(uint)*(ushort *)(*param_1 + uVar3 * 2),param_2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < UVar1);
  }
  piVar4 = (int *)((int)this + 0xb8);
  FUN_45411e13(this,0,param_2);
  FUN_4540303d(0x45448f20);
  FUN_45410e4d(this,piVar4);
  if (*piVar4 == 0) {
    pOVar2 = (BSTR)0x0;
  }
  else {
    ui = _wcslen((wchar_t *)*piVar4);
    pOVar2 = SysAllocStringLen((OLECHAR *)*piVar4,ui);
  }
  return pOVar2;
}


