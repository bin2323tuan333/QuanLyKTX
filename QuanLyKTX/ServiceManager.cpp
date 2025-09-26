#include "ServiceManager.h"


LoginService* ServiceManager::loginService = nullptr;
AccountRepository* ServiceManager::accountRepo = nullptr;
bool ServiceManager::initialized = false;


void ServiceManager::initialize() 
{
    if (initialized) return;
    accountRepo = new AccountRepository();
    accountRepo->LoadDataFromFile();
    loginService = new LoginService(*accountRepo);
    initialized = true;
}

LoginService& ServiceManager::getLoginService() 
{
    return *loginService;
}

AccountRepository& ServiceManager::getAccountRepository() 
{
    return *accountRepo;
}

bool ServiceManager::isInitialized() 
{
    return initialized;
}

void ServiceManager::shutdown() 
{
    if (loginService) 
    {
        delete loginService;
        loginService = nullptr;
    }
    if (accountRepo) {
        delete accountRepo;
        accountRepo = nullptr;
    }
    initialized = false;
}