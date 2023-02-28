/* This is an example of the GUIX graphics framework in Win32. */
/* Include system files. */

#include <stdio.h>
#include "tx_api.h"
#include "gx_api.h"

/* Include GUIX resource and specification files for example. */

#include "demo2_resources.h"
#include "demo2_specifications.h"

/* Define the new example thread control block and stack. */

TX_THREAD new_example_thread;
UCHAR new_example_thread_stack[3085];

/* Define the root window pointer. */

GX_WINDOW_ROOT* root_window;

/* Define function prototypes. */

VOID new_example_thread_entry(ULONG thread_input);
extern UINT win32_graphics_driver_setup_24xrgb(GX_DISPLAY* display);
//extern UINT win32_graphics_driver_setup_24bpp(GX_DISPLAY* display);
UINT onAlaramButtonClicked(GX_WINDOW* widget, GX_EVENT* event_ptr);
int main(int argc, char** argv)
{
    /* Enter the ThreadX kernel. */
    tx_kernel_enter();
    return(0);
}

VOID tx_application_define(void* first_unused_memory)
{
    /* Create the new example thread. */
    tx_thread_create(&new_example_thread, "GUIX New Example Thread",
        new_example_thread_entry, 0,
        new_example_thread_stack, sizeof(new_example_thread_stack),
        1, 1, TX_NO_TIME_SLICE, TX_AUTO_START);
}

VOID new_example_thread_entry(ULONG thread_input)
{
    /* Initialize the GUIX library */
    gx_system_initialize();

    /* Configure the main display. */
    gx_studio_display_configure(DISPLAY_1,                      /* Display to configure*/
        win32_graphics_driver_setup_24xrgb, /* Driver to use */
        LANGUAGE_ENGLISH,                  /* Language to install */
        DISPLAY_1_THEME_1,        /* Theme to install */
        &root_window);                     /* Root window pointer */

/* Create the screen - attached to root window. */

    gx_studio_named_widget_create("main_menu", (GX_WIDGET*)root_window, GX_NULL);
    gx_studio_named_widget_create("clock_screen", GX_NULL, GX_NULL);
    gx_studio_named_widget_create("screen_setting", GX_NULL, GX_NULL);
    gx_studio_named_widget_create("display_setting", GX_NULL, GX_NULL);
    gx_studio_named_widget_create("alarm_screen_new", GX_NULL, GX_NULL);
    gx_studio_named_widget_create("world_clock_screen", GX_NULL, GX_NULL);
    gx_studio_named_widget_create("timer_screen", GX_NULL, GX_NULL);
    gx_studio_named_widget_create("home_screen_setting", GX_NULL, GX_NULL);
    gx_studio_named_widget_create("lock_screen_setting", GX_NULL, GX_NULL);
    
    
    
    /* Show the root window to make it visible. */
    gx_widget_show(root_window);

    /* Let GUIX run. */
    gx_system_start();

}

UINT onAlaramButtonClicked(GX_WINDOW* widget, GX_EVENT* event_ptr) {
    switch (event_ptr->gx_event_type) {
    case GX_SIGNAL(1,GX_EVENT_CLICKED):
        // function to handle the event

        break;
    }
    return 0;
}