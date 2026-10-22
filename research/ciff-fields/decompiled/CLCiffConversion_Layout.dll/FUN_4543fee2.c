// Source: CLCiffConversion_Layout.dll @ 4543fee2; FUN_4543fee2

undefined4 __cdecl FUN_4543fee2(uint param_1)

{
  int *piVar1;
  ulong *puVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if ((-1 < (int)param_1) && (param_1 < DAT_454626e8)) {
    iVar3 = (param_1 & 0x1f) * 0x40;
    if (((*(byte *)(iVar3 + 4 + (&DAT_454612f8)[(int)param_1 >> 5]) & 1) != 0) &&
       (*(int *)(iVar3 + (&DAT_454612f8)[(int)param_1 >> 5]) != -1)) {
      if (DAT_45460bd8 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_4543ff3f;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_4543ff3f:
      *(undefined4 *)(iVar3 + (&DAT_454612f8)[(int)param_1 >> 5]) = 0xffffffff;
      return 0;
    }
  }
  piVar1 = __errno();
  *piVar1 = 9;
  puVar2 = ___doserrno();
  *puVar2 = 0;
  return 0xffffffff;
}


