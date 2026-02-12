#pragma once

#include <iostream>
#include "support/SupportExporter.h"

NS_pTS_BEGIN
BEGIN_CREATE_REF_CLASS(Engine, Singleton<Engine>)

GLB:
    void start();
    void quit();
    void clean();
    inline void stop() { _is_running = false; }
    inline const bool is_running() { return _is_running; }
PRV:
    bool _is_running = true;

END_CREATE_CLASS
NS_pTS_END


