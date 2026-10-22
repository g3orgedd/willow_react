42458960  push      8
42458962  mov       eax, 0x4248e334
42458967  call      0x4246ed14
4245896c  mov       eax, dword ptr [ebp + 0xc]
4245896f  lea       edx, [ebp - 0x10]
42458972  and       dword ptr [ebp - 4], 0
42458976  push      edx
42458977  push      eax
42458978  mov       ecx, dword ptr [eax]
4245897a  call      dword ptr [ecx + 0x2c]
4245897d  mov       eax, dword ptr [ebp + 0xc]
42458980  lea       edx, [ebp - 0x14]
42458983  push      edx
42458984  push      eax
42458985  mov       ecx, dword ptr [eax]
42458987  call      dword ptr [ecx + 0x34]
4245898a  mov       esi, dword ptr [ebp + 8]
4245898d  push      ecx
4245898e  movd      xmm0, dword ptr [esi]
42458992  cvtdq2ps  xmm0, xmm0
42458995  mulss     xmm0, dword ptr [ebp - 0x10]
4245899a  movss     dword ptr [esp], xmm0
4245899f  call      0x424264fb
424589a4  movd      xmm0, dword ptr [esi + 4]
424589a9  cvtdq2ps  xmm0, xmm0
424589ac  mov       dword ptr [esi], eax
424589ae  mulss     xmm0, dword ptr [ebp - 0x14]
424589b3  movss     dword ptr [esp], xmm0
424589b8  call      0x424264fb
424589bd  or        dword ptr [ebp - 4], 0xffffffff
424589c1  mov       dword ptr [esi + 4], eax
424589c4  mov       eax, dword ptr [ebp + 0xc]
424589c7  pop       ecx
424589c8  test      eax, eax
424589ca  je        0x424589d2
424589cc  mov       ecx, dword ptr [eax]
424589ce  push      eax
424589cf  call      dword ptr [ecx + 8]
424589d2  call      0x4246ece2
424589d7  ret       8
