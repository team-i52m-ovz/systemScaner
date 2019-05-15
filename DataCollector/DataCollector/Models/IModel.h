#pragma once
#ifndef SYSTEMRAT_MODELS_IMODEL_H
#define SYSTEMRAT_MODELS_IMODEL_H

#include <string>

namespace SystemRat
{
	namespace Models
	{
		class IModel
		{
		public:
			virtual ~IModel() = default;
		};
	}
}

#endif