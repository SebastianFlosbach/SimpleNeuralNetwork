#include "simpleNN.h"


namespace SimpleNN {


	CSimpleNN_ptr CreateSimpleNN( const SimpleNNData& data ) {
		return std::make_unique<CSimpleNN>(data);
	}


}
