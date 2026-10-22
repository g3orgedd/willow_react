// Source: CLCiffConversion_Data.dll @ 45020b7c; FUN_45020b7c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_45020b7c(void *this,BSTR param_1,LPCWSTR param_2,BSTR param_3,uint *param_4)

{
  uint *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  LSTATUS LVar3;
  OLECHAR *strIn;
  BSTR extraout_ECX;
  undefined4 uVar4;
  BSTR pOVar5;
  BSTR pOVar6;
  undefined4 *puVar7;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  BSTR local_14 [3];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  uVar4 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  puVar7 = &local_24;
  local_8 = 3;
  uStack_7 = 0;
  local_14[0] = (BSTR)&stack0xffffffc4;
  pOVar6 = this;
  FUN_45001ef3(&stack0xffffffc4,(int *)&param_3);
  local_8 = 4;
  pOVar5 = extraout_ECX;
  FUN_45001ef3(&stack0xffffffc0,(int *)&param_1);
  _local_8 = CONCAT31(uStack_7,3);
  bVar2 = FUN_45020d0c(this,pOVar5,pOVar6,puVar7);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    local_14[0] = (BSTR)0x0;
    LVar3 = FUN_45020d86(&local_24,param_2,(LPBYTE)0x0,(uint *)local_14);
    if (LVar3 == 0) {
      local_14[0] = (BSTR)((int)local_14[0] + 1);
      strIn = (OLECHAR *)
              FUN_45020ebb(-(uint)((int)(ZEXT48(local_14[0]) * 2 >> 0x20) != 0) |
                           (uint)(ZEXT48(local_14[0]) * 2));
      if (strIn != (OLECHAR *)0x0) {
        LVar3 = FUN_45020d86(&local_24,param_2,(LPBYTE)strIn,(uint *)local_14);
        if (LVar3 == 0) {
          SysFreeString((BSTR)*param_4);
          *param_4 = 0;
          local_14[0] = SysAllocStringLen(strIn,(int)local_14[0] - 1);
          puVar1 = param_4;
          if ((BSTR)*param_4 != local_14[0]) {
            SysFreeString((BSTR)*param_4);
            *puVar1 = (uint)local_14[0];
          }
          uVar4 = 1;
        }
        FID_conflict__free(strIn);
      }
    }
    ATL::CRegKey::Close((CRegKey *)&local_24);
  }
  ATL::CRegKey::Close((CRegKey *)&local_24);
  SysFreeString(param_1);
  SysFreeString(param_2);
  SysFreeString(param_3);
  return uVar4;
}


