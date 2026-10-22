// Source: CLCiffConversion_Layout.dll @ 4541f632; FUN_4541f632

void __thiscall FUN_4541f632(void *this,int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = FUN_4541d4ba((int)this);
  if (bVar1) {
    iVar2 = FUN_4541cd14((int)this);
    iVar3 = FUN_4541cb40((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x7c))
              (*(int **)((int)this + 4),
               (int)(((float)param_1 / (float)iVar3) * (float)iVar2 + DAT_45447488));
  }
  (**(code **)(**(int **)((int)this + 4) + 0x84))(*(int **)((int)this + 4),param_1);
  return;
}


