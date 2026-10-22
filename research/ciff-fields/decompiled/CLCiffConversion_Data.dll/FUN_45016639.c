// Source: CLCiffConversion_Data.dll @ 45016639; FUN_45016639

int __thiscall FUN_45016639(void *this,LPCRITICAL_SECTION param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  *param_3 = 0;
  puVar3 = *(undefined4 **)((int)this + 0x2c);
  if (puVar3 != (undefined4 *)0x0) {
    for (; (int *)*puVar3 != (int *)0x0; puVar3 = puVar3 + 9) {
      if ((puVar3[2] != 0) && (iVar2 = FUN_45018a9f((int *)param_1,(int *)*puVar3), iVar2 != 0)) {
        piVar1 = puVar3 + 4;
        if (*piVar1 == 0) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_450538b8);
          iVar4 = 0;
          if (*piVar1 == 0) {
            iVar4 = (*(code *)puVar3[2])(puVar3[3],&DAT_4503d450,piVar1);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_450538b8);
        }
        puVar3 = (undefined4 *)*piVar1;
        if (puVar3 != (undefined4 *)0x0) {
          iVar4 = (**(code **)*puVar3)(puVar3,param_2,param_3);
        }
        if (*param_3 != 0) {
          return iVar4;
        }
        if (iVar4 != 0) {
          return iVar4;
        }
        break;
      }
    }
  }
  iVar4 = FUN_450153e2((int *)&DAT_450538a8,param_1,param_2,param_3);
  return iVar4;
}


