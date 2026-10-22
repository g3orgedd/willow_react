// Source: CLCiffConversion_Layout.dll @ 45416187; FUN_45416187

int __cdecl FUN_45416187(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if (param_1 == param_3) {
    return param_1;
  }
  if (param_2 != param_3) {
    if (param_1 == param_2) {
      return param_1;
    }
    iVar2 = param_2 - param_3;
    iVar3 = param_1 - param_3;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    bVar4 = SBORROW4(iVar3,iVar2);
    iVar1 = iVar3 - iVar2;
    if (iVar3 == iVar2) {
      bVar4 = SBORROW4(param_1,param_2);
      iVar1 = param_1 - param_2;
    }
    if (bVar4 != iVar1 < 0) {
      param_2 = param_1;
    }
  }
  return param_2;
}


