// Source: CLCiffConversion_Data.dll @ 450024bc; FUN_450024bc

undefined4 __thiscall
FUN_450024bc(void *this,undefined4 *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_4 + param_2;
  if (iVar2 == 0) {
    *param_1 = PTR_DAT_4505101c;
  }
  else {
    if (iVar2 < param_2) {
      return 0;
    }
    iVar1 = FUN_4500244d(param_1,iVar2);
    if (iVar1 == 0) {
      return 0;
    }
    FUN_45004ebd((void *)*param_1,iVar2 * 2 + 2,(void *)(*(int *)this + param_3 * 2),param_2 * 2);
  }
  return 1;
}


