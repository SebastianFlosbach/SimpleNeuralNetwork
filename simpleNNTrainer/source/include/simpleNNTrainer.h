#pragma once

#include "simpleNNTrainer_export.h"

#include "CSimpleNNTrainer.h"


SIMPLE_NN_TRAINER_EXPORTS CSimpleNNTrainer* CreateSimpleNNTrainer( uint32_t generationSize, float chance, float range );
SIMPLE_NN_TRAINER_EXPORTS void DestroySimpleNNTrainer( CSimpleNNTrainer* trainer );
