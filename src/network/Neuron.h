#pragma once

typedef unsigned int Uint32;

namespace network {

	class Neuron {

		Uint32 id_;
		float bias_;

	public:
		Neuron();

		const Uint32 Id() const { return id_; }
		const float getOutput( float input ) const;
		const float getBias() const { return bias_; }
		void setBias( float bias ) { bias_ = bias; }



	};

}