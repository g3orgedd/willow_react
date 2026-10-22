// Source: CLCiffConversion_Data.dll @ 4500e3e3; FUN_4500e3e3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4500e3e3(void *this,undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  UINT UVar3;
  int *local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  piVar1 = *(int **)this;
  if (piVar1 != (int *)0x0) {
    local_14[0] = 0;
    local_8 = 0;
    iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1,local_14);
    if (-1 < iVar2) {
      if (local_14[0] == 1) {
        (**(code **)(**(int **)this + 0xe8))(*(int **)this,0);
        (**(code **)(**(int **)this + 0xf0))(*(int **)this,0);
        (**(code **)(**(int **)this + 0xf8))(*(int **)this,0);
      }
      else if (local_14[0] == 2) {
        (**(code **)(**(int **)this + 0x74))(*(int **)this,0);
        (**(code **)(**(int **)this + 0x6c))(*(int **)this,0);
      }
      else if (local_14[0] == 3) {
        (**(code **)(**(int **)this + 0xc0))(*(int **)this,0);
        (**(code **)(**(int **)this + 200))(*(int **)this,0);
        (**(code **)(**(int **)this + 0xd0))(*(int **)this,0);
        (**(code **)(**(int **)this + 0xd8))(*(int **)this,0);
        (**(code **)(**(int **)this + 0xe0))(*(int **)this,0);
      }
      else if (local_14[0] == 4) {
        (**(code **)(**(int **)this + 0xb8))(*(int **)this,0);
      }
      else if (local_14[0] == 5) {
        (**(code **)(**(int **)this + 0x100))(*(int **)this,0);
        (**(code **)(**(int **)this + 0x108))(*(int **)this,1);
        (**(code **)(**(int **)this + 0x110))(*(int **)this,0);
      }
      else if (local_14[0] == 7) {
        CComQIPtr<>(&local_18,*(undefined4 **)this);
        local_8._0_1_ = 1;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 0x144))(local_18,0);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
    }
    (**(code **)(**(int **)this + 0x2c))(*(int **)this,0);
    (**(code **)(**(int **)this + 0x3c))(*(int **)this,1);
    (**(code **)(**(int **)this + 0x44))(*(int **)this,0);
    (**(code **)(**(int **)this + 0x84))(*(int **)this,L"en-GB");
    (**(code **)(**(int **)this + 0x54))(*(int **)this,0);
    (**(code **)(**(int **)this + 0x5c))(*(int **)this,*param_1);
    (**(code **)(**(int **)this + 100))(*(int **)this,*param_1);
    piVar1 = *(int **)this;
    UVar3 = SysStringLen((BSTR)*param_1);
    (**(code **)(*piVar1 + 0x98))(piVar1,UVar3);
    (**(code **)(**(int **)this + 0xa0))(*(int **)this,0);
    SysFreeString((BSTR)0x0);
  }
  return;
}


