#pragma once

#include "FlexSimDefs.h"

#ifdef _WINDOWS
#define PY_CONNECTOR_EXPORT __declspec(dllexport)
#else
#define PY_CONNECTOR_EXPORT
#endif
