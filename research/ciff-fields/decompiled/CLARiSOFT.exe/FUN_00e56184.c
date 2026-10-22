// Source: CLARiSOFT.exe @ 00e56184; FUN_00e56184

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_00e56184(void *this,int *param_1,int *param_2,int *param_3,char param_4)

{
  bool bVar1;
  void *this_00;
  undefined4 *puVar2;
  
  *(int **)this = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  *(int **)((int)this + 4) = param_3;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  FUN_00e03ab8((void *)((int)this + 0x10),param_1);
  *(undefined1 *)((int)this + 0x14) = 0;
  if (*(int *)this != 0) {
    this_00 = (void *)FUN_00eca369(0x1af8);
    if (this_00 == (void *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_00e543a4(this_00,this,param_4);
    }
    *(undefined4 **)((int)this + 8) = puVar2;
    if (param_4 == '\0') {
      bVar1 = FUN_00e562da((int)this);
      *(bool *)((int)this + 0x14) = bVar1;
    }
    else {
      FUN_00e5630b(this);
    }
  }
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  return this;
}


