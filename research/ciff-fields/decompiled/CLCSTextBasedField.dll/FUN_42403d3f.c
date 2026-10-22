// Source: CLCSTextBasedField.dll @ 42403d3f; FUN_42403d3f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_42403d3f(void)

{
  undefined4 *in_EAX;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = 1;
    *(undefined2 *)((int)in_EAX + unaff_ESI * 2 + 0xc) = 0;
    in_EAX[1] = unaff_ESI;
    in_EAX[2] = unaff_ESI;
    *unaff_EDI = in_EAX + 3;
  }
  return;
}


