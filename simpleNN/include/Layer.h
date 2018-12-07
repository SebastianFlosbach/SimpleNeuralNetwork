#pragma once
#include "Neuron.h"

#include <vector>


	class Layer;

	typedef std::unique_ptr<Layer> LayerPtr;

	class Layer {
		// Unique identifier of this layer inside its network
		Uint32 id_;

		// Array of neurons this layer holds
		std::vector<NeuronPtr> neurons_;

	public:
		Layer( Uint32 id ) : id_( id ) {
		}

		~Layer() = default;

		// Getter
		inline const Uint32 id() const { return id_; }
		const Uint32 size() const { return neurons_.size(); }

		const Uint32 addNeuron( const Uint32 count = 0 );
		NeuronPtr getNeuron( Uint32 id ) const;
		void resetInput();
		void setInput( Uint32 id, float input );
		void operateOutput();

	};