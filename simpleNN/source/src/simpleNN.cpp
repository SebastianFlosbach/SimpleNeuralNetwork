#include "simpleNN.h"


SimpleNNFactory* CreateSimpleNNFactory() {
	return new SimpleNNFactory();
}

void DestroySimpleNNFactory(SimpleNNFactory* factory) {
	if (factory == nullptr) {
		return;
	}

	delete factory;
}
