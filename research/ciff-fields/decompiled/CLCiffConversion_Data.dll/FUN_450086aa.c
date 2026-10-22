// Source: CLCiffConversion_Data.dll @ 450086aa; FUN_450086aa

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_450086aa(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *_Memory;
  bool bVar4;
  undefined4 **ppuVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char local_18;
  
  puVar3 = param_3;
  local_18 = '\x01';
  puVar6 = (undefined4 *)(*(undefined4 **)this)[1];
  cVar1 = *(char *)((int)puVar6 + 0xd);
  puVar2 = *(undefined4 **)this;
  while (cVar1 == '\0') {
    if ((char)param_2 == '\0') {
      local_18 = FUN_45008b14(puVar3,puVar6 + 4);
    }
    else {
      bVar4 = FUN_45008b14(puVar6 + 4,puVar3);
      local_18 = '\x01' - bVar4;
    }
    if (local_18 == '\0') {
      puVar7 = (undefined4 *)puVar6[2];
    }
    else {
      puVar7 = (undefined4 *)*puVar6;
    }
    puVar2 = puVar6;
    puVar6 = puVar7;
    cVar1 = *(char *)((int)puVar7 + 0xd);
  }
  param_2 = puVar2;
  if (local_18 != '\0') {
    if (puVar2 == (undefined4 *)**(int **)this) {
      ppuVar5 = &param_2;
      local_18 = '\x01';
      goto LAB_45008721;
    }
    FUN_45005981((int *)&param_2);
  }
  puVar6 = param_2;
  bVar4 = FUN_45008b14(param_2 + 4,puVar3);
  _Memory = param_4;
  if (!bVar4) {
    FUN_450088df(param_4 + 4);
    FID_conflict__free(_Memory);
    *param_1 = puVar6;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  ppuVar5 = &param_3;
LAB_45008721:
  puVar6 = (undefined4 *)FUN_4500841c(this,ppuVar5,local_18,puVar2,puVar3,param_4);
  *param_1 = *puVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


