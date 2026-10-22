// Source: CLCSRichTextBlockField.dll @ 418175bc; FUN_418175bc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_418175bc(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 *param_4,int *param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 extraout_EAX;
  int iVar4;
  VARIANTARG local_54;
  int local_44;
  BSTR local_40;
  int local_3c;
  BSTR local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int *local_1c;
  int local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x418175c8;
  FUN_41806fb8(&local_38,(GUID *)&DAT_4183caf0);
  puVar2 = param_3;
  local_8 = 0;
  (**(code **)(*(int *)*param_3 + 0x74))((int *)*param_3,local_38);
  local_2c = (int *)0x0;
  CComQIPtr<>(&local_34,(undefined4 *)*puVar2);
  local_8._0_1_ = 2;
  (**(code **)(*(int *)*puVar2 + 0x5c))((int *)*puVar2,&local_2c);
  (**(code **)(*(int *)*puVar2 + 0x6c))((int *)*puVar2,L"RichText");
  FUN_41824ee0((uint *)&local_54,0,0x10);
  VariantInit(&local_54);
  local_8._0_1_ = 3;
  (**(code **)(*local_2c + 0x28))(local_2c,0,0,1,0,&local_54);
  CComQIPtr<>(&local_1c,(undefined4 *)local_54.n1._8_4_);
  local_8._0_1_ = 4;
  (**(code **)(*local_1c + 0x54))(local_1c,0);
  puVar3 = FUN_418197e3(&local_3c,0x647e);
  local_8._0_1_ = 5;
  FUN_41801397(&local_40,(OLECHAR *)*puVar3);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_418015fa(&local_3c);
  (**(code **)(*local_1c + 0x5c))(local_1c,local_40);
  (**(code **)(*local_1c + 100))(local_1c,local_40);
  (**(code **)(*(int *)*puVar2 + 0x9c))((int *)*puVar2,local_40);
  (**(code **)(*(int *)*puVar2 + 0xac))((int *)*puVar2,*param_1);
  iVar4 = param_2;
  (**(code **)(*(int *)*puVar2 + 0xb4))((int *)*puVar2,param_2);
  local_20 = 1;
  piVar1 = (int *)*param_5;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3b4))(piVar1,&local_20);
  }
  (**(code **)(*(int *)*puVar2 + 0xb4))((int *)*puVar2,local_20 * iVar4);
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 0x16c))(local_34,local_20);
  }
  (**(code **)(*(int *)*puVar2 + 0x128))((int *)*puVar2,1);
  (**(code **)(*(int *)*puVar2 + 0x78))((int *)*puVar2,&local_24);
  (**(code **)(*(int *)*puVar2 + 0x80))((int *)*puVar2,local_14);
  if ((local_24 == 0) || (local_14[0] == 0)) {
    (**(code **)(*(int *)*param_4 + 0x54))((int *)*param_4,&param_2);
    param_3 = (undefined4 *)0x0;
    (**(code **)(*(int *)*param_5 + 0x2c))((int *)*param_5,&param_3);
    param_1 = (undefined4 *)0x0;
    (**(code **)(*(int *)*param_5 + 0x34))((int *)*param_5,&param_1);
    local_24 = 0;
    local_28 = 2000;
    FUN_418170d2(&local_28,param_2,(float)param_3);
    local_14[0] = 0;
    local_18 = 2000;
    FUN_418170d2(&local_18,param_2,(float)param_1);
    local_24 = local_28;
    local_14[0] = local_18;
  }
  (**(code **)(*(int *)*puVar2 + 0x7c))((int *)*puVar2,local_24);
  (**(code **)(*(int *)*puVar2 + 0x84))((int *)*puVar2,local_14[0]);
  (**(code **)(*(int *)*puVar2 + 0xf8))((int *)*puVar2,0);
  if (3 < iVar4) {
    iVar4 = 4;
  }
  (**(code **)(*(int *)*puVar2 + 0xf0))((int *)*puVar2,iVar4);
  (**(code **)(*(int *)*puVar2 + 0xd8))((int *)*puVar2,local_24);
  (**(code **)(*(int *)*puVar2 + 0xe0))((int *)*puVar2,local_14[0]);
  (**(code **)(*(int *)*puVar2 + 0xe8))((int *)*puVar2,*(undefined4 *)(local_44 + 0x8c));
  CComQIPtr<>(&local_30,(undefined4 *)*puVar2);
  local_8._0_1_ = 8;
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 0x130))(local_30,0);
  }
  local_8._0_1_ = 7;
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))(local_30);
  }
  SysFreeString(local_40);
  local_8._0_1_ = 3;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  VariantClear(&local_54);
  local_8._0_1_ = 1;
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_2c != (int *)0x0) {
    (**(code **)(*local_2c + 8))(local_2c);
  }
  SysFreeString(local_38);
  return CONCAT31((int3)((uint)extraout_EAX >> 8),1);
}


