#pragma once
#include "LoginService.h"
#include "AccountRepository.h"

class ServiceManager {
private:
    static LoginService* loginService;
    static AccountRepository* accountRepo;
    static bool initialized;

public:
    static void initialize();
    static LoginService& getLoginService();
    static AccountRepository& getAccountRepository();
    static bool isInitialized();
    static void shutdown();
};