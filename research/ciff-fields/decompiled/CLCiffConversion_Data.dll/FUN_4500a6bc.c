// Source: CLCiffConversion_Data.dll @ 4500a6bc; FUN_4500a6bc

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_4500a6bc(void *this,undefined4 *param_1,undefined4 *param_2,wchar_t *param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 *puVar2;
  wchar_t *this_00;
  int iVar3;
  wchar_t **ppwVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  bool local_18;
  
  this_00 = param_3;
  local_18 = true;
  puVar5 = (undefined4 *)(*(undefined4 **)this)[1];
  cVar1 = *(char *)((int)puVar5 + 0xd);
  puVar2 = *(undefined4 **)this;
  while (cVar1 == '\0') {
    if ((char)param_2 == '\0') {
      iVar3 = FUN_45007b0d(this_00,(wchar_t *)(puVar5 + 4));
      local_18 = iVar3 < 0;
    }
    else {
      iVar3 = FUN_45007b0d(puVar5 + 4,this_00);
      local_18 = -1 < iVar3;
    }
    if (local_18 == false) {
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
  if (local_18 != false) {
    if (puVar2 == (undefined4 *)**(int **)this) {
      ppwVar4 = (wchar_t **)&param_2;
      local_18 = true;
      goto LAB_4500a73a;
    }
    FUN_45005981((int *)&param_2);
  }
  puVar5 = param_2;
  iVar3 = FUN_45007b0d(param_2 + 4,this_00);
  if (-1 < iVar3) {
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  ppwVar4 = &param_3;
LAB_4500a73a:
  puVar5 = (undefined4 *)FUN_4500a59a(this,ppwVar4,local_18,puVar2,(undefined8 *)this_00);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


