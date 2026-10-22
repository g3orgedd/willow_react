// Source: CLCiffConversion_Data.dll @ 4502e2c8; __except1

/* Library Function - Single Match
    __except1
   
   Library: Visual Studio 2019 Release */

void __cdecl __except1(uint param_1,int param_2,undefined8 param_3,double param_4,uint param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint local_90 [16];
  uint local_50;
  uint local_14;
  
  local_14 = DAT_450518d0 ^ (uint)&stack0xfffffff0;
  bVar1 = __handle_exc(param_1,&param_4,param_5);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    local_50 = local_50 & 0xfffffffe;
    FUN_4502e5df(local_90,&param_5,param_1,param_2,(uint *)&param_3,(uint *)&param_4,0);
  }
  iVar2 = __errcode(param_1);
  if ((DAT_45052880 == 0) && (iVar2 != 0)) {
    __umatherr(iVar2,param_2);
  }
  else {
    __set_errno_from_matherr(iVar2);
    __ctrlfp();
  }
  FUN_45022e32(local_14 ^ (uint)&stack0xfffffff0);
  return;
}


