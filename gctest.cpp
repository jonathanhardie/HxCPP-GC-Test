#define IMPLEMENT_API
#include <hx/CFFI.h>
#include <stdio.h>
extern "C" {	
	DECLARE_KIND(k_transform_matrix);
	DEFINE_KIND(k_transform_matrix);
	#define val_matrix(v) ((float*)val_data(v))
	
	void deallocateMatrix(value matrix) {		
		float* m = val_matrix(matrix);
		printf("freeing mem %p, abstract %p\n", m, matrix);
		free(m);
		free_abstract(matrix);
	}
	
	value allocateMatrix(value parent) {
		float* m = (float*)malloc(sizeof(float) * 6);
		m[0] = 0.0;
		m[1] = 1.0;
		m[2] = 2.0;
		m[3] = 3.0;
		m[4] = 4.0;
		m[5] = 5.0;
		value matrix = alloc_abstract(k_transform_matrix, m);
		printf("allocating %p, wrapping in abstract %p, setting finalizer %p\n", m, matrix, deallocateMatrix);
		val_gc(matrix, deallocateMatrix);	
		return matrix;
	}
}
DEFINE_PRIM( allocateMatrix, 0 );