#ifndef ROXLU_QUADH
#define ROXLU_QUADH

struct Quad {
	int a,b,c,d;
	Quad(int nA, int nB, int nC, int nD):a(nA),b(nB),c(nC),d(nD)
	{
	}
	void set(int nA, int nB, int nC, int nD) {
		a = nA;
		b = nB;
		c = nC;
		d = nD;
	}
};

#endif