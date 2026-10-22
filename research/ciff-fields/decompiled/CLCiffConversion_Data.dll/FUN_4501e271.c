// Source: CLCiffConversion_Data.dll @ 4501e271; FUN_4501e271

undefined4 __thiscall FUN_4501e271(void *this,int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if ((iVar1 < *(int *)this) ||
     ((*(int *)this == iVar1 &&
      ((param_1[1] < *(int *)((int)this + 4) ||
       (((*(int *)this == iVar1 && (*(int *)((int)this + 4) == param_1[1])) &&
        (*(double *)(param_1 + 2) <= *(double *)((int)this + 8) &&
         *(double *)((int)this + 8) != *(double *)(param_1 + 2))))))))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


