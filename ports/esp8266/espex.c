#include "py/nlr.h"
#include "py/obj.h"
#include "py/runtime.h"

#include "c_types.h"
#include "gpio.h"

STATIC mp_obj_t espex_gpio_pin_wakeup_enable(mp_obj_t py_pin, mp_obj_t py_level)
{
    mp_int_t pin = mp_obj_get_int(py_pin);
    mp_int_t level = mp_obj_get_int(py_level);
    if (level)
        gpio_pin_wakeup_enable(pin, GPIO_PIN_INTR_HILEVEL);
    else
        gpio_pin_wakeup_enable(pin, GPIO_PIN_INTR_LOLEVEL);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(espex_gpio_pin_wakeup_enable_obj, espex_gpio_pin_wakeup_enable);

STATIC const mp_map_elem_t espex_globals_table[] = {
    {MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_espex)},
};
STATIC MP_DEFINE_CONST_DICT(
    mp_module_espex_globals,
    espex_globals_table);
const mp_obj_module_t mp_module_espex = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&mp_module_espex_globals,
};
