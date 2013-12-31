/*
 * Author: hisayosh ( Hisayoshi Tamaki )
 *
 * @brief tsc_checker
 * @file tsc_checker.c
 */

#include <stdio.h>
#include <getopt.h>
#include <stdint.h>
#include <stdlib.h>
#include "tsc_checker.h"

/* Command Line options */
static struct option const long_opts[] = {
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, 0, 'v'},
    {"frequency", required_argument, NULL, 'f'},
    {NULL, 0, NULL, 0}
};

/** Show help information
 * @param none
 * @return none
 */
static void usage(void){

    printf("Usage:\n");
    printf("  -h                           "
	   "show help\n");
    printf("  -v                           "
	   "show version\n");
    printf("  -f FREQUENCY                 "
	   "specify the frequency of CPU (KHz) [default: 2000000]\n");
}

/** Show version information
 * @param none
 * @return none
 */
static void version(void){

    printf("tsc_checker "
	   "version %s.%s\n", VERSION_MAJOR, VERSION_MINOR);

}

int32_t main(int argc, char *argv[]){

    int32_t opt = 0;
    uint32_t frequency = 2000000;

    for (; (opt = getopt_long(argc, argv, "hvf:", long_opts, NULL)) != -1 ;){

	switch(opt) {

	case 'h':
	    usage();
	    goto exit;
	case 'v':
	    version();
	    goto exit;
	case 'f':
	    frequency = atoi(optarg);
	    if(!(frequency > 0)){
		goto exit;
	    }
	    break;
	default:
	    usage();
	    goto exit;
	}
    
    }

    tsc_check(frequency);

exit:
    return 0;
}

void tsc_check(uint32_t frequency){

    uint64_t tsc, current;
    uint32_t scale;
    uint32_t cpu_khz = frequency;

    tsc = get_tsc();
    scale = (1000000 << CYC2NS_SCALE_FACTOR) / cpu_khz;
    current = tsc * scale;
//    current = mult_frac(tsc, scale, (1UL << CYC2NS_SCALE_FACTOR));
    printf("TSC value        : %llu\n", (unsigned long long)tsc);
    printf("SC value         : %u\n", (unsigned int)scale); 

    if(current/tsc != scale){
	printf("***warning***\n"
	       "there is the possibility of numeric overflow "
	       "at the next time of startup if you have not taken measure.\n");
    }else{
	printf("current value    : %llu\n", (unsigned long long)current);
	printf("threashold value : %llu\n",  ((unsigned long long)~0));
    }

}

uint64_t get_tsc(){

    uint64_t val;
    uint32_t low, high;

    asm volatile ("rdtsc" : "=a" (low), "=d" (high));
    val = (uint64_t)low | ((uint64_t)high << 32);

    return val;
}
