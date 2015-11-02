// Micro Programming - Assignment - Hardware Simulator
// Abhinav Jain, 13MA20004 	
#include <stdio.h>

main() {
	// ib = Internal Bus , ir = Input Register, mar = Memory Address Register, mbr = Memory Buffer Register, pc = Program Counter
	// d, e = General Purpose Registers
	// p, q = Special Function Registers
	int ib, ir, mar, mbr, pc, d, e, f, p, q, n, k[100], i, flag;
	pc = 0; i = 0;
	do {
		if(i <= pc) { scanf("%d", &k[i]); i++; continue; } ir = k[pc]; pc++;
		if((ir == 10) && (flag == 0)) pc = ib;
		if(ir == 11) mar = ib;			if(ir == 21) ib = mar;   
		if(ir == 12) mbr = ib;			if(ir == 22) ib = mbr;
		if(ir == 13) pc = ib;			if(ir == 23) ib = pc;
		if(ir == 14) d = ib;			if(ir == 24) ib = d;
		if(ir == 15) e = ib;			if(ir == 25) ib = e;
		if(ir == 0) mbr = k[mar];		if(ir == 1) k[mar] = mbr;
		if(ir == 31) p = ib;			if(ir == 32) q = ib;
		if(ir == 33) {
			ib = p + q;
			flag = (ib < 0)? 1 : 0;
		}
		if(ir == 34) {
			ib = p - q;
			flag = (ib < 0)? 1 : 0;
		}
		if(ir == 35) {
			ib = p * q;		
		}
		if(ir == 36) {
			ib = p / q;		
		}
		if(ir == 47) {
			printf("Give Input");
			scanf("%d", &ib);
		}
		if(ir == 48) {
			printf("Output %d ", ib);
			sleep(1);
			fflush(stdout);		
		}
		if(ir / 100 == 5) ib = ir % 100;
	}
	while (ir != 49);
	printf("Over");
}
