// Source: CiffHelper.dll @ 4081a593; FUN_4081a593

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __thiscall FUN_4081a593(void *this,LPCWSTR param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  int local_1c;
  wchar_t *local_18;
  undefined1 local_11;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0;
  uVar4 = 0;
  local_11 = 0;
  if (*(int *)((int)this + 0x6c) != 0) {
    if (*(int *)(*(int *)((int)this + 0x6c) + 4) != 0) {
      FUN_40803c8a(&local_18,"");
      local_8._0_1_ = 1;
      piVar3 = *(int **)**(int **)((int)this + 0x6c);
      if (piVar3 != (int *)**(int **)((int)this + 0x6c)) {
        do {
          FUN_4080316d(&local_18,piVar3 + 2);
          puVar1 = FUN_408030e3(&local_1c,param_1);
          iVar2 = _wcscmp(local_18,(wchar_t *)*puVar1);
          FUN_40803143(&local_1c);
          if (iVar2 == 0) {
            uVar4 = 1;
            break;
          }
          piVar3 = (int *)*piVar3;
          uVar4 = local_11;
        } while (piVar3 != (int *)**(int **)((int)this + 0x6c));
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_40803143((int *)&local_18);
    }
    piVar3 = FUN_408030e3(&local_1c,param_1);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_4081a115(*(undefined4 **)((int)this + 0x6c),(int *)**(undefined4 **)((int)this + 0x6c),
                 piVar3);
    FUN_40803143(&local_1c);
  }
  SysFreeString(param_1);
  return uVar4;
}


