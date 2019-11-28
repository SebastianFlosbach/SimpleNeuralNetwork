#pragma once

#include "ISimpleNN.h"
#include "SimpleNNData.h"


class SimpleNNFactory {
public:
	ISimpleNN_ptr createSimpleNN( const SimpleNNData& data );

};
