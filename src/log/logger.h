/*
 * Logging Module for Syrupixel
 *
 * version 1.0
 */
#pragma once

#include <string.h>

namespace SYRP_LOG {

class SyrpLogger {
public:
    SyrpLogger();

    SyrpLogger(const SyrpLogger&);

    SyrpLogger& operator=(const SyrpLogger&);

    virtual ~SyrpLogger();

    uint32_t InitLogger();

    uint32_t SyrpLog(std::string strMessage, std:string strLogLevel);

private:
    std::string m_SyrpLogLevel;
    std::string m_SyrpLogDir;
    std::string m_SyrpLogName
};

} // end of SYRP_LOG
