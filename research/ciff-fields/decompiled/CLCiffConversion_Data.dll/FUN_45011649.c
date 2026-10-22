// Source: CLCiffConversion_Data.dll @ 45011649; FUN_45011649

void __thiscall FUN_45011649(void *this,float param_1,float param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    iVar1 = FUN_4500febb((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x84))
              (*(int **)((int)this + 4),(int)((float)iVar1 * param_2));
    iVar1 = FUN_4500feda((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x7c))
              (*(int **)((int)this + 4),(int)((float)iVar1 * param_1) * iVar1);
    iVar1 = FUN_4500fef6((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x30))
              (*(int **)((int)this + 4),(int)((float)iVar1 * param_1) * iVar1);
    iVar1 = FUN_4500ff12((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x38))
              (*(int **)((int)this + 4),(int)((float)iVar1 * param_2));
  }
  iVar1 = FUN_4500ff84((int)this);
  if (iVar1 == 0) {
    iVar1 = FUN_4500ff65((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0xb4))
              (*(int **)((int)this + 4),(int)((float)iVar1 * param_2));
  }
  return;
}


