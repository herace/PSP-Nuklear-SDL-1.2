#include <SDL/SDL.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_IMPLEMENTATION
#define NK_SDL_IMPLEMENTATION

#include "nuklear/nuklear.h"
#include "nuklear_sdl_12.h"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 272

int main(int argc, char **argv){
    static SDL_Surface *screen;
    
    struct nk_color background;
    
    int running = 1;
    
    struct nk_context *ctx;
    float bg[4];

    /* SDL setup */
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_SWSURFACE);
    
    ctx = nk_sdl_init(screen);
    
    background = nk_rgb(28, 48, 62);
    
    while (running){
        /* GUI */
        nk_begin(ctx, "PSP Nuklear Demo", nk_rect(108, 100, 180, 100), NK_WINDOW_BORDER|NK_WINDOW_TITLE);
			nk_layout_row_dynamic(ctx, 30,1);
				nk_button_label(ctx, "New Game");
			nk_layout_row_dynamic(ctx, 20, 2);
				nk_button_label(ctx, "Options");
				nk_button_label(ctx, "Credits");
        nk_end(ctx);

        /* Draw */
        nk_color_fv(bg, background);
        nk_sdl_render(nk_rgb(background.r, background.g, background.b));
    }

cleanup:
    nk_sdl_shutdown();
    SDL_Quit();
return 0;
}
