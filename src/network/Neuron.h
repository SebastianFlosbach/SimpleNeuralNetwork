#pragma once
#include <memory>

typedef unsigned int Uint32;

namespace network {

	class Neuron;

	typedef std::unique_ptr<Neuron> NeuronPtr;

	class Neuron {

		Uint32 id_;
		float bias_;

	public:
		Neuron( Uint32 id ) : id_( id ) {

		}

		const Uint32 Id() const { return id_; }
		const float getOutput( float input ) const;
		const float getBias() const { return bias_; }
		void setBias( float bias ) { bias_ = bias; }



	};

}