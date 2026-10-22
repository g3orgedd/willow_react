// Source: CiffMgr.dll @ 68103fac; FUN_68103fac

void FUN_68103fac(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(stringdispid **)(param_1 + 0x14) != (stringdispid *)0x0) {
      ATL::CComTypeInfoHolder::stringdispid::_vector_deleting_destructor_
                (*(stringdispid **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}


