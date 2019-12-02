#pragma once


class IFitness {
public:
	virtual bool operator>( const IFitness& right ) = 0;
	virtual bool operator<( const IFitness& right ) = 0;

	virtual bool operator>=( const IFitness& right ) = 0;
	virtual bool operator<=( const IFitness& right ) = 0;

};
