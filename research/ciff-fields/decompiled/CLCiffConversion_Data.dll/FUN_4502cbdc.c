// Source: CLCiffConversion_Data.dll @ 4502cbdc; type_info::_Type_info_dtor

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    private: static void __cdecl type_info::_Type_info_dtor(class type_info *)
   
   Library: Visual Studio 2012 Release */

void __cdecl type_info::_Type_info_dtor(type_info *param_1)

{
  int *_Memory;
  int *piVar1;
  int *piVar2;
  
  __lock(0xe);
  _Memory = DAT_450553a0;
  if (*(int *)(param_1 + 4) != 0) {
    piVar1 = (int *)&DAT_4505539c;
    do {
      piVar2 = piVar1;
      if (DAT_450553a0 == (int *)0x0) goto LAB_4502cc21;
      piVar1 = DAT_450553a0;
    } while (*DAT_450553a0 != *(int *)(param_1 + 4));
    piVar2[1] = DAT_450553a0[1];
    FID_conflict__free(_Memory);
LAB_4502cc21:
    FID_conflict__free(*(void **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  FUN_4502cc44();
  return;
}


