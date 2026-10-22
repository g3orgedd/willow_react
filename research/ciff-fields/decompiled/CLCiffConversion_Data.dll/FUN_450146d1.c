// Source: CLCiffConversion_Data.dll @ 450146d1; FUN_450146d1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_450146d1(void *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  FUN_4501467d((undefined4 *)((int)param_1 + 0xc));
  *(undefined4 *)((int)param_1 + 0x2c) = 0;
  *(undefined4 *)((int)param_1 + 0x30) = 0;
  FUN_450212c4((int)param_1 + 0x38,0x30,0x19,&LAB_450147c4);
  *(undefined4 *)((int)param_1 + 0x4e8) = 0;
  *(undefined4 *)((int)param_1 + 0x4ec) = 0;
  uVar2 = FUN_45013f7b((int *)0x0,(int *)0x0);
  *(undefined4 *)((int)param_1 + 0x4e8) = uVar2;
  *(undefined **)((int)param_1 + 0x4f0) = PTR_DAT_4505101c;
  *(undefined4 *)((int)param_1 + 0x4f4) = 0;
  FUN_45005aac(0x4503fe54);
  piVar1 = *(int **)((int)param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45015f23(L"CLCiffConversion_Data");
  FUN_45018d66(param_1,'\x01');
  return param_1;
}


