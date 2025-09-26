#pragma once
#include "LoginService.h"
#include "AccountRepository.h"
#include <memory>
#include <stdexcept>

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