// Source: CLCiffConversion_Layout.dll @ 4540dad6; FUN_4540dad6

undefined4 * __thiscall FUN_4540dad6(void *this,undefined4 *param_1)

{
  double *pdVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  double dVar6;
  
  *param_1 = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x30));
  if (*(int *)((int)this + 0x2c) == 10) {
    iVar5 = 0;
    iVar3 = 0;
    dVar6 = DAT_45448418;
    piVar4 = this;
    do {
      piVar4 = piVar4 + 1;
      pdVar1 = (double *)(*piVar4 + 0x68);
      if (*pdVar1 <= dVar6 && dVar6 != *pdVar1) {
        dVar6 = *(double *)(*piVar4 + 0x68);
        iVar5 = iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 10);
    puVar2 = *(undefined4 **)((int)this + iVar5 * 4 + 4);
    *param_1 = puVar2[0x1c];
    FUN_4540e16f(puVar2);
    puVar2[0x1c] = puVar2[0x1c] + 10;
  }
  else {
    puVar2 = (undefined4 *)FUN_454298b4(0xc0);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_4540d8ca(puVar2);
    }
    if (puVar2 == (undefined4 *)0x0) goto LAB_4540db6d;
    *(undefined4 **)((int)this + *(int *)((int)this + 0x2c) * 4 + 4) = puVar2;
    puVar2[0x1c] = *(undefined4 *)((int)this + 0x2c);
    *(int *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + 1;
  }
  FUN_4540e218((int)puVar2);
LAB_4540db6d:
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x30));
  return puVar2;
}


