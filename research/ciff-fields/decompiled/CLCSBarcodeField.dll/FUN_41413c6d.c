// Source: CLCSBarcodeField.dll @ 41413c6d; FUN_41413c6d

void FUN_41413c6d(int param_1,int *param_2,int param_3)

{
  DWORD DVar1;
  
  if (param_1 != 0) goto LAB_41413c8b;
  do {
    RaiseException(0xc0000005,1,0,(ULONG_PTR *)0x0);
LAB_41413c8b:
  } while ((param_2 == (int *)0x0) || (param_3 == 0));
  *param_2 = param_3;
  DVar1 = GetCurrentThreadId();
  param_2[1] = DVar1;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  param_2[2] = *(int *)(param_1 + 0x1c);
  *(int **)(param_1 + 0x1c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}


