
#include <iostream>
#include "support/SupportExporter.h"

NS_pTS_BEGIN
BEGIN_CREATE_REF_CLASS(Timer, Singleton<Timer>)

GLB:
    void tick();
PRV:
    float _dt;
    float _last;

END_CREATE_CLASS
NS_pTS_END


