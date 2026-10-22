// Source: CLCiffConversion_Layout.dll @ 45421e35; FUN_45421e35

bool FUN_45421e35(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_4541cb7f(param_1);
  iVar3 = FUN_4541cb7f(param_2);
  if (iVar2 < iVar3) {
    bVar1 = true;
  }
  else {
    iVar2 = FUN_4541cb7f(param_1);
    iVar3 = FUN_4541cb7f(param_2);
    if (iVar2 == iVar3) {
      iVar2 = FUN_4541cd30(param_1);
      iVar3 = FUN_4541cd30(param_2);
      bVar1 = iVar2 < iVar3;
    }
    else {
      bVar1 = false;
    }
  }
  return bVar1;
}


