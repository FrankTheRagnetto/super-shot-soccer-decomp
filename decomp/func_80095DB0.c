typedef unsigned char u8; typedef int s32;

void func_80095DB0(s32 *pos, s32 *vel, s32 *tgt, u8 snap) {
    s32 old, new, t;

    if (*vel != 0) {
        old = *pos;
        *pos = new = old + *vel;
        if (snap) {
            t = *tgt;
            if ((t < old) ? (t < new) : (new < t)) {
                return;
            }
            *pos = t;
            *vel = 0;
        }
    }
}
