// Source: CiffMgr.dll @ 68104530; FUN_68104530

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_68104530(void *this,undefined *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  UINT UVar6;
  int *piVar7;
  int *piVar8;
  code *pcVar9;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_1;
  uStack_4 = 0x14;
  local_8 = 0x6810453c;
  pcVar9 = (code *)param_1;
  iVar4 = (**(code **)(*(int *)param_1 + 0xc))(param_1,&local_1c);
  if (-1 < iVar4) {
    piVar7 = (int *)0x0;
    local_18 = (int *)0x0;
    param_1 = (undefined *)(uint)*(ushort *)(local_1c + 0x2c);
    *(undefined4 *)((int)this + 0x14) = 0;
    *(undefined **)((int)this + 0x18) = param_1;
    if (param_1 != (undefined *)0x0) {
      puVar5 = (undefined4 *)
               FUN_68132ccc(-(uint)(0xfffffffb < (uint)((int)param_1 * 0xc)) |
                            (int)param_1 * 0xc + 4U);
      local_8 = 0;
      if (puVar5 == (undefined4 *)0x0) {
        piVar7 = (int *)0x0;
        local_18 = (int *)0x0;
      }
      else {
        piVar7 = puVar5 + 1;
        pcVar9 = FUN_681081ac;
        *puVar5 = param_1;
        local_18 = piVar7;
        FUN_68132c04(piVar7,0xc,(int)param_1,&LAB_68103cdc);
      }
      local_8 = 0xffffffff;
      if (piVar7 == (int *)0x0) {
        (**(code **)(*(int *)puVar1 + 0x4c))(puVar1,local_1c);
        return 0x8007000e;
      }
    }
    local_20 = 0;
    piVar8 = piVar7;
    piVar3 = piVar7;
    if (0 < *(int *)((int)this + 0x18)) {
      do {
        param_1 = (undefined *)piVar3;
        iVar4 = (**(code **)(*(int *)puVar1 + 0x14))(puVar1,local_20,local_14,pcVar9);
        if (-1 < iVar4) {
          param_1 = (undefined *)0x0;
          local_8 = 1;
          iVar4 = (**(code **)(*(int *)puVar1 + 0x30))(puVar1,*local_14[0],&param_1,0,0,0);
          puVar2 = param_1;
          if (-1 < iVar4) {
            param_1 = (undefined *)0x0;
            if ((undefined *)*piVar7 != puVar2) {
              SysFreeString((BSTR)*piVar7);
              *piVar7 = (int)puVar2;
            }
            UVar6 = SysStringLen((BSTR)*piVar7);
            piVar7[1] = UVar6;
            piVar7[2] = *local_14[0];
          }
          (**(code **)(*(int *)puVar1 + 0x50))(puVar1,local_14[0]);
          local_8 = 0xffffffff;
          SysFreeString((BSTR)param_1);
        }
        piVar7 = piVar7 + 3;
        local_20 = local_20 + 1;
        piVar8 = local_18;
        piVar3 = (int *)param_1;
      } while (local_20 < *(int *)((int)this + 0x18));
    }
    *(int **)((int)this + 0x14) = piVar8;
    (**(code **)(*(int *)puVar1 + 0x4c))(puVar1,local_1c);
  }
  return 0;
}


