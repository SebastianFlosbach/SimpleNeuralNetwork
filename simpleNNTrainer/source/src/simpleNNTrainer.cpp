#include "simpleNNTrainer.h"

#include "CSimpleNNTrainer.h"


CSimpleNNTrainer* CreateSimpleNNTrainer( uint32_t generationSize, float chance, float range ) {
	return new CSimpleNNTrainer( generationSize, chance, range );
}

void DestroySimpleNNTrainer( CSimpleNNTrainer* trainer ) {
	if( trainer == nullptr ) {
		return;
	}

	delete trainer;
}
