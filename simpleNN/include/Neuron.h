#pragma once
#include "Connection.h"

#include <memory>
#include <vector>

typedef unsigned int Uint32;

class Neuron;
class Connection;

class Neuron {
	Uint32 id_;
	float bias_;
	std::vector<Connection> connections_;

public:
	Neuron( Uint32 id );
	Neuron( Uint32 id, float bias );

	Neuron( const Neuron& other ) = delete;
	Neuron& operator=( const Neuron& other ) = delete;

	Neuron( Neuron&& other );
	Neuron& operator=( Neuron&& other ) noexcept;

	inline Uint32 id() const { return id_; }

	inline float getBias() const { return bias_; }
	inline void setBias( float bias ) { bias_ = bias; }

	// Connection
	inline Uint32 numberOfConnections() const { return connections_.size(); }
	void addConnection( Neuron& target, float weight );
	Connection& getConnection( Uint32 targetId );

	Neuron copy() const;
};
