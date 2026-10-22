// Source: CLCiffConversion_Layout.dll @ 4540d969; FUN_4540d969

void __fastcall FUN_4540d969(int param_1)

{
  if (*(int *)(param_1 + 0x74) != 0) {
    FID_conflict__free(*(void **)(param_1 + 0x74));
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  if (*(void **)(param_1 + 0x88) != (void *)0x0) {
    FID_conflict__free(*(void **)(param_1 + 0x88));
    *(undefined4 *)(param_1 + 0x88) = 0;
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  if (*(void **)(param_1 + 0x94) != (void *)0x0) {
    FID_conflict__free(*(void **)(param_1 + 0x94));
    *(undefined4 *)(param_1 + 0x94) = 0;
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  if (*(void **)(param_1 + 0xb4) != (void *)0x0) {
    FID_conflict__free(*(void **)(param_1 + 0xb4));
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  return;
}


