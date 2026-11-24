typedef unsigned short u16; typedef int s32;
extern char D_800A090A[], D_800A0926[], D_800A093A[], D_800A0952[], D_800A0966[];
void func_80094164(s32, char *);
void func_80091A44(u16 arg0) {
    switch (arg0) {
    case 0: func_80094164(2, D_800A090A); break;
    case 1: func_80094164(2, D_800A0926); break;
    case 2: func_80094164(2, D_800A093A); break;
    case 3: func_80094164(2, D_800A0952); break;
    case 4: func_80094164(2, D_800A0966); break;
    }
}
