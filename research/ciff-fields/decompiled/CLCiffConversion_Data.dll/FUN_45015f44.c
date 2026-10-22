// Source: CLCiffConversion_Data.dll @ 45015f44; FUN_45015f44

void FUN_45015f44(int param_1)

{
  int *piVar1;
  
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
  return;
}


