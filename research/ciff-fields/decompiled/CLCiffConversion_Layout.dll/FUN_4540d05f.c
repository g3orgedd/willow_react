// Source: CLCiffConversion_Layout.dll @ 4540d05f; FUN_4540d05f

void __thiscall FUN_4540d05f(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  
  puVar3 = (undefined8 *)_Allocate<>(param_1);
  FUN_4542a090(puVar3,*(undefined8 **)this,*(int *)((int)this + 4) - *(int *)this & 0xfffffffe);
  iVar1 = *(int *)((int)this + 4);
  iVar2 = *(int *)this;
  if (*(int *)this != 0) {
    FID_conflict__free(*(void **)this);
  }
  *(undefined8 **)this = puVar3;
  *(uint *)((int)this + 8) = (int)puVar3 + param_1 * 2;
  *(int *)((int)this + 4) = (int)puVar3 + (iVar1 - iVar2 >> 1) * 2;
  return;
}


