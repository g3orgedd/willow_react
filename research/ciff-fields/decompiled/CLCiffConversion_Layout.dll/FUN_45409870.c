// Source: CLCiffConversion_Layout.dll @ 45409870; FUN_45409870

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_45409870(void *this,undefined4 *param_1,undefined4 *param_2,XQATItem *param_3,undefined4 param_4
            )

{
  char cVar1;
  undefined4 *puVar2;
  XQATItem *this_00;
  uint uVar3;
  XQATItem **ppXVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char local_18;
  
  this_00 = param_3;
  local_18 = '\x01';
  puVar5 = (undefined4 *)(*(undefined4 **)this)[1];
  cVar1 = *(char *)((int)puVar5 + 0xd);
  puVar2 = *(undefined4 **)this;
  while (cVar1 == '\0') {
    if ((char)param_2 == '\0') {
      uVar3 = FUN_45409a5f(this_00,puVar5 + 4);
      local_18 = (char)uVar3;
    }
    else {
      uVar3 = FUN_45409a5f(puVar5 + 4,(undefined4 *)this_00);
      local_18 = '\x01' - ((char)uVar3 != '\0');
    }
    if (local_18 == '\0') {
      puVar6 = (undefined4 *)puVar5[2];
    }
    else {
      puVar6 = (undefined4 *)*puVar5;
    }
    puVar2 = puVar5;
    puVar5 = puVar6;
    cVar1 = *(char *)((int)puVar6 + 0xd);
  }
  param_2 = puVar2;
  if (local_18 != '\0') {
    if (puVar2 == (undefined4 *)**(int **)this) {
      ppXVar4 = (XQATItem **)&param_2;
      local_18 = '\x01';
      goto LAB_454098ea;
    }
    FUN_454078a8((int *)&param_2);
  }
  puVar5 = param_2;
  uVar3 = FUN_45409a5f(param_2 + 4,(undefined4 *)this_00);
  if ((char)uVar3 == '\0') {
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  ppXVar4 = &param_3;
LAB_454098ea:
  puVar5 = (undefined4 *)FUN_4540974e(this,ppXVar4,local_18,puVar2,this_00);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


