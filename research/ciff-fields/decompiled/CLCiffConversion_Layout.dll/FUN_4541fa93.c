// Source: CLCiffConversion_Layout.dll @ 4541fa93; FUN_4541fa93

void __thiscall FUN_4541fa93(void *this,float param_1,float param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  float fVar3;
  
  bVar1 = FUN_4541d4ba((int)this);
  fVar3 = param_1;
  if ((bVar1) && (fVar3 = param_2, param_2 <= param_1)) {
    param_2 = param_1;
    fVar3 = param_1;
  }
  if (param_3 != 0) {
    iVar2 = FUN_4541cb40((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x84))
              (*(int **)((int)this + 4),(int)((float)iVar2 * param_2));
    iVar2 = FUN_4541cd14((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x7c))
              (*(int **)((int)this + 4),(int)((float)iVar2 * fVar3) * iVar2);
    iVar2 = FUN_4541cd30((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x30))
              (*(int **)((int)this + 4),(int)((float)iVar2 * fVar3) * iVar2);
    iVar2 = FUN_4541cd4c((int)this);
    (**(code **)(**(int **)((int)this + 4) + 0x38))
              (*(int **)((int)this + 4),(int)((float)iVar2 * param_2));
  }
  return;
}


