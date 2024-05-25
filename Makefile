all: 
	@zip -q -9 -x Makefile -x .luarc.json -x .editorconfig -r game.love . && mv game.love ../../storage/downloads
