// Source: CLCiffConversion_Data.dll @ 4501056d; FUN_4501056d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_4501056d(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  longlong lVar1;
  UINT UVar2;
  undefined4 ***_Memory;
  wchar_t *_Dst;
  undefined4 ***pppuVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint _SizeInWords;
  undefined4 ***pppuVar7;
  BSTR local_5c;
  undefined4 *local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined2 local_48 [2];
  undefined2 local_44 [8];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 **local_2c [5];
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x45010579;
  local_50 = 0;
  local_54 = param_2;
  local_58 = param_3;
  (**(code **)(*(int *)*param_1 + 0x9c))((int *)*param_1,&local_50);
  if (local_50 != 1) goto LAB_450106d1;
  (**(code **)(*(int *)*param_1 + 0xa4))((int *)*param_1,local_48);
  UVar2 = SysStringLen((BSTR)*param_3);
  local_34 = 0;
  iVar6 = param_2 - UVar2;
  local_30 = 7;
  local_44[0] = 0;
  local_8 = 0;
  basic_string<>(local_2c,(wchar_t *)*param_3);
  local_8 = CONCAT31(local_8._1_3_,1);
  lVar1 = (ulonglong)(iVar6 + 1) * 2;
  _Memory = (undefined4 ***)
            FUN_45020ebb(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  iVar5 = 0;
  if (0 < iVar6) {
    do {
      *(undefined2 *)((int)_Memory + iVar5 * 2) = local_48[0];
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar6);
  }
  *(undefined2 *)((int)_Memory + iVar5 * 2) = 0;
  (**(code **)(*(int *)*param_1 + 0xac))((int *)*param_1,&local_4c);
  _SizeInWords = local_54 + 1;
  _Dst = (wchar_t *)
         FUN_45020ebb(-(uint)((int)((ulonglong)_SizeInWords * 2 >> 0x20) != 0) |
                      (uint)((ulonglong)_SizeInWords * 2));
  if (local_4c == 0) {
    pppuVar3 = local_2c;
    pppuVar7 = _Memory;
    if (7 < local_18) {
      pppuVar3 = (undefined4 ***)local_2c[0];
    }
LAB_45010667:
    _swprintf_s(_Dst,_SizeInWords,L"%s%s",pppuVar3,pppuVar7);
  }
  else {
    if (local_4c == 1) {
      pppuVar3 = _Memory;
      pppuVar7 = local_2c;
      if (7 < local_18) {
        pppuVar7 = (undefined4 ***)local_2c[0];
      }
      goto LAB_45010667;
    }
    pppuVar3 = local_2c;
    if (7 < local_18) {
      pppuVar3 = (undefined4 ***)local_2c[0];
    }
    _swprintf_s(_Dst,_SizeInWords,L"%s",pppuVar3);
  }
  piVar4 = FUN_45001f5d(&local_5c,_Dst);
  FUN_450058c3(local_58,piVar4);
  SysFreeString(local_5c);
  FID_conflict__free(_Dst);
  FID_conflict__free(_Memory);
  FUN_450046d9(local_2c,'\x01',0);
  FUN_450046d9(local_44,'\x01',0);
LAB_450106d1:
  FUN_45022eb8();
  return;
}


