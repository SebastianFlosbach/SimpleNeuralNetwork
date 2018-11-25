#pragma once
#include "Connection.h"

#include <memory>
#include <vector>

typedef unsigned int Uint32;

namespace network {

	class Neuron;

	typedef std::shared_ptr<Neuron> NeuronPtr;

	class Neuron {
		Uint32 id_;
		float bias_;
		std::vector<Connection> connections_;

		float currentInput_;

	public:
		Neuron( Uint32 id ) : id_( id ) {

		}

		const Uint32 Id() const { return id_; }
		const float getOutput( float input ) const;
		const float getBias() const { return bias_; }
		void setBias( float bias ) { bias_ = bias; }
		void addConnection( float bias, NeuronPtr& target );
		const std::vector<Connection>& getConnections() const { return connections_; }
		bool removeConnection( Uint32 id );
		void resetInput();
		void addToInput( float input );

	};

}