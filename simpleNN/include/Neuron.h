#pragma once
#include "Connection.h"

#include <memory>
#include <vector>

typedef unsigned int Uint32;


	class Neuron;
	class Connection;

	typedef std::shared_ptr<Neuron> NeuronPtr;

	class Neuron {
		Uint32 id_;
		float bias_;
		std::vector<Connection> connections_;

		float currentInput_;

	public:
		Neuron( Uint32 id );

		inline const Uint32 id() const { return id_; }
		inline const Uint32 size() const { return connections_.size(); }
		inline const float getBias() const { return bias_; }
		void setBias( float bias ) { bias_ = bias; }
		const float getOutput() const;
		void addConnection( NeuronPtr& target );
		void addConnection( NeuronPtr& target, float weight );
		Connection* getConnection( Uint32 targetId );
		void operateConnection();
		void resetInput();
		void addToInput( float input );
		void setInput( float input );

	};
