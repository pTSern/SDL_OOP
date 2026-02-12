#pragma once

#include "Engine.h"

NS_pTS_BEGIN

bool Engine::init() {
    return true;
}

STR Engine::to_string() {
    return "Hello";
}

void Engine::log() {
    const STR msg = this->_class_name + this->to_string();
    std::cout << msg << std::endl;
}

void Engine::start() {
    while(_is_running) {

    }
    clean();
    quit();
}

void Engine::quit() {

}

void Engine::clean() {

}

Engine::~Engine() {

}

Engine::Engine() {

}

NS_pTS_END
