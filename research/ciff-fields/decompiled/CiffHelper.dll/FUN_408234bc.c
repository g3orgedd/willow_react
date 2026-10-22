// Source: CiffHelper.dll @ 408234bc; FUN_408234bc

int __thiscall FUN_408234bc(void *this,BSTR param_1)

{
  BSTR pOVar1;
  int iVar2;
  int *piVar3;
  BSTR extraout_ECX;
  BSTR pOVar4;
  
  pOVar1 = param_1;
  iVar2 = FUN_408228d4(this,(undefined4 *)param_1);
  if ((-1 < iVar2) && (*(int *)this != 0)) {
    iVar2 = FUN_408223f4((undefined4 *)pOVar1);
    if (-1 < iVar2) {
      piVar3 = (int *)FUN_40821231(*(CComBSTR **)((int)this + 4),*(CComBSTR **)((int)this + 8),this)
      ;
      if (piVar3 != *(int **)((int)this + 8)) {
        FUN_40823563((void *)((int)this + 4),&param_1,piVar3);
      }
      iVar2 = FUN_40822d03((undefined4 *)pOVar1,0);
      if (-1 < iVar2) {
        pOVar4 = extraout_ECX;
        FUN_40803baf(&stack0xffffffec,this);
        iVar2 = FUN_408213b8(this,(int *)pOVar1,pOVar4);
        if (-1 < iVar2) {
          FUN_40821329(this,pOVar1);
        }
      }
    }
  }
  return iVar2;
}


