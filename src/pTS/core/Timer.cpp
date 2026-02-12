#include "Timer.h"
#include "support/Macros.h"

NS_pTS_BEGIN

bool Timer::init() {
    return true;
}

void Timer::log() {
    std::cout << _dt << std::endl;

}

void Timer::tick() {
    //auto _tick = SDL_GetTicks();
    //_dt = ( _tick - _last ) / 1000.0f;
    //_last = _tick;
}

STR Timer::to_string() {
    return _class_name;
}

Timer::~Timer() {

}

Timer::Timer() {

}

NS_pTS_END
