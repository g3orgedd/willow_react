// Source: CLCiffConversion_Layout.dll @ 4543167e; FUN_4543167e

int __cdecl
FUN_4543167e(undefined1 *param_1,uint param_2,int param_3,int param_4,int *param_5,char param_6,
            int *param_7)

{
  int *piVar1;
  int iVar2;
  errno_t eVar3;
  int iVar4;
  undefined1 *puVar5;
  char *_Dst;
  int iVar6;
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_4542c8eb(local_14,param_7);
  if ((param_1 == (undefined1 *)0x0) || (param_2 == 0)) {
    piVar1 = __errno();
    iVar6 = 0x16;
  }
  else {
    iVar6 = 0;
    iVar2 = param_3;
    if (param_3 < 1) {
      iVar2 = 0;
    }
    if (iVar2 + 9U < param_2) {
      if (param_6 != '\0') {
        __shift(param_1 + (*param_5 == 0x2d),(uint)(0 < param_3));
      }
      puVar5 = param_1;
      if (*param_5 == 0x2d) {
        *param_1 = 0x2d;
        puVar5 = param_1 + 1;
      }
      if (0 < param_3) {
        *puVar5 = puVar5[1];
        puVar5 = puVar5 + 1;
        *puVar5 = *(undefined1 *)**(undefined4 **)(local_14[0] + 0x84);
      }
      _Dst = puVar5 + (uint)(param_6 == '\0') + param_3;
      puVar5 = (undefined1 *)0xffffffff;
      if (param_2 != 0xffffffff) {
        puVar5 = param_1 + (param_2 - (int)_Dst);
      }
      eVar3 = _strcpy_s(_Dst,(rsize_t)puVar5,"e+000");
      if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      if (param_4 != 0) {
        *_Dst = 'E';
      }
      if (*(char *)param_5[3] != '0') {
        iVar2 = param_5[1] + -1;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
          _Dst[1] = '-';
        }
        if (99 < iVar2) {
          iVar4 = iVar2 / 100;
          iVar2 = iVar2 % 100;
          _Dst[2] = _Dst[2] + (char)iVar4;
        }
        if (9 < iVar2) {
          iVar4 = iVar2 / 10;
          iVar2 = iVar2 % 10;
          _Dst[3] = _Dst[3] + (char)iVar4;
        }
        _Dst[4] = _Dst[4] + (char)iVar2;
      }
      if (((DAT_4546168c & 1) != 0) && (_Dst[2] == '0')) {
        FUN_4542a090((undefined8 *)(_Dst + 2),(undefined8 *)(_Dst + 3),3);
      }
      goto LAB_454317af;
    }
    piVar1 = __errno();
    iVar6 = 0x22;
  }
  *piVar1 = iVar6;
  FUN_45432798();
LAB_454317af:
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar6;
}


