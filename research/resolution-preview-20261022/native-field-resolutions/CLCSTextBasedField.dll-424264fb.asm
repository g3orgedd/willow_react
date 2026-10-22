424264fb  push      ebp
424264fc  mov       ebp, esp
424264fe  xorps     xmm0, xmm0
42426501  comiss    xmm0, dword ptr [ebp + 8]
42426505  jbe       0x42426511
42426507  movss     xmm0, dword ptr [0x424983f4]
4242650f  jmp       0x42426519
42426511  movss     xmm0, dword ptr [0x424983e0]
42426519  addss     xmm0, dword ptr [ebp + 8]
4242651e  cvttss2si eax, xmm0
42426522  pop       ebp
42426523  ret       
