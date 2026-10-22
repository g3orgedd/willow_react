00e62f49  push      ebp
00e62f4a  mov       ebp, esp
00e62f4c  sub       esp, 0x60
00e62f4f  mov       eax, dword ptr [0xf385b8]
00e62f54  xor       eax, ebp
00e62f56  mov       dword ptr [ebp - 4], eax
00e62f59  mov       eax, dword ptr [ebp + 0xc]
00e62f5c  push      ebx
00e62f5d  mov       dword ptr [ebp - 0x28], eax
00e62f60  mov       eax, dword ptr [ebp + 0x18]
00e62f63  push      esi
00e62f64  mov       esi, dword ptr [ebp + 0x1c]
00e62f67  mov       dword ptr [ebp - 0x50], eax
00e62f6a  xor       eax, eax
00e62f6c  push      edi
00e62f6d  mov       edi, dword ptr [ebp + 8]
00e62f70  mov       dword ptr [ebp - 0x38], eax
00e62f73  mov       dword ptr [ebp - 0x34], eax
00e62f76  mov       dword ptr [ebp - 0x24], eax
00e62f79  mov       dword ptr [ebp - 0x20], eax
00e62f7c  lea       eax, [ebp - 0x38]
00e62f7f  push      eax
00e62f80  push      dword ptr [edi]
00e62f82  mov       dword ptr [ebp - 0x30], edi
00e62f85  call      dword ptr [0xefc17c]
00e62f8b  lea       eax, [ebp - 0x24]
00e62f8e  push      eax
00e62f8f  push      dword ptr [edi]
00e62f91  call      dword ptr [0xefc154]
00e62f97  mov       al, byte ptr [ebp + 0x24]
00e62f9a  mov       ecx, 0xcc0020
00e62f9f  test      al, al
00e62fa1  mov       ebx, 0x8800c6
00e62fa6  cmovne    ebx, ecx
00e62fa9  cmp       byte ptr [ebp + 0x20], 0
00e62fad  mov       ecx, 0xbe0269
00e62fb2  cmovne    ebx, ecx
00e62fb5  and       dword ptr [ebp - 0x4c], 0
00e62fb9  and       dword ptr [ebp - 0x48], 0
00e62fbd  cmp       byte ptr [ebp + 0x28], 0
00e62fc1  mov       dword ptr [ebp - 0x40], ebx
00e62fc4  je        0xe62fd3
00e62fc6  test      al, al
00e62fc8  mov       ecx, 0xee0086
00e62fcd  cmovne    ebx, ecx
00e62fd0  mov       dword ptr [ebp - 0x40], ebx
00e62fd3  test      esi, esi
00e62fd5  je        0xe62ff7
00e62fd7  mov       ebx, 0xb8074a
00e62fdc  push      esi
00e62fdd  mov       dword ptr [ebp - 0x40], ebx
00e62fe0  call      dword ptr [0xefc1b0]
00e62fe6  mov       esi, eax
00e62fe8  push      esi
00e62fe9  push      dword ptr [edi]
00e62feb  mov       dword ptr [ebp - 0x48], esi
00e62fee  call      dword ptr [0xefc140]
00e62ff4  mov       dword ptr [ebp - 0x4c], eax
00e62ff7  mov       eax, dword ptr [ebp - 0x24]
00e62ffa  cdq       
00e62ffb  sub       eax, edx
00e62ffd  mov       esi, eax
00e62fff  mov       eax, dword ptr [ebp - 0x38]
00e63002  imul      eax, dword ptr [ebp + 0x10]
00e63006  sar       esi, 1
00e63008  add       eax, esi
00e6300a  cdq       
00e6300b  idiv      dword ptr [ebp - 0x24]
00e6300e  mov       dword ptr [ebp - 0x2c], eax
00e63011  mov       eax, dword ptr [ebp - 0x20]
00e63014  cdq       
00e63015  sub       eax, edx
00e63017  mov       ecx, eax
00e63019  mov       eax, dword ptr [ebp - 0x34]
00e6301c  imul      eax, dword ptr [ebp + 0x14]
00e63020  sar       ecx, 1
00e63022  mov       dword ptr [ebp - 0x3c], ecx
00e63025  add       eax, ecx
00e63027  mov       ecx, dword ptr [ebp - 0x2c]
00e6302a  cdq       
00e6302b  idiv      dword ptr [ebp - 0x20]
00e6302e  mov       dword ptr [ebp - 0x44], eax
00e63031  cmp       ecx, dword ptr [ebp + 0x10]
00e63034  jl        0xe6305e
00e63036  cmp       eax, dword ptr [ebp + 0x14]
00e63039  jl        0xe6305e
00e6303b  mov       eax, dword ptr [ebp - 0x28]
00e6303e  push      ebx
00e6303f  push      0
00e63041  push      0
00e63043  push      dword ptr [ebp - 0x50]
00e63046  push      dword ptr [ebp + 0x14]
00e63049  push      dword ptr [ebp + 0x10]
00e6304c  push      dword ptr [eax + 4]
00e6304f  push      dword ptr [eax]
00e63051  push      dword ptr [edi]
00e63053  call      dword ptr [0xefc11c]
00e63059  jmp       0xe631aa
00e6305e  mov       ecx, dword ptr [ebp - 0x28]
00e63061  push      dword ptr [edi]
00e63063  mov       eax, dword ptr [ecx]
00e63065  imul      eax, dword ptr [ebp - 0x38]
00e63069  add       eax, esi
00e6306b  cdq       
00e6306c  idiv      dword ptr [ebp - 0x24]
00e6306f  mov       dword ptr [ebp - 0x28], eax
00e63072  mov       eax, dword ptr [ecx + 4]
00e63075  imul      eax, dword ptr [ebp - 0x34]
00e63079  add       eax, dword ptr [ebp - 0x3c]
00e6307c  cdq       
00e6307d  idiv      dword ptr [ebp - 0x20]
00e63080  mov       dword ptr [ebp - 0x3c], eax
00e63083  call      dword ptr [0xefc1b4]
00e63089  push      dword ptr [ebp - 0x44]
00e6308c  mov       esi, eax
00e6308e  push      dword ptr [ebp - 0x2c]
00e63091  push      dword ptr [edi]
00e63093  call      dword ptr [0xefc118]
00e63099  mov       edi, eax
00e6309b  push      edi
00e6309c  push      esi
00e6309d  call      dword ptr [0xefc140]
00e630a3  push      0x18
00e630a5  mov       dword ptr [ebp - 0x54], eax
00e630a8  pop       eax
00e630a9  mov       word ptr [ebp - 0x1c], ax
00e630ad  lea       eax, [ebp - 0x1c]
00e630b0  push      eax
00e630b1  push      esi
00e630b2  call      dword ptr [0xefc0c8]
00e630b8  mov       eax, 0x3e8
00e630bd  push      esi
00e630be  mov       word ptr [ebp - 0x10], ax
00e630c2  call      dword ptr [0xefc0cc]
00e630c8  push      4
00e630ca  mov       ebx, eax
00e630cc  push      esi
00e630cd  mov       dword ptr [ebp - 0x5c], ebx
00e630d0  call      dword ptr [0xefc0c0]
00e630d6  mov       dword ptr [ebp - 0x58], eax
00e630d9  lea       eax, [ebp - 0x1c]
00e630dc  push      eax
00e630dd  push      esi
00e630de  call      dword ptr [0xefc0c4]
00e630e4  push      0
00e630e6  push      ebx
00e630e7  push      esi
00e630e8  call      dword ptr [0xefc0bc]
00e630ee  push      esi
00e630ef  mov       dword ptr [ebp - 0x60], eax
00e630f2  call      dword ptr [0xefc0b8]
00e630f8  xor       ebx, ebx
00e630fa  push      ebx
00e630fb  push      ebx
00e630fc  push      ebx
00e630fd  push      esi
00e630fe  call      dword ptr [0xefc144]
00e63104  push      0xcc0020
00e63109  push      dword ptr [ebp + 0x14]
00e6310c  push      dword ptr [ebp + 0x10]
00e6310f  push      ebx
00e63110  push      ebx
00e63111  push      dword ptr [ebp - 0x50]
00e63114  push      dword ptr [ebp - 0x44]
00e63117  push      dword ptr [ebp - 0x2c]
00e6311a  push      ebx
00e6311b  push      ebx
00e6311c  push      esi
00e6311d  call      dword ptr [0xefc110]
00e63123  mov       eax, dword ptr [ebp - 0x30]
00e63126  push      ebx
00e63127  push      dword ptr [ebp - 0x20]
00e6312a  mov       ebx, dword ptr [0xefc164]
00e63130  push      dword ptr [ebp - 0x24]
00e63133  push      dword ptr [eax]
00e63135  call      ebx
00e63137  push      dword ptr [ebp - 0x40]
00e6313a  push      0
00e6313c  push      0
00e6313e  mov       eax, dword ptr [ebp - 0x30]
00e63141  push      esi
00e63142  push      dword ptr [ebp - 0x44]
00e63145  push      dword ptr [ebp - 0x2c]
00e63148  push      dword ptr [ebp - 0x3c]
00e6314b  push      dword ptr [ebp - 0x28]
00e6314e  push      dword ptr [eax]
00e63150  call      dword ptr [0xefc11c]
00e63156  mov       eax, dword ptr [ebp - 0x30]
00e63159  push      0
00e6315b  push      dword ptr [ebp - 0x34]
00e6315e  push      dword ptr [ebp - 0x38]
00e63161  push      dword ptr [eax]
00e63163  call      ebx
00e63165  push      0
00e63167  push      dword ptr [ebp - 0x60]
00e6316a  push      esi
00e6316b  call      dword ptr [0xefc0bc]
00e63171  push      esi
00e63172  call      dword ptr [0xefc0b8]
00e63178  push      dword ptr [ebp - 0x58]
00e6317b  push      esi
00e6317c  call      dword ptr [0xefc0c0]
00e63182  push      dword ptr [ebp - 0x5c]
00e63185  call      dword ptr [0xefc124]
00e6318b  push      dword ptr [ebp - 0x54]
00e6318e  push      esi
00e6318f  call      dword ptr [0xefc140]
00e63195  test      edi, edi
00e63197  je        0xe631a0
00e63199  push      edi
00e6319a  call      dword ptr [0xefc124]
00e631a0  push      esi
00e631a1  call      dword ptr [0xefc138]
00e631a7  mov       edi, dword ptr [ebp - 0x30]
00e631aa  mov       eax, dword ptr [ebp - 0x4c]
00e631ad  test      eax, eax
00e631af  je        0xe631c3
00e631b1  push      eax
00e631b2  push      dword ptr [edi]
00e631b4  call      dword ptr [0xefc140]
00e631ba  push      dword ptr [ebp - 0x48]
00e631bd  call      dword ptr [0xefc124]
00e631c3  mov       ecx, dword ptr [ebp - 4]
00e631c6  pop       edi
00e631c7  pop       esi
00e631c8  xor       ecx, ebp
00e631ca  pop       ebx
00e631cb  call      0xec9db6
00e631d0  mov       esp, ebp
00e631d2  pop       ebp
00e631d3  ret       0x24
