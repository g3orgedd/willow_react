// Source: CiffMgr.dll @ 68101ef7; FUN_68101ef7

void __thiscall FUN_68101ef7(void *this,undefined4 param_1,undefined4 param_2)

{
  error_condition *this_00;
  error_condition *peVar1;
  void *local_c;
  void *pvStack_8;
  
  peVar1 = (error_condition *)&local_c;
  local_c = this;
  pvStack_8 = this;
  this_00 = (error_condition *)(**(code **)(*(int *)this + 0xc))(peVar1,param_1,param_2);
  std::error_condition::operator==(this_00,peVar1);
  return;
}


