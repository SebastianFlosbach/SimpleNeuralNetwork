#include "simpleNN.h"


CSimpleNN_ptr CreateSimpleNN( const SimpleNNData& data ) {
	return std::make_unique<CSimpleNN>(data);
}

