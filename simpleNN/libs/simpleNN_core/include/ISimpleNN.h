#pragma once

#include <memory>


class ISimpleNN {
public:
	

};

typedef std::unique_ptr<ISimpleNN> ISimpleNN_ptr;
typedef std::shared_ptr<ISimpleNN> ISimpleNN_sptr;
