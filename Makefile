ERGODOX_EZ = qmk_firmware/keyboards/ergodox_ez
T4N14_DEST := $(ERGODOX_EZ)/keymaps/t4n14

.PHONY: all
all: t4n14

.PHONY: clean
clean:
	rm -rf $(T4N14_DEST)

.PHONY: t4n14
t4n14:
	cp -r t4n14 $(T4N14_DEST)
	cd qmk_firmware \
	&& $(MAKE) ergodox_ez:t4n14
	mv qmk_firmware/ergodox_ez_t4n14.hex t4n14.hex
