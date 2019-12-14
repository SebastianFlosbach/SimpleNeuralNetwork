#include "simpleNN.h"


namespace SimpleNN {


	CSimpleNN_ptr Create( const SimpleNNData& data ) {
		return std::make_unique<CSimpleNN>(data);
	}


}
