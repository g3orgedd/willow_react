// Source: CLCiffConversion_Data.dll @ 45008ab7; FUN_45008ab7

int * __thiscall FUN_45008ab7(void *this,int *param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int *local_8;
  
  piVar3 = param_1;
  local_8 = this;
  piVar2 = FUN_45009021(this,param_1);
  if (piVar2 != *(int **)this) {
    bVar1 = FUN_45008b14(piVar3,piVar2 + 4);
    if (!bVar1) goto LAB_45008b08;
  }
  local_8 = piVar3;
  piVar3 = FUN_450083cb(this,&DAT_45053868,&local_8);
  FUN_4500854c(this,&param_1,piVar2,piVar3 + 4,piVar3);
  piVar2 = param_1;
LAB_45008b08:
  return piVar2 + 5;
}


