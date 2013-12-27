#define VERSION_MAJOR "0"
#define VERSION_MINOR "01"
#define CYC2NS_SCALE_FACTOR 10
/* from linux kernel (/include/linux/kernel.h b/include/linux/kernel.h)
 * Multiplies an integer by a fraction, while avoiding unnecessary
 * overflow or loss of precision.
 */
#define mult_frac(x, numer, denom)(                        \
{                                                          \
    typeof(x) quot = (x) / (denom);                        \
    typeof(x) rem  = (x) % (denom);                        \
    (quot * (numer)) + ((rem * (numer)) / (denom));        \
}                                                          \
)

uint64_t get_tsc();
void tsc_check(uint32_t frequency);
