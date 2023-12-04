#include <string>
#include <iostream>
#include "phxpaxos/sm.h"

class PhxEchoServer
{
public:
    PhxEchoServer();
    ~PhxEchoServer();

    int Echo(const std::string & sEchoReqValue, std::string & sEchoRespValue);
};

class PhxEchoSM : public phxpaxos::StateMachine
{
public:
    PhxEchoSM();

    bool Execute(const int iGroupIdx, const uint64_t llInstanceID, 
            const std::string & sPaxosValue, phxpaxos::SMCtx * poSMCtx);

    const int SMID() const { return 1; }
};

int main() {
    PhxEchoSM p();
    return 0;
}