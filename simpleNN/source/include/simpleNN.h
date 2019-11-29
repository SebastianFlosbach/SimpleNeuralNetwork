#pragma once

#include "simpleNN_export.h"

#include "SimpleNNFactory.h"


SIMPLE_NN_EXPORTS SimpleNNFactory* CreateSimpleNNFactory();
SIMPLE_NN_EXPORTS void DestroySimpleNNFactory(SimpleNNFactory* factory);
