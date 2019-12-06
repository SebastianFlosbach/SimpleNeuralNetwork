#pragma once

#include "CSimpleNN.h"
#include "SimpleNNData.h"


class SimpleNNFactory {
public:
	CSimpleNN_ptr createSimpleNN( const SimpleNNData& data );

};
