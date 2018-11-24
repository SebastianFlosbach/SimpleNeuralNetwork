#pragma once
#include "../network/Layer.h"

namespace factory {
	
	class LayerFactory {
		Uint32 idCounter;

	public:
		LayerFactory() {
			idCounter = 0;
		}

		network::LayerPtr createLayer() {
			return std::make_unique<network::Layer>( idCounter++ );
		}

	};
}