// Source: CLCiffConversion_Layout.dll @ 4540784b; FUN_4540784b

int * __thiscall FUN_4540784b(void *this,int *param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int *local_8;
  
  piVar3 = param_1;
  local_8 = this;
  piVar2 = FUN_45407db7(this,param_1);
  if (piVar2 != *(int **)this) {
    bVar1 = FUN_454078ec(piVar3,piVar2 + 4);
    if (!bVar1) goto LAB_4540789c;
  }
  local_8 = piVar3;
  piVar3 = FUN_45407195(this,&DAT_4545fbc2,&local_8);
  FUN_45407316(this,&param_1,piVar2,piVar3 + 4,piVar3);
  piVar2 = param_1;
LAB_4540789c:
  return piVar2 + 5;
}


