#pragma once
#include "Connection.h"

#include <memory>
#include <vector>

typedef unsigned int Uint32;

namespace network {

	class Neuron;
	class Connection;

	typedef std::shared_ptr<Neuron> NeuronPtr;

	class Neuron {
		Uint32 id_;
		float bias_;
		std::vector<Connection> connections_;

		float currentInput_;

	public:
		Neuron( Uint32 id, float bias ) : id_( id ), bias_( bias ) {
		}

		inline const Uint32 Id() const { return id_; }
		inline const float getBias() const { return bias_; }
		const float getOutput() const;
		void addConnection( float bias, NeuronPtr& target );
		void operateConnection();
		void resetInput();
		void addToInput( float input );
		void setInput( float input );

	};

}