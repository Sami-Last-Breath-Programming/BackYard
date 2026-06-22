GUI/output/ui: GUI/ui.c
	gcc -c GUI/ui.c -o GUI/output/obj/ui.o -I .vscode/libs/Linux54_64/include/
	gcc GUI/output/obj/ui.o -o GUI/output/ui -liupimglib -liup -L .vscode/libs/Linux54_64/

run: GUI/output/ui 
	export LD_LIBRARY_PATH=.vscode/libs/Linux54_64/ && GUI/output/ui