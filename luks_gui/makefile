APP=luks_gui_mount
CFLAGS=-O3 -m64
#CFLAGS=-O0 -g3
all:$(APP)
$(APP): $(APP).c
	gcc -o$@ $(APP).c `pkg-config gtk+-2.0 --cflags --libs` -lbsd

clean:
	rm -f $(APP)

