// Source: CLCiffConversion_Layout.dll @ 4542273a; FUN_4542273a

void __thiscall FUN_4542273a(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)((int)this + 4);
  if ((param_1 < puVar3) && (*(undefined4 **)this <= param_1)) {
    iVar1 = *(int *)this;
    if (puVar3 == *(undefined4 **)((int)this + 8)) {
      FUN_45422307(this,1);
    }
    puVar3 = *(undefined4 **)((int)this + 4);
    if (puVar3 == (undefined4 *)0x0) goto LAB_45422785;
    uVar2 = *(undefined4 *)(*(int *)this + ((int)param_1 - iVar1 >> 2) * 4);
  }
  else {
    if (puVar3 == *(undefined4 **)((int)this + 8)) {
      FUN_45422307(this,1);
    }
    puVar3 = *(undefined4 **)((int)this + 4);
    if (puVar3 == (undefined4 *)0x0) goto LAB_45422785;
    uVar2 = *param_1;
  }
  *puVar3 = uVar2;
LAB_45422785:
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  return;
}


