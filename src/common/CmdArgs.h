#ifndef TESTPROM_CMDARGS_H
#define TESTPROM_CMDARGS_H

#include "CmdArgs.h"
#include <string>

enum class Args {
    PORT,     /**<< Number of port */
    CONN_TYPE /**<< Type of connection TCP OR UDP */
};

enum class ConnType {
    TCP,
    UDP
};

class CmdArgs
{

public:

    static auto check() -> int;


    auto getValue() const -> std::string;


private:

};

#endif // TESTPROM_CMDARGS_H
