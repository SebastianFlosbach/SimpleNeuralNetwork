#pragma once

#include "simpleNNTrainer_export.h"

#include "ISimpleNNTrainer.h"


SIMPLE_NN_TRAINER_EXPORTS ISimpleNNTrainer* CreateSimpleNNTrainer();
SIMPLE_NN_TRAINER_EXPORTS void DestroySimpleNNTrainer( ISimpleNNTrainer* trainer );
