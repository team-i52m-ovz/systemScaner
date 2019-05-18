#pragma once
#ifndef SYSTEMRAT_DATAMANAGER_DATAMANAGER_H
#define SYSTEMRAT_DATAMANAGER_DATAMANAGER_H

#include <vector>
#include <memory>
#include <unordered_map>

namespace SystemRat
{
	namespace Models
	{
		class IModel;
	}

	namespace DataManager
	{
		class DataManager final
		{
		public:
			explicit DataManager() = default;
			~DataManager() = default;

			void init();
			void add(std::string name, std::shared_ptr<SystemRat::Models::IModel> val);
			std::vector<std::shared_ptr<SystemRat::Models::IModel>>* get(std::string key);
			bool contains(std::string key);

		private:
			std::unordered_map<std::string, std::vector<std::shared_ptr<SystemRat::Models::IModel>>> m_models;
		};
	}
}

#endif