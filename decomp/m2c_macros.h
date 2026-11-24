/* the few m2c macros the drafts use (m2c --valid-syntax), written for GCC 2.95 */
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
#define M2C_UNK s32
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_ERROR(desc) (0)
