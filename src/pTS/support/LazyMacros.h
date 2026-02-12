#pragma once

//# Quick commenter marking zone

#define MARK_CONSTRUCTOR                                            /** @def Begin implement all construcot functions */

#define pTS_REF

#define pTS_ABS 

//# Lazy zone

#define OVR                                                         override
#define VIR                                                         virtual
#define CST                                                         const
#define STT                                                         static
#define INL                                                         inline

#define MEM                                                         protected
#define PRV                                                         private
#define GLB                                                         public

#define STR                                                         std::string

//# Quick implement zone

#define QUICK_VAR(_TYPE_, _FIRST_, ...)                             _TYPE_ _FIRST_, ##__VA_ARGS__;

#define QUICK_FLOAT(_VAR_, ...)                                     QUICK_VAR(float, _VAR_, ##__VA_ARGS__)
#define QUICK_STRING(_VAR, ...)                                     QUICK_VAR(STR, _VAR_, ##__VA_ARGS__)
#define QUICK_DOUBLE(_VAR_, ...)                                    QUICK_VAR(double, _VAR_, ##__VA_ARGS__)
#define QUICK_BOOL(_VAR_, ...)                                      QUICK_VAR(bool, _VAR_, ##__VA_ARGS__)
#define QUICK_CHP(_VAR_, ...)                                       QUICK_VAR(const char, _VAR_, ##__VA_ARGS__)

#define GETTER_CREATOR(_TYPE_, _NAME_, _VAR_)                       \
INL void _NAME_(_TYPE_ ret) { _VAR_ = ret; }                        \

#define SETTER_CREATOR(_TYPE_, _NAME_, _VAR_)                       \
INL _TYPE_ _NAME_() { return _VAR_ }                                \

#define GET_SET_CREATOR(_TYPE_, _NAME_, _VAR_)                      \
GETTER_CREATOR(_TYPE_, get_##_NAME_, _VAR_)                         \
SETTER_CREATOR(_TYPE_, set_##_NAME_, _VAR_)                         \

#define GET_SET_VAR_CREATOR(_TYPE_, _NAME_)                         \
MEM:                                                                \
  _TYPE_ _NAME_;                                                    \
GLB:                                                                \
  GET_SET_CREATOR(_TYPE_, _NAME_, _NAME_)                           \

#define END_CREATE_CLASS                                            };

#define BEGIN_CREATE_REF_CLASS(_CLASS_NAME_, _REF_CLASS_, ...)      \
class pTS_REF _CLASS_NAME_ : GLB _REF_CLASS_, ##__VA_ARGS__         \
{                                                                   \
GLB:                                                                \
  VIR bool init();                                                  \
  VIR STR to_string();                                              \
  VIR void log();                                                   \
  VIR ~_CLASS_NAME_();                                              \
  _CLASS_NAME_();                                                   \
PRV:                                                                \
  const STR _class_name = #_CLASS_NAME_;                            \


#define pTS_LOG(_MSG_, ...)                                         \
std::cout << _MSG_ << #__VA_ARGS__ << std::endl;                    \
