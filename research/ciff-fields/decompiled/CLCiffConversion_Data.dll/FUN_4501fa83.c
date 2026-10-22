// Source: CLCiffConversion_Data.dll @ 4501fa83; FUN_4501fa83

undefined4 __fastcall FUN_4501fa83(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0x4a;
  do {
    iVar3 = (iVar2 + iVar4) / 2;
    iVar1 = _wcscmp(&DAT_45040c80 + iVar3 * 0xc,(wchar_t *)(param_1 + 0xd0));
    if (iVar1 == 0) {
      return *(undefined4 *)(&UNK_45040c94 + iVar3 * 0x18);
    }
    if (iVar1 < 1) {
      iVar4 = iVar3 + 1;
    }
    else {
      iVar2 = iVar3 + -1;
    }
  } while (iVar4 <= iVar2);
  return 0;
}


