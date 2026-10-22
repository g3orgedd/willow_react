// Source: CLCiffConversion_Data.dll @ 450052fd; FUN_450052fd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_450052fd(void *this,undefined4 *param_1,undefined4 *param_2,wchar_t *param_3,int *param_4)

{
  char cVar1;
  undefined4 *puVar2;
  wchar_t *this_00;
  int *_Memory;
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
      goto LAB_4500537b;
    }
    FUN_45005981((int *)&param_2);
  }
  puVar5 = param_2;
  iVar3 = FUN_45007b0d(param_2 + 4,this_00);
  _Memory = param_4;
  if (-1 < iVar3) {
    FUN_450056f0(param_4 + 4);
    FID_conflict__free(_Memory);
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  ppwVar4 = &param_3;
LAB_4500537b:
  puVar5 = (undefined4 *)FUN_45005070(this,ppwVar4,local_18,puVar2,this_00,param_4);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


