#include "simpleNNTrainer.h"

#include "CSimpleNNTrainer.h"


ISimpleNNTrainer* CreateSimpleNNTrainer( uint32_t generationSize, float chance, float range ) {
	return new CSimpleNNTrainer( generationSize, chance, range );
}

void DestroySimpleNNTrainer( ISimpleNNTrainer* trainer ) {
	if( trainer == nullptr ) {
		return;
	}

	delete trainer;
}
