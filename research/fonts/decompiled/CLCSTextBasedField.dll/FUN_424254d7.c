// Source: CLCSTextBasedField.dll @ 424254d7; FUN_424254d7

undefined4
FUN_424254d7(undefined4 param_1,short param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5,int param_6,uint *param_7)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 local_c;
  int *local_8;
  
  puVar1 = param_7;
  *param_7 = 1;
  if (param_2 == 0) {
    return 0;
  }
  param_7 = (uint *)0x0;
  (**(code **)*param_4)(param_4,&DAT_424956f8,&param_7);
  local_8 = (int *)0x0;
  FUN_42420daa(&local_8,(int *)&param_7);
  local_c = CONCAT31(local_c._1_3_,1);
  if (param_6 == 1) {
    cVar2 = FUN_424277d0((int)&local_c);
LAB_42425549:
    if (cVar2 != '\0') {
LAB_4242554d:
      *puVar1 = 1;
      goto LAB_42425569;
    }
    uVar3 = FUN_42425a98((int)&local_c);
    bVar4 = (char)uVar3 == '\x01';
  }
  else {
    if (param_6 == 3) {
      uVar3 = FUN_42421ea8((int)&local_c);
      cVar2 = (char)uVar3;
      goto LAB_42425549;
    }
    if (param_6 != 4) goto LAB_4242554d;
    cVar2 = FUN_42426439((int)&local_c);
    bVar4 = cVar2 != '\0';
  }
  *puVar1 = (uint)bVar4;
LAB_42425569:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  if (param_7 != (uint *)0x0) {
    (**(code **)(*param_7 + 8))(param_7);
  }
  return 0;
}


