#pragma once
#include <sqlite3.h>
#include <iostream>
#include "Client.h"
#include <vector>

using namespace std;
using namespace Model;

namespace Repositories {
	class ClientRepository
	{
	private:
		sqlite3* db;
	public:
		ClientRepository(sqlite3* dataBase);
		Client getClientById(int id);
		void saveCliend(Client* client);
		vector<Client> getAllClients();
		void deleteClient(int id);
		vector<Client> searchByFIO(char* fio);
	};
}
