#include "key.h"
#include "bsp_gpio.h"
#include "debug.h"


static u8 get_key_id(void)
{
    u8 key_state = 0;
    if(KEY0_R() == 0)
    {
        key_state |= 1;
    }
    if(KEY1_R() == 0)
    {
        key_state |= 2;
    }
    if(KEY2_R() == 0)
    {
        key_state |= 4;
    }
    if(key_state == 0)
    {
        return	__NO_KEY;

    }
    return key_state;

}




static key_status_t key_state_t_g;

void key_detect_loop(void)
{
    u8 key_id = 0;
    u8 key_state  = 0;
    key_state_detect(&key_state_t_g);
    key_id = key_state_t_g.msg_keynum;
    key_state = key_state_t_g.msg_state;
    key_state_t_g.msg_keynum = __NO_KEY;
    key_state_t_g.msg_state = KEY_NULL;
    if(key_id != __NO_KEY)
    {
        switch(key_state)
        {
        case KEY_NULL:
            LOG_D("KEY: %d  NULL\n", key_id);

            break;
        case KEY_SHORT:
            LOG_D("KEY: %d  SHORT\n", key_id);
            break;
        case KEY_LONG:
            LOG_D("KEY: %d  LONG\n", key_id);
            break;
        case KEY_DOUBLE:
            LOG_D("KEY: %d  DOUBLE\n", key_id);
            break;
        case KEY_REPEAT:
            LOG_D("KEY: %d  REPEAT\n", key_id);
            break;
        case KEY_REPEAT_UP:
            LOG_D("KEY: %d  REPEAT_UP\n", key_id);
            break;
        }
    }

}



__IRQ_HdlTypedef(key_detect_loop, 1);




void init_key_detect(void)
{
    key_state_t_g.c_val = __NO_KEY;
    key_state_t_g.b_val = __NO_KEY;
    key_state_t_g.msg_keynum = __NO_KEY;
    key_state_t_g.count = 0;
    key_state_t_g.double_key_cnt = 0;
    key_state_t_g.msg_state = KEY_NULL;
    key_state_t_g.key_state = KEY_NULL;
    key_state_t_g.get_key_val_fun = get_key_id;
    register_timer_handler(T_IRQ_Hdl(key_detect_loop));
}

