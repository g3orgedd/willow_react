// Source: CiffHelper.dll @ 408316cb; FUN_408316cb

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_408316cb(int param_1,undefined4 param_2)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  undefined8 local_c;
  
  uVar2 = __ctrlfp();
  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = __sptype(param_1,(uint)(CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) >>
                                   0x20));
    if (iVar3 == 1) {
      __ctrlfp();
      fVar4 = (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
    }
    else if (iVar3 == 2) {
      __ctrlfp();
      fVar4 = -(float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
    }
    else {
      dVar1 = (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
      if (iVar3 == 3) {
        fVar4 = __handle_qnan1(0x15,(double)CONCAT44((int)((ulonglong)dVar1 >> 0x20),param_1));
      }
      else {
        fVar4 = (float10)__except1(8,0x15,dVar1,_DAT_40851a50 + dVar1,uVar2);
      }
    }
  }
  else {
    local_c = ABS((double)CONCAT44(param_2,param_1));
    __ctrlfp();
    fVar4 = (float10)local_c;
  }
  return fVar4;
}


