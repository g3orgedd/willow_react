// Source: CLCiffConversion_Layout.dll @ 4541729f; FUN_4541729f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4541729f(void *this,BSTR param_1)

{
  int *piVar1;
  BSTR this_00;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int local_24;
  int local_20;
  BSTR local_1c;
  int local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  this_00 = param_1;
  uStack_4 = 0x14;
  local_8 = 0x454172ab;
  uVar4 = 0;
  (**(code **)(**(int **)(param_1 + 2) + 100))(*(int **)(param_1 + 2),local_14);
  puVar3 = FUN_4541cbbe(this_00,&local_1c);
  local_8 = 0;
  FUN_45407800((void *)((int)this + *(int *)(*(int *)((int)this + -4) + 4) + 0x60),
               (wchar_t *)*puVar3);
  local_8 = 0xffffffff;
  SysFreeString(local_1c);
  cVar2 = FUN_4540678d((int)this + *(int *)(*(int *)((int)this + -4) + 4) + -4);
  if (cVar2 != '\0') {
    local_1c = (BSTR)0x0;
    piVar1 = *(int **)(*(int *)(*(int *)((int)this + -4) + 4) + 0x34 + (int)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x29c))(piVar1,&local_1c);
    }
    if ((local_14[0] == (int *)0x0) && (local_1c == (BSTR)0x0)) {
      FUN_45412a39(&local_18);
      local_8 = 1;
      (**(code **)**(undefined4 **)(this_00 + 2))
                (*(undefined4 **)(this_00 + 2),&DAT_454486ec,local_14);
      FUN_45419a75((void *)((int)this + -8),&local_18);
      local_8 = 0xffffffff;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    return 0;
  }
  if (local_14[0] == (int *)0x0) {
    FUN_45412a39(&local_20);
    local_8 = 2;
    (**(code **)**(undefined4 **)(this_00 + 2))
              (*(undefined4 **)(this_00 + 2),&DAT_454486ec,&local_1c);
    uVar4 = FUN_4541991d((void *)((int)this + -8),&local_20);
  }
  else {
    if (local_14[0] != (int *)0x1) goto LAB_4541740d;
    param_1 = (BSTR)0x0;
    local_8 = 3;
    (**(code **)**(undefined4 **)(this_00 + 2))
              (*(undefined4 **)(this_00 + 2),&DAT_45449f90,&param_1);
    local_24 = 0;
    (**(code **)(*(int *)param_1 + 0xc0))(param_1,&local_24);
    if (local_24 != 0) {
      uVar4 = FUN_45419163();
    }
    FUN_4541907d((void *)((int)this + -8),&param_1);
    local_1c = param_1;
  }
  local_8 = 0xffffffff;
  if (local_1c != (BSTR)0x0) {
    (**(code **)(*(int *)local_1c + 8))(local_1c);
  }
LAB_4541740d:
  FUN_45402cd0((void *)((int)this + *(int *)(*(int *)((int)this + -4) + 4) + 0x60),"");
  return uVar4;
}


