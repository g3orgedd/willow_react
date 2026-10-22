// Source: CLCiffConversion_Layout.dll @ 45426ebf; FUN_45426ebf

/* WARNING: Unable to track spacebase fully for stack */

void FUN_45426ebf(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 unaff_BL;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  HMODULE unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (*(int *)(unaff_EBP + -0x418) != 0) {
    FUN_45404b24(*(void **)(unaff_EBP + -0x418),*(rsize_t *)(unaff_EBP + -0x41c),
                 *(void **)(unaff_EBP + -0x424),*(rsize_t *)(unaff_EBP + -0x41c));
    iVar1 = *(int *)(unaff_EBP + 0x14);
    *(undefined1 *)(*(int *)(unaff_EBP + -0x418) + *(int *)(unaff_EBP + -0x41c)) = unaff_BL;
    FUN_45426bee((void *)(unaff_EBP + -0x434),*(char **)(unaff_EBP + -0x418),iVar1);
  }
  if (unaff_EDI != (HMODULE)0x0) {
    FreeLibrary(unaff_EDI);
  }
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_454037d2((undefined4 *)(unaff_EBP + -0x418));
  }
  while (unaff_ESI != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*unaff_ESI;
    FID_conflict__free(unaff_ESI);
    unaff_ESI = puVar2;
  }
  *(undefined4 *)(unaff_EBP + -0x448) = 0x45426f81;
  FUN_4542a966();
  return;
}


