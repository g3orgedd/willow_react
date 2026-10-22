// Source: CLCiffConversion_Data.dll @ 450386ae; FUN_450386ae

undefined4 __cdecl FUN_450386ae(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint *_Str;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  size_t sVar6;
  char *_Dst;
  errno_t eVar7;
  BOOL BVar8;
  undefined1 *puVar9;
  bool bVar10;
  uint *_Src;
  undefined4 local_c;
  
  local_c = 0;
  if (param_1 == (undefined4 *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_45027e29();
    return 0xffffffff;
  }
  _Str = (uint *)*param_1;
  if (((_Str == (uint *)0x0) || (puVar3 = (uint *)FUN_45038f52(_Str,0x3d), puVar3 == (uint *)0x0))
     || (_Str == puVar3)) {
LAB_45038739:
    piVar2 = __errno();
    *piVar2 = 0x16;
    return 0xffffffff;
  }
  bVar10 = *(char *)((int)puVar3 + 1) == '\0';
  if (DAT_450553b4 == DAT_450553d4) {
    DAT_450553b4 = FUN_450388f6(DAT_450553b4);
  }
  if (DAT_450553b4 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_450553b8 == (undefined4 *)0x0)) {
      if (bVar10) {
        return 0;
      }
      DAT_450553b4 = FUN_4502df29(4);
      if (DAT_450553b4 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_450553b4 = 0;
      if (DAT_450553b8 == (undefined4 *)0x0) {
        DAT_450553b8 = FUN_4502df29(4);
        if (DAT_450553b8 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_450553b8 = 0;
      }
    }
    else {
      iVar4 = FUN_450378ca();
      if (iVar4 != 0) goto LAB_45038739;
    }
    if (DAT_450553b4 == (int *)0x0) {
      return 0xffffffff;
    }
  }
  piVar2 = DAT_450553b4;
  uVar5 = findenv((uchar *)_Str,(int)puVar3 - (int)_Str);
  if (((int)uVar5 < 0) || (*piVar2 == 0)) {
    if (bVar10) {
      FID_conflict__free(_Str);
      *param_1 = 0;
      return 0;
    }
    if ((int)uVar5 < 0) {
      uVar5 = -uVar5;
    }
    uVar1 = uVar5 + 2;
    if ((int)uVar1 < (int)uVar5) {
      return 0xffffffff;
    }
    if (0x3ffffffe < uVar1) {
      return 0xffffffff;
    }
    piVar2 = FUN_4502dfba(DAT_450553b4,4,uVar1);
    if (piVar2 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar2[uVar5 + 1] = 0;
    piVar2[uVar5] = (int)_Str;
    *param_1 = 0;
  }
  else {
    FID_conflict__free((void *)piVar2[uVar5]);
    if (!bVar10) {
      piVar2[uVar5] = (int)_Str;
      *param_1 = 0;
      goto LAB_4503884d;
    }
    for (; piVar2[uVar5] != 0; uVar5 = uVar5 + 1) {
      piVar2[uVar5] = piVar2[uVar5 + 1];
    }
    if ((0x3ffffffe < uVar5) || (piVar2 = FUN_4502dfba(DAT_450553b4,uVar5,4), piVar2 == (int *)0x0))
    goto LAB_4503884d;
  }
  DAT_450553b4 = piVar2;
LAB_4503884d:
  if (param_2 != 0) {
    uVar5 = 1;
    sVar6 = _strlen((char *)_Str);
    _Dst = FUN_4502dee1(sVar6 + 2,uVar5);
    if (_Dst != (char *)0x0) {
      _Src = _Str;
      sVar6 = _strlen((char *)_Str);
      eVar7 = _strcpy_s(_Dst,sVar6 + 2,(char *)_Src);
      if (eVar7 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      puVar9 = (undefined1 *)(((int)_Dst - (int)_Str) + (int)puVar3);
      *puVar9 = 0;
      BVar8 = SetEnvironmentVariableA(_Dst,(LPCSTR)(~-(uint)bVar10 & (uint)(puVar9 + 1)));
      if (BVar8 == 0) {
        local_c = 0xffffffff;
        piVar2 = __errno();
        *piVar2 = 0x2a;
      }
      FID_conflict__free(_Dst);
    }
  }
  if (bVar10) {
    FID_conflict__free(_Str);
    *param_1 = 0;
    return local_c;
  }
  return local_c;
}


