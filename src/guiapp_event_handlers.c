

#include "gui/guiapp_resources.h"
#include "gui/guiapp_specifications.h"

#include "main_thread.h"
extern GX_WINDOW_ROOT * p_window_root;

static UINT show_window(GX_WINDOW * p_new, GX_WIDGET * p_widget, bool detach_old);
//static void update_text_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, GX_CONST GX_CHAR *string_id);
static void update_numeric(GX_WIDGET * p_widget, GX_RESOURCE_ID id, int numeric);

int set_point=0;
char count_text;
//static bool button_enabled = false;


UINT window1_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type){
        case GX_EVENT_PEN_UP:
            show_window((GX_WINDOW*)&window3, (GX_WIDGET*)widget, true);
            break;
        default:
            result = gx_window_event_process(widget, event_ptr);
            break;
    }
    return result;



//    UINT result = gx_window_event_process(widget, event_ptr);
//
//    switch (event_ptr->gx_event_type)
//    {
////    case GX_SIGNAL(ID_BUTTONENABLER, GX_EVENT_TOGGLE_ON):
////        button_enabled = true;
////      //  update_text_id(widget->gx_widget_parent, ID_WINDOWCHANGER, "12345");
////    count2++;
////    count_text =(char) count2;
////        update_text_id(widget->gx_widget_parent, ID_INSTRUCTIONS,(char) count_text);
////        update_numeric(widget->gx_widget_parent, ID_INSTRUCTIONS2,  count2);
////        break;
////    case GX_SIGNAL(ID_BUTTONENABLER, GX_EVENT_TOGGLE_OFF):
////        button_enabled = false;
////      // update_text_id(widget->gx_widget_parent, ID_WINDOWCHANGER,  "HOla");
////        update_text_id(widget->gx_widget_parent, ID_INSTRUCTIONS,  "asdasd");
////        break;
//    case GX_SIGNAL(ID_WINDOWCHANGER, GX_EVENT_CLICKED):
//
//            show_window((GX_WINDOW*)&window2, (GX_WIDGET*)widget, true);
//    break;
//    default:
//        gx_window_event_process(widget, event_ptr);
//        break;
//    }
//
//    return result;
}

UINT window2_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type){
        case GX_SIGNAL(BTN_BACK, GX_EVENT_CLICKED):
            show_window((GX_WINDOW*)&window3, (GX_WIDGET*)widget, true);
            break;
        default:
            result = gx_window_event_process(widget, event_ptr);
            break;
    }
    return result;
}

UINT window3_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type){
        case GX_SIGNAL(BTN_STOP, GX_EVENT_CLICKED):
           // show_window((GX_WINDOW*)&window2, (GX_WIDGET*)widget, true);
            break;
        case GX_SIGNAL(BTN_INC, GX_EVENT_CLICKED):
        set_point=set_point+20;
        update_numeric(widget->gx_widget_parent, PR_SET_POINT,  set_point);
        break;
        case GX_SIGNAL(BTN_DEC, GX_EVENT_CLICKED):
                set_point=set_point-20;
        update_numeric(widget->gx_widget_parent, PR_SET_POINT,  set_point);
        break;
        case GX_SIGNAL(BTN_ABOUT, GX_EVENT_CLICKED):
        show_window((GX_WINDOW*)&window2, (GX_WIDGET*)widget, true);
        break;
        default:
            result = gx_window_event_process(widget, event_ptr);
            break;
    }
    return result;
}

static UINT show_window(GX_WINDOW * p_new, GX_WIDGET * p_widget, bool detach_old)
{
    UINT err = GX_SUCCESS;

    if (!p_new->gx_widget_parent)
    {
        err = gx_widget_attach(p_window_root, p_new);
    }
    else
    {
        err = gx_widget_show(p_new);
    }

    gx_system_focus_claim(p_new);

    GX_WIDGET * p_old = p_widget;
    if (p_old && detach_old)
    {
        if (p_old != (GX_WIDGET*)p_new)
        {
            gx_widget_detach(p_old);
        }
    }

    return err;
}

//static void update_text_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, GX_CONST GX_CHAR *string_id)
//{
//    GX_PROMPT * p_prompt = NULL;
//
//    ssp_err_t err = gx_widget_find(p_widget, (USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_prompt);
//    if (TX_SUCCESS == err)
//    {
//        gx_prompt_text_set(p_prompt, string_id);
//    }
//}

static void update_numeric(GX_WIDGET * p_widget, GX_RESOURCE_ID id, int numeric)
{
    GX_NUMERIC_PROMPT * p_prompt = NULL;

    ssp_err_t err = gx_widget_find(p_widget, (USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_prompt);
    if (TX_SUCCESS == err)
    {
        _gxe_numeric_prompt_value_set(p_prompt, numeric);
    }
}

//void update_text_numeric(int count3)
//{
//    update_numeric((GX_WINDOW*)&window1, ID_INSTRUCTIONS2,  count3);
//}

