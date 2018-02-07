# ASanSample
A demo shows you how to run [AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer) on android using [wrap shell script](https://developer.android.com/ndk/guides/wrap-script.html).
## how to use
Run this app on device with 8.1 or emulator with android O. Then you will get the log as bellow:

```
wrap.sh: =================================================================
wrap.sh: [1m[31m==31040==ERROR: AddressSanitizer: heap-use-after-free on address 0xa791bc40 at pc 0x99a4c297 bp 0xbf8ad1b8 sp 0xbf8ad1a8
wrap.sh: [1m[0m[1m[34mREAD of size 4 at 0xa791bc40 thread T0 (gwhp.asansample)[1m[0m
wrap.sh:     #0 0x99a4c296  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/lib/x86/libnative-lib.so+0x5296)
wrap.sh:     #1 0x99a4bfaa  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/lib/x86/libnative-lib.so+0x4faa)
wrap.sh:     #2 0x99a90088  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/oat/x86/base.odex+0x9088)
wrap.sh: [1m[32m0xa791bc40 is located 0 bytes inside of 400-byte region [0xa791bc40,0xa791bdd0)
wrap.sh: [1m[0m[1m[35mfreed by thread T0 (gwhp.asansample) here:[1m[0m
wrap.sh:     #0 0xacea1551  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/lib/x86/libclang_rt.asan-i686-android.so+0x91551)
wrap.sh:     #1 0x99a4c252  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/lib/x86/libnative-lib.so+0x5252)
wrap.sh:     #2 0x99a4bfaa  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/lib/x86/libnative-lib.so+0x4faa)
wrap.sh:     #3 0x99a90088  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/oat/x86/base.odex+0x9088)
wrap.sh:     #4 0xa910307f  (<unknown module>)
wrap.sh:     #5 0x3fe458c7  (<unknown module>)
wrap.sh: [1m[35mpreviously allocated by thread T0 (gwhp.asansample) here:[1m[0m
wrap.sh:     #0 0xacea07d1  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/lib/x86/libclang_rt.asan-i686-android.so+0x907d1)
wrap.sh:     #1 0x99a4c22d  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/lib/x86/libnative-lib.so+0x522d)
wrap.sh:     #2 0x99a4bfaa  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/lib/x86/libnative-lib.so+0x4faa)
wrap.sh:     #3 0x99a90088  (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/oat/x86/base.odex+0x9088)
wrap.sh:     #4 0xa910307f  (<unknown module>)
wrap.sh:     #5 0x3fe458c7  (<unknown module>)
wrap.sh: SUMMARY: AddressSanitizer: heap-use-after-free (/data/app/com.github.sgwhp.asansample-wd9ONFhysI1uyGX_DI5cRg==/lib/x86/libnative-lib.so+0x5296)
wrap.sh: Shadow bytes around the buggy address:
wrap.sh:   0x14f23730: [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m
wrap.sh:   0x14f23740: [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m
wrap.sh:   0x14f23750: [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m
wrap.sh:   0x14f23760: [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m
wrap.sh:   0x14f23770: [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m
wrap.sh: =>0x14f23780: [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m[[1m[35mfd[1m[0m][1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m
wrap.sh:   0x14f23790: [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m
wrap.sh:   0x14f237a0: [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m
wrap.sh:   0x14f237b0: [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[35mfd[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m
wrap.sh:   0x14f237c0: [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m
wrap.sh:   0x14f237d0: [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m [1m[31mfa[1m[0m
wrap.sh: Shadow byte legend (one shadow byte represents 8 application bytes):
wrap.sh:   Addressable:           [1m[0m00[1m[0m
wrap.sh:   Partially addressable: [1m[0m01[1m[0m [1m[0m02[1m[0m [1m[0m03[1m[0m [1m[0m04[1m[0m [1m[0m05[1m[0m [1m[0m06[1m[0m [1m[0m07[1m[0m
wrap.sh:   Heap left redzone:       [1m[31mfa[1m[0m
wrap.sh:   Freed heap region:       [1m[35mfd[1m[0m
wrap.sh:   Stack left redzone:      [1m[31mf1[1m[0m
wrap.sh:   Stack mid redzone:       [1m[31mf2[1m[0m
wrap.sh:   Stack right redzone:     [1m[31mf3[1m[0m
wrap.sh:   Stack after return:      [1m[35mf5[1m[0m
wrap.sh:   Stack use after scope:   [1m[35mf8[1m[0m
wrap.sh:   Global redzone:          [1m[31mf9[1m[0m
wrap.sh:   Global init order:       [1m[36mf6[1m[0m
wrap.sh:   Poisoned by user:        [1m[34mf7[1m[0m
wrap.sh:   Container overflow:      [1m[34mfc[1m[0m
wrap.sh:   Array cookie:            [1m[31mac[1m[0m
wrap.sh:   Intra object redzone:    [1m[33mbb[1m[0m
wrap.sh:   ASan internal:           [1m[33mfe[1m[0m
wrap.sh:   Left alloca redzone:     [1m[34mca[1m[0m
wrap.sh:   Right alloca redzone:    [1m[34mcb[1m[0m
wrap.sh: ==31040==ABORTING
wrap.sh: Aborted
wrap.sh: wrap.sh terminated by exit(134)
```

Using addr2line can get the actual line number from pc. You can find this tool under ndk directory.
