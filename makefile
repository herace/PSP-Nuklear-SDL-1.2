TARGET = NUKLEAR
#PSP_EBOOT_ICON = ICON0.png
#PSP_EBOOT_PIC1 = BG0.png
OBJS = main.o 

PSPSDK = $(shell psp-config --pspsdk-path)
PSPBIN = $(shell psp-config --psp-prefix)/bin
SDL_CONFIG = $(PSPBIN)/sdl-config

DEFAULT_CFLAGS = $(shell $(SDL_CONFIG) --cflags)
MORE_CFLAGS = -G0 -O2
CFLAGS = $(DEFAULT_CFLAGS) $(MORE_CFLAGS)
CXXFLAGS = $(DEFAULT_CFLAGS) $(MORE_CFLAGS) -fno-exceptions -fno-rtti

LIBS = -lSDL_image -lSDL_gfx -lSDL_mixer -lSDL_ttf -lfreetype -lz -lpng -ljpeg\
	$(shell $(SDL_CONFIG) --libs)
EXTRA_TARGETS = EBOOT.PBP

include $(PSPSDK)/lib/build.mak
