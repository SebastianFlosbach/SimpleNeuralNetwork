#pragma once
#include "Neuron.h"

#include <vector>


class Layer;

class Layer {
	// Unique identifier of this layer inside its network
	Uint32 id_;

	// Array of neurons this layer holds
	mutable std::vector<Neuron> neurons_;

public:
	Layer( Uint32 id ) : id_( id ) {
	}

	Layer( const Layer& other ) = delete;
	Layer& operator=( const Layer& other ) = delete;

	Layer( Layer&& other );
	Layer& operator=( Layer&& other );

	~Layer() = default;

	// Getter
	inline const Uint32 id() const { return id_; }
	const Uint32 size() const { return neurons_.size(); }

	const void addNeuron( const Uint32 count );
	Neuron* addNeuron();
	Neuron* getNeuron( Uint32 id ) const;

	Layer copy() const;
};