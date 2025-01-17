#include "library.h"
#include "ogm/interpreter/Variable.hpp"
#include "ogm/common/error.hpp"
#include "ogm/common/util.hpp"
#include "ogm/interpreter/Executor.hpp"
#include "ogm/interpreter/execute.hpp"
#include "ogm/interpreter/display/Display.hpp"

#include <string>
#include <cassert>
#include <locale>
#include <cctype>
#include <cstdlib>

using namespace ogm::interpreter;
using namespace ogm::interpreter::fn;

#define frame staticExecutor.m_frame
#define display frame.m_display

void ogm::interpreter::fn::io_clear(VO out)
{
    display->clear_keys();
}

void ogm::interpreter::fn::keyboard_check(VO out, V key)
{
    out = display->get_key_down(key.castCoerce<int>());
}

void ogm::interpreter::fn::keyboard_check_pressed(VO out, V key)
{
    out = display->get_key_pressed(key.castCoerce<int>());
}

void ogm::interpreter::fn::keyboard_check_released(VO out, V key)
{
    out = display->get_key_released(key.castCoerce<int>());
}