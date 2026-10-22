// Source: CLCiffConversion_Layout.dll @ 4541fb66; FUN_4541fb66

void __thiscall FUN_4541fb66(void *this,float param_1,float param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    iVar1 = FUN_4541cb40((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x84))
              (*(int **)((int)this + 4),(int)((float)iVar1 * param_2));
    iVar1 = FUN_4541cd14((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x7c))
              (*(int **)((int)this + 4),(int)((float)iVar1 * param_1) * iVar1);
    iVar1 = FUN_4541cd30((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x30))
              (*(int **)((int)this + 4),(int)((float)iVar1 * param_1) * iVar1);
    iVar1 = FUN_4541cd4c((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x38))
              (*(int **)((int)this + 4),(int)((float)iVar1 * param_2));
  }
  iVar1 = FUN_4541d01d((int)this);
  if (iVar1 == 0) {
    iVar1 = FUN_4541cded((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0xb4))
              (*(int **)((int)this + 4),(int)((float)iVar1 * param_2));
  }
  return;
}


