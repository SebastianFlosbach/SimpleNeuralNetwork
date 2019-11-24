#pragma once

#include "simpleNN_export.h"

#include "CSimpleNN.h"

namespace SimpleNN {


SIMPLE_NN_EXPORTS CSimpleNN_ptr create( uint32_t argn, const Layer* layer );


}