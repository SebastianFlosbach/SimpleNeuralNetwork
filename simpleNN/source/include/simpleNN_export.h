#pragma once

#ifdef SIMPLE_NN_EXPORTS
#define SIMPLE_NN_EXPORTS __declspec(dllexport)
#else
#define SIMPLE_NN_EXPORTS __declspec(dllimport)
#endif
