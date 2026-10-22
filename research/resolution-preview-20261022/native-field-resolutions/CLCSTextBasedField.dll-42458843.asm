42458843  push      0
42458845  mov       eax, 0x424916f5
4245884a  call      0x4246ed14
4245884f  mov       eax, dword ptr [ebp + 0x10]
42458852  lea       edx, [ebp + 0xc]
42458855  and       dword ptr [ebp - 4], 0
42458859  cmp       dword ptr [ebp + 0xc], 1
4245885d  push      edx
4245885e  mov       ecx, dword ptr [eax]
42458860  push      eax
42458861  jne       0x42458868
42458863  call      dword ptr [ecx + 0x2c]
42458866  jmp       0x4245886b
42458868  call      dword ptr [ecx + 0x34]
4245886b  movd      xmm0, dword ptr [ebp + 8]
42458870  cvtdq2ps  xmm0, xmm0
42458873  push      ecx
42458874  divss     xmm0, dword ptr [ebp + 0xc]
42458879  movss     dword ptr [esp], xmm0
4245887e  call      0x424264fb
42458883  or        dword ptr [ebp - 4], 0xffffffff
42458887  mov       esi, eax
42458889  pop       ecx
4245888a  mov       ecx, dword ptr [ebp + 0x10]
4245888d  test      ecx, ecx
4245888f  je        0x42458897
42458891  mov       edx, dword ptr [ecx]
42458893  push      ecx
42458894  call      dword ptr [edx + 8]
42458897  mov       eax, esi
42458899  call      0x4246ece2
4245889e  ret       
